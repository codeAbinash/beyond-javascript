import { menuOperation } from "./header.js"
import lib from "../lib.js"
import load from "./load.js"



let searchIcon = document.getElementById("searchIcon")
let searchBar = document.getElementById("search")
let dataOpen = document.querySelectorAll("[data-open]")
let emailPageError = document.querySelectorAll(".emailPageError")
let dataOpens = document.querySelectorAll("[data-opens]")
// header()






//Event listener of options
dataOpen.forEach((elem) => {

    //Set ID to all

    elem.id = elem.getAttribute('data-open')
    elem.addEventListener("click", () => {

        setTimeout(() => {
            load(elem.getAttribute('data-open'))
        }, 200);

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



//Link Control
function loadFromLink() {
    let url = window.location
    let search = new URL(url).searchParams.get('file')
    if (!search) {
        load()
        return
    }
    load(search)
}

loadFromLink()
lib()








//Set service Worker

if ('serviceWorker' in navigator) {
    let registration;

    const registerServiceWorker = async () => {
        registration = await navigator.serviceWorker.register('./service-worker.js');
    };

    registerServiceWorker();
}else{
    console.log("Sw ");
}