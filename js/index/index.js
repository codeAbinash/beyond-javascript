import { menuOperation } from "./header.js"
import lib from "../lib.js"
import load from "./load.js"
import darkMode from '../darkMode.js'

// import whatsNew from './whatsNew.js'


let searchIcon = document.getElementById("searchIcon")
let searchBar = document.getElementById("search")
let dataOpen = document.querySelectorAll("[data-open]")
let emailPageError = document.querySelectorAll(".emailPageError")
let dataOpens = document.querySelectorAll("[data-opens]")



// window.onload = function () {
//     document.body.style.opacity = '1'
// }


//Event listener of options
dataOpen.forEach((elem) => {

    //Set ID to all

    elem.id = elem.getAttribute('data-open')
    elem.addEventListener("click", () => {

        setTimeout(() => {
            load(elem.getAttribute('data-open'))
        }, 200)

    })
})

//Data opens
dataOpens.forEach((elem) => {
    elem.addEventListener("click", () => {
        load(elem.getAttribute('data-opens'))
    })
})


searchIcon.addEventListener("click", openSearch)
function openSearch() {
    menuOperation()
    searchBar.focus()
}


//emailPageError
emailPageError.forEach((elem) => {
    elem.setAttribute("href", "mailto:codeAbinash@gmail.com?subject=Something is wrong in Beyond Javascript page&body=The link of the page is " + window.location.hash + ". The wrong thing is ")
})



lib()


darkMode()

// whatsNew()


// Search on Shift + F
let keys = {}
function keyPress(e) {
    let { key, type } = e
    let isKeyDown = (type == 'keydown')
    keys[key] = isKeyDown;
    if (isKeyDown && keys.Shift && (keys.f || keys.F)) {
        let tagNameFocusedElem = document.activeElement.tagName
        if (tagNameFocusedElem != 'INPUT') {
            e.preventDefault()
            searchBar.focus();
        }
    }
    if (isKeyDown == false)
        keys = {}
}
document.onkeyup = (e) => { keyPress(e) }
document.onkeydown = (e) => { keyPress(e) }



//Set service Worker

// if ('serviceWorker' in navigator) {
//     let registration

//     const registerServiceWorker = async () => {
//         registration = await navigator.serviceWorker.register('./serviceWorker.js')
//     }

//     registerServiceWorker()
// }

async function registerSW() {
    if ('serviceWorker' in navigator) {
        try {
            const registration = navigator.serviceWorker.register('./serviceWorker.js')
        }
        catch (error) {
            console.log('Error Registering SW' + error.message)
        }
    }
    else
        console.log("Service Worker is not available for this device")
}

registerSW()