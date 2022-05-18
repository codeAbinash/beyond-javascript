export default class History {
    static store(storeLink) {
        // let scrollAmount = window.pageYOffset || (document.documentElement || document.body.parentNode || document.body).scrollTop;

        let data = []
        // let scrollData = []
        if (sessionStorage.History){
            data = JSON.parse(sessionStorage.History)
            // scrollData = JSON.parse(sessionStorage.ScrollData)
        }

        if (data[data.length - 1] == storeLink)
            return

        data.push(storeLink)
        sessionStorage.History = JSON.stringify(data)
        // scrollData = []
        // scrollData.push(scrollAmount)


        // sessionStorage.ScrollData = JSON.stringify(scrollData)
        localStorage.lastPage = storeLink
        console.log();

    }

    static back() {
        let data = []
        let scrollData = []

        if (sessionStorage.History){
            data = JSON.parse(sessionStorage.History)
            // scrollData = JSON.parse(sessionStorage.ScrollData)
        }
        if (data.length == 0 || data.length == 1)
            window.history.back()

        
        data.pop()
        let linkNav = data.pop()


        // let scrollAmount = scrollData.pop()
        // scrollData.pop()
        // scrollData.pop()

        sessionStorage.ScrollData = JSON.stringify(scrollData)
        sessionStorage.History = JSON.stringify(data)
        return [linkNav/*, scrollAmount*/]
    }
}