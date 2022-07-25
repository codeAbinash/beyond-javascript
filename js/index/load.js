import History from "../history.js"
import handelMenu from "./header.js"
import highligh from "../prism.js"

let loader = document.querySelector("#loader div")
let main = document.getElementById("main")


export default function load(src = "index/Javascript Home", scrollAmount = 0) {
    let link = src
    const hashIndex = link.indexOf('#')
    const hash = hashIndex == -1 ? '' : link.substring(hashIndex + 1)
    src = hashIndex == -1 ? link : link.substring(0, hashIndex)

    let fetchLink = `./pages/${src}.html`

    resetLoadTransition()
    activeSideBarElements(src)
    //Edit on Github Links
    githubLinks(src)

    History.store(src)
    changeWindowLocation(src, hash)

    fetch(fetchLink)
        .then((text) => {
            let err = false
            if (!text.ok)
                err = true
            return [text.text(), err]
        })
        .then(([text, err]) => {
            if (err) {
                main.innerHTML =
                    `<h1> <span class="gT">404</span> : Page Not found</h1>
                    <div class="btnDiv">
                        <button class="noTxt hist"><pre>&lt;&lt;   Go Back</pre></button>
                    </div>
                    <img src="./images/illustration/sad boy.png" alt="Sad Boy"
                    style="width: min(50%, 350px);margin: 50px auto 20px auto;display:block;">
                    <p class="center">The page you are trying to reach is not available right now.
                    Maybe it was deleted or it is not written yet.</p>`

                clickOpenPage()
                setHistoryBack()
                loadImages()
                loaderTransition()
                setTimeout(() => {
                    window.scrollTo(0, 0)
                }, 0)
                return
            }
            text.then((txt) => {
                main.innerHTML = txt
                loadCodes(scrollAmount)
                clickOpenPage()
                setHistoryBack()
                loadImages()
                loadPageLink()
                loadMemeLink()
                displayMeme()
            })
        })

}



let editOnGithub = document.getElementById('editOnGithub')
let sourceOnGithub = document.getElementById('sourceOnGithub')

function githubLinks(src) {
    editOnGithub.href = 'https://github.com/codeAbinash/web/edit/main/pages/' + src + '.html'
    sourceOnGithub.href = 'https://github.com/codeAbinash/web/blob/main/pages/' + src + '.html?plain=1'
}

function loadMemeLink() {
    const links = document.querySelectorAll('[data-meme]')
    links.forEach(link => {
        let memeLink = link.getAttribute('data-meme')
        link.href = window.location.pathname + `?file=meme/view`
        link.addEventListener('click', (e) => {
            localStorage.lastMeme = memeLink
            e.preventDefault()
            load('meme/view')
        })
    })
}

async function displayMeme() {
    let memeContainer = document.getElementById("memeContainer")
    let emojiContainer = document.getElementById("emojiContainer")
    let meme = document.getElementById("displayMeme")
    let memeDOMHeading = document.getElementById("memeHeading")
    let memeDOMText = document.getElementById("memeText")

    if (!meme)
        return
    let memeHeading, memeText, memeSrc, noFun
    try {
        const lastMeme = localStorage.lastMeme || 'default'
        const memeData = await fetch('./meme/data/' + lastMeme + ".json")
        const memeJson = await memeData.json()
        memeHeading = memeJson.heading || "Meme Viewer"
        memeText = memeJson.text || "Have Fun With Memes"
        memeSrc = memeJson.src || false
        noFun = memeJson.noFun
    } catch {
        memeHeading = "Meme Loading Failed"
        memeText = "Meme cannot be loaded. Maybe there is some error occurred. Check your internet connection or maybe the location of the meme json file is changed"
        memeSrc = false
        noFun = true
    }

    if (memeSrc) {
        meme.src = './meme/meme/' + memeSrc
        meme.setAttribute('alt', memeHeading)
        memeDOMHeading.innerHTML = memeHeading
        memeDOMText.innerHTML = memeText
        const emojiNumbers = Math.min(Math.round(window.innerWidth / 25), 25)
        memeContainer.onclick = () => {
            emojiContainer.classList.toggle('hidden')
        }
        for (let i = 0; i < emojiNumbers; i++)
            emojiContainer.appendChild(createEmojiDOM())
        if (noFun)
            emojiContainer.classList.add('hidden')
    }
}

function createEmojiDOM() {
    const emoji = document.createElement('img')
    emoji.src = './icons/haha.svg'
    emoji.classList.add('emoji')
    emoji.style.height = 40 * Math.random() + 20 + "px"
    emoji.style.left = 100 * Math.random() + "%"
    emoji.style.animationDuration = 3 + Math.random() * 5 + "s"
    emoji.style.animationDelay = 1 * Math.random() * 3 + "s"
    return emoji
}


