import load, { activeSideBarElements } from "./load.js";

export default async function loadSidebarElements(loadElements = []) {
    loadElements.forEach(loadElem => {
        new SideBarLoader(loadElem.file, loadElem.selector).load()
    })
}


class SideBarLoader {
    constructor(fileName, selector) {
        this.fileName = fileName
        this.selector = selector
    }
    async load() {
        let domElem = document.querySelector(this.selector)
        let fileLocation = './data/' + this.fileName

        let jsonData
        try{
            let fetchData = await fetch(fileLocation)    
            jsonData = await fetchData.json()
        }catch{
            console.error('Cannot Parse JSON')
            jsonData = []
        }

        jsonData.forEach(elem => {
            let a = document.createElement('a')
            a.setAttribute('data-open', elem.link)
            a.textContent = elem.name
            a.id = elem.link
            a.href = window.location.pathname + `?file=${elem.link}` //#${elem.link} // removed hash
            a.addEventListener('click', (e) => {
                e.preventDefault()
                load(elem.link)
            })
            domElem.appendChild(a)
        })
        activeSideBarElements(sessionStorage.lastPage)
    }
}