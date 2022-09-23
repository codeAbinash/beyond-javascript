// const staticCacheName =
const cacheData = {
    static: {
        name: 'static-beyond-javascript',
        urls: [
            './js/prism.js',
            // Font Cache
            'https://fonts.googleapis.com/css2?family=Poppins:wght@400;500;600;700;800&display=swap',
            'https://fonts.gstatic.com/s/poppins/v20/pxiByp8kv8JHgFVrLCz7Z1xlFd2JQEk.woff2',
            'https://fonts.gstatic.com/s/poppins/v20/pxiByp8kv8JHgFVrLDD4Z1xlFd2JQEk.woff2',
            'https://fonts.gstatic.com/s/poppins/v20/pxiByp8kv8JHgFVrLEj6Z1xlFd2JQEk.woff2',
            'https://fonts.gstatic.com/s/poppins/v20/pxiByp8kv8JHgFVrLGT9Z1xlFd2JQEk.woff2',
            'https://fonts.gstatic.com/s/poppins/v20/pxiEyp8kv8JHgFVrJJfecnFHGPc.woff2',
        ]
    },
    dynamic: {
        name: 'dynamic-beyond-javascript'
    }
}


self.addEventListener('install', event => {
    event.waitUntil(
        caches.open(cacheData.static.name).then(cache => {
            cache.addAll(cacheData.static.urls)
        })
    )
})


self.addEventListener('fetch', event => {
    if (cacheData.static.urls.includes(event.request.url))
        event.respondWith(
            caches.match(event.request).then(cacheResponse => {
                return cacheResponse || fetch(event.request)
            })
        )

    else
        event.respondWith(
            caches.match(event.request).then(cacheResponse => {
                const fetchUrl = fetch(event.request).then(fetchResponse => {
                    return caches.open(cacheData.dynamic.name).then(cache => {
                        cache.put(event.request, fetchResponse.clone())
                        return fetchResponse
                    })
                })
                return cacheResponse || fetchUrl
            })
        )
})