function loadPageLink() {
    let elements = document.querySelectorAll('[data-link]')
    elements.forEach(elem => {
        let link = elem.getAttribute('data-link')
        elem.href = window.location.pathname + `?file=${link}`
        elem.addEventListener("click", (e) => {
            if(elem.getAttribute('target') == '_blank')
                return
            e.preventDefault()
            load(link)
        })
    })
}


function loadImages() {
    let imagesDiv = document.querySelectorAll("[data-image]")
    imagesDiv.forEach((imageDiv) => {
        let img = document.createElement("img")
        img.setAttribute("loading", "lazy")
        img.setAttribute("alt", imageDiv.getAttribute("data-image-alt"))
        img.classList.add("press100")
        img.src = `./images/${imageDiv.getAttribute("data-image")}`
        imageDiv.appendChild(img)
    })
}


function changeWindowLocation(src, hash = '') {
    let url = window.location
    let newUrl = new URL(url)
    if (hash)
        newUrl.hash = hash
    newUrl.search = `?file=${src}`
    let title = src.substring(src.lastIndexOf("/") + 1)
    window.history.pushState("object or string", src, newUrl)
    document.title = title
}



handelMenu()

export function activeSideBarElements(src = "index/Javascript Home") {
    let lastPage = sessionStorage.lastPage
    let lastActiveElement = document.querySelector(`[data-open="${lastPage}"]`)
    let activeElement = document.querySelector(`[data-open="${src}"]`)

    let timeOut = 0
    setTimeout(() => {
        if (activeElement)
            activeElement.scrollIntoView({ block: 'center', behavior: 'smooth' })
    }, timeOut)

    if (lastActiveElement)
        lastActiveElement.classList.remove("activeOption")
    if (activeElement)
        activeElement.classList.add("activeOption")
}


function setHistoryBack() {
    let elements = document.querySelectorAll(".hist")
    elements.forEach((elem) => {
        elem.addEventListener("click", () => {
            let backData = History.back()

            load(backData[0], backData[1])

        })
    })
}

function loaderTransition() {
    loader.style.transitionDuration = "300ms"
    loader.style.width = "100%"
    setTimeout(() => {
        loader.style.transitionDuration = "0s"
        loader.style.width = "0"
    }, 400)
}

function resetLoadTransition() {
    loader.style.transitionDuration = "2s"
    loader.style.width = "80%"
}


function clickOpenPage() {
    let dataPage = main.querySelectorAll("[data-page]")
    dataPage.forEach((elem) => {
        elem.addEventListener("click", function () {
            load(elem.getAttribute('data-page'))
        }, { once: true })
    })
}


function loadCodes(scrollAmount) {

    let loadPromises = []
    let codesElements = document.querySelectorAll("[data-code]")
    codesElements.forEach((codeElem) => {
        let pre = document.createElement("pre")
        let code = document.createElement("code")

        if (codeElem.classList.contains("css")) {
            code.classList.add("language-css")
            fetchData(`./learning/css/${codeElem.getAttribute("data-code")}`)
        }
        if (codeElem.classList.contains("js")) {
            code.classList.add("language-js")
            fetchData(`./learning/js/${codeElem.getAttribute("data-code")}`)
        }
        if (codeElem.classList.contains("html")) {
            code.classList.add("language-html")
            fetchData(`./learning/html/${codeElem.getAttribute("data-code")}`)
        }
        if (codeElem.classList.contains("c")) {
            code.classList.add("language-clike")
            fetchData(`./learning/c/${codeElem.getAttribute("data-code")}`)
        }

        function fetchData(src) {
            let promise = fetch(src)
                .then(text => text.text())
                .then((text) => {
                    code.textContent = text
                    pre.appendChild(code)
                    codeElem.appendChild(pre)
                    return text
                })
            loadPromises.push(promise)
        }
    })

    // if (!scrollAmount) window.scrollTo({ top: 0, left: 0, behavior: 'smooth' })
    Promise.allSettled(loadPromises).then(() => {
        //set dom elem if hash is available
        let domElem
        let hash = window.location.hash
        if (hash) {
            domElem = document.querySelector(hash)
            window.location.hash = hash
        }
        highligh()
        loaderTransition()
        if (hash && domElem) {
            setTimeout(() => {
                domElem?.scrollIntoView({ behavior: "smooth", block: "start", inline: "nearest" });
            }, 10)
            return
        }
        window.location.hash = ''
        window.scrollTo({
            top: scrollAmount,
            left: 0,
            behavior: "smooth"
        })
    })
}