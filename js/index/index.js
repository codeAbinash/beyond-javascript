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


// window.addEventListener("popstate", () => {
//     window.history.replaceState("object or string", "", "");
//     loadFromLink()
//     console.dir(window.history.back())
//     window.location.assign(window.location.href)
//     window.history.
// })

//Load the Last Page
// if (localStorage.lastPage)
//     load(localStorage.lastPage)
// else
//     load("home")




lib()








//Set service Worker

const registerServiceWorker = async () => {
    if ('serviceWorker' in navigator) {
        try {
            const registration = await navigator.serviceWorker.register(
                '../sw.js'
                // {
                //     scope: '/sw-test/',
                // }
            );
            // if (registration.installing) {
            //     console.log('Service worker installing');
            // } else if (registration.waiting) {
            //     console.log('Service worker installed');
            // } else if (registration.active) {
            //     console.log('Service worker active');
            // }
        } catch (error) {
            // console.error(`Registration failed with ${error}`);
        }
    }
};
registerServiceWorker();