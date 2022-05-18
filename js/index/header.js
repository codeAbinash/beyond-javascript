let menuIcon = document.getElementById("menuIcon")
let sideBar = document.getElementById("sideBar")
let sideBarCancel = document.getElementById("sidebarCancel")
let searchBar = document.getElementById("search")
let sideBarClickHide = document.querySelectorAll(".body .sideBar .list")


let menuOpen = true;
export function menuOperation() {
    if (window.innerWidth >= 900)
        return
    setTimeout(() => {

        if (menuOpen) {
            sideBar.style.left = "calc(-80%)"
            sideBarCancel.style.left = "100%"
        } else {
            sideBar.style.left = 0
            sideBarCancel.style.left = "0"

        }
    }, 50);
    menuOpen = !menuOpen
}

export default function handelMenu() {



    menuIcon.addEventListener("click", menuOperation)
    sideBarCancel.addEventListener("click", menuOperation) 
    // sideBarCancel.addEventListener("mouseover", menuOperation) 
    // sideBarCancel.addEventListener("touchstart", menuOperation)
    // sideBarCancel.addEventListener("touchmove", menuOperation)

    sideBarClickHide.forEach((listElement) => {
        listElement.addEventListener("click", function(){
            menuOperation()
            clearSearch()
        })
    })





    // sideBar.onclick = menuOperation




    searchBar.addEventListener("input", () => { filterSearch(searchBar.value) });



    

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



    function filterSearch(searchTxt = "") {
        let sideBarElements = document.querySelectorAll(".body .sideBar .list span")

        searchTxt = searchTxt.toLowerCase()

        sideBarElements.forEach((elem) => {
            let elemTxt = elem.innerText.toLowerCase();


            if (elemTxt.includes(searchTxt)) {

                elem.style.display = "inline-block"
            } else {
                elem.style.display = "none"

            }

        })


    }



    function clearSearch(){
        searchBar.value = ""
        filterSearch("");
    }
}


