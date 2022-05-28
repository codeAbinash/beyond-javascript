import load from "./load.js";

export default async function loadSidebarElements() {
    let sidebarElemDiv = document.getElementById('sidebarElemDiv')
    let fetchData = await fetch('./data/sidebar.json')
    let jsonData = await fetchData.json()

    jsonData.forEach(elem => {
        let a = document.createElement('a')
        a.setAttribute('data-open', elem.link)
        a.textContent = elem.name
        a.id = elem.link
        a.href = window.location.pathname + `?file=${elem.link}#${elem.link}`
        a.addEventListener('click', (e) => {
            e.preventDefault()
            load(elem.link)
        })
        sidebarElemDiv.appendChild(a)
    });
}