import debounce from "../debounce.js"

let menuIcon = document.getElementById("menuIcon")
let sideBar = document.getElementById("sideBar")
let sideBarCancel = document.getElementById("sidebarCancel")
let searchBar = document.getElementById("search")
let sideBarClickHide = document.querySelectorAll(".body .sideBar .list")
let mainLogo = document.getElementById('logo')

mainLogo.addEventListener('click', () => { scrollToTop() })




let menuOpen = true;
export function menuOperation() {
    if (window.innerWidth >= 900)
        return

    const animDuration = getAnimDuration()
    setTimeout(() => {

        if (menuOpen) {
            sideBar.style.left = "calc(-80%)"
            sideBarCancel.style.backgroundColor = "#00000000"
            setTimeout(() => {
                sideBarCancel.style.display = "none"
            }, animDuration);
        } else {
            sideBar.style.left = 0
            sideBarCancel.style.display = "block"
            setTimeout(() => {
                sideBarCancel.style.backgroundColor = "#00000033"
            }, 10);
        }
    }, 50);
    menuOpen = !menuOpen


    function getAnimDuration() {
        const style = getComputedStyle(document.body)
        const cssVar = style.getPropertyValue('--anim-duration')
        const animDuration = parseFloat(cssVar) * 1000
        return animDuration
    }
}

export default function handelMenu() {
    menuIcon.addEventListener("click", menuOperation)
    sideBarCancel.addEventListener("click", menuOperation)

    sideBarClickHide.forEach((listElement) => {
        listElement.addEventListener("click", function () {
            menuOperation()
            clearSearch()
        })
    })


    searchBar.addEventListener("input", debounce(() => { filterSearch(searchBar.value) }, 300, false))


    let moreOptions = document.getElementById("moreOptions")
    let moreOptionsDiv = document.getElementById("moreOptionsDiv")
    moreOptions.onclick = function () {
        moreOptionsDiv.style.left = 0
    }

    moreOptionsDiv.onclick = closeMoreOptions;
    function closeMoreOptions() {
        setTimeout(() => {
            moreOptionsDiv.style.left = "100%"
        }, 50);
    }



    async function filterSearch(searchTxt = "") {
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


    function clearSearch() {
        searchBar.value = ""
        filterSearch("");
    }
}


function scrollToTop() {
    window.scrollTo({
        top: 0,
        left: 0,
        behavior: 'smooth'
    })
}