function alertWin(message, callback = () => { }) {

    button.addEventListener('click', callback)

}

export default class AlertWin {
    #win
    constructor(message, callback = () => { }) {
        this.message = message
        this.callback = callback
    }

    show() {
        this.#win = document.getElementById('alertWindow')
        const heading = this.#win.querySelector('.heading')
        const text = this.#win.querySelector('.text')
        const button = this.#win.querySelector('.btnsDiv button')


        this.#win.style.display = "grid"
        document.body.style.overflow = "hidden"

        setTimeout(() => { this.#win.style.opacity = 1 }, 200)

        heading.innerHTML = this.message.heading || "Heading"
        text.innerHTML = this.message.text || "Welcome to Beyond JavaScript"
        button.innerHTML = this.message.btnTxt || "OK"

        button.addEventListener('click', () => {
            this.callback()
            this.hide()
        })
    }

    hide() {
        this.#win.style.opacity = 0
        setTimeout(() => {
            this.#win.style.display = "none"
            document.body.style.overflow = "auto"
        }, 200)
    }

}