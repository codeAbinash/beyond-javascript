import highlighter from "../prism.js"


let dataFetch = document.querySelectorAll('[fetch]')
// console.log(dataFetch[0].attributes.getNamedItem('fetch-css').value);

// console.dir(dataFetch[0].getAttribute("fetch-css"));


let allPromises = [];


for (let i = 0; i < dataFetch.length; i++) {
    let fetchContainer = dataFetch[i]




    if (fetchContainer.classList.contains("language-css")) {
        let x = fetch(`./learning/css/${dataFetch[i].getAttribute("fetch")}`)
        x = x.then(data => data.text()).then(text => {
            fetchContainer.innerHTML = text
        })
        allPromises.push(x)
    }
    if (fetchContainer.classList.contains("language-js")) {
        let x = fetch(`./learning/js/${dataFetch[i].getAttribute("fetch")}`)
        x = x.then(data => data.text()).then(text => {
            fetchContainer.innerHTML = text
        })
        allPromises.push(x)
    }


}

console.log(allPromises);

Promise.allSettled(allPromises).then(() => {
    highlighter()
})
//   then((results) => results.forEach((result) => console.log(result.status)));



let body = document.querySelector(".body")
let main = document.getElementById("main")
let loader = document.querySelector("#loader div")
