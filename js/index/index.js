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


// Search on Keypress
document.onkeydown = (e) => {
    let charCode = e.which
    let tagNameFocusedElem = document.activeElement.tagName
    if ( (charCode >= 65 && charCode <=90 ) || (charCode>=97 && charCode<=112)){        
        if(tagNameFocusedElem != 'INPUT'){
            searchBar.focus();
        }
    }
}


//Set service Worker

if ('serviceWorker' in navigator) {
    let registration

    const registerServiceWorker = async () => {
        registration = await navigator.serviceWorker.register('./js/service-worker.js')
    }

    registerServiceWorker()
}