// Use a global variable to store DOM data,
// Not to load every time searching
let sidebarElements;


export default async function filterSearch(searchTxt = "") {
    let sideBarElements = document.querySelectorAll(".body .sideBar .list a")
    if (searchTxt == "") {
        sideBarElements.forEach(elem => {
            elem.style.display = "inline-block"
        })
        return
    }
    if (searchTxt.length > 0) {
        searchTxt = searchTxt.toLowerCase()
        sideBarElements.forEach((elem) => {
            let elemTxt = elem.innerText.toLowerCase();
            if (elemTxt.includes(searchTxt))
                elem.style.display = "inline-block"
            else
                elem.style.display = "none"
        })
    }
}