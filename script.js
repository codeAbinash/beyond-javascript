let time = 4000

setTimeout(() => {window.location.replace('https://codeabinash.github.io/web/beyond_js.html')}, time);

let countSecond = ( time / 1000 ) - 1
let countDom = document.querySelector('.sec')


let timeOut = setInterval(() => {
    redirect();
    if (countSecond < 0) {
        clearInterval(timeOut)
    }
}, 1000)

function redirect(){
    countDom.textContent = countSecond
    countSecond--
}