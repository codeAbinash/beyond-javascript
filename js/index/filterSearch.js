// Use a global variable to store DOM data,
// Not to load every time searching
let sideBarElements, allSearchText, length;

export default async function filterSearch(searchTxt = "") {
    if (sideBarElements === undefined) {
        sideBarElements = [...document.querySelectorAll(".body .sideBar .list a")]
        allSearchText = sideBarElements.map(elem => elem.textContent.toLowerCase())
        length = allSearchText.length
    }

    if (searchTxt == "") {
        sideBarElements.forEach(elem => {
            elem.style.display = "inline-block"
        })
        return
    }
    if (searchTxt.length > 0) {
        let i;
        searchTxt = searchTxt.toLowerCase()

        for(i = 0; i < length; i++){
            if(allSearchText[i].includes(searchTxt))
                sideBarElements[i].style.display = "inline-block"
            else
                sideBarElements[i].style.display = "none"
        }
    }
}