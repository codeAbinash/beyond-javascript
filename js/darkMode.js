let darkThemeButton = document.querySelectorAll(".darkThemeButton")
var supportCss = checkBackdropFilterSupport()
let darkModeStatus = Number.parseInt(localStorage.darkMode || 0)

function checkBackdropFilterSupport(){
    return (CSS.supports('backdrop-filter','blur(10px)'))
}

export default function () {
    applyTheme(darkModeStatus)

    const mode = new Switcher(darkModeStatus)

    darkThemeButton.forEach(button => {
        button.onclick = (e) => {
            e.stopPropagation()
            mode.change()
            applyTheme(mode.status)
        }
    })
}

function applyTheme(darkModeStatus) {
    let modeString = "Theme : Auto"
    if (darkModeStatus == 1) {
        modeString = "Theme : Dark"
        applyDarkMode()
    }
    else if (darkModeStatus == 2) {
        modeString = "Theme : Light"
        applyLightMode()
    }
    else
        applyAutoMode()

    darkThemeButton.forEach((btn) => {
        btn.textContent = modeString
    })
}
function applyAutoMode() {
    if (window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches) {
        applyDarkMode()
    }
}
function applyDarkMode() {
    const darkData =
        `--text: #fdfdfd;
        --loader: #967ae2;
        --bg: #0d1119;
        --bg-sideBar: #161b24;
        --header-bg: #161b24aa;
        --bg-moreOptions-div: #000010bb;
        --note-bg: #8b6bf730;
        --quote-bg: #00000000;
        --console-bg: #0d0d0d;
        --border: #ffffff33;
        --console-border: #555;
        --btn-border: #b549f888;
        --invert: 1;
        --err-text: #ff6600;
        --err-code-border: #ff000070;
        --code-scrollbar-color: #ffffff22;
        --incode-bg: #ffffff22;
        --incode-border: #ffffff44;
        --scrollbar-color: #ffffff22;
        --p-link-hover-bg: linear-gradient(90deg, #d28affaa 40%, #6f9fffaa)`
    changeCSSVar(darkData)

    // check firefox
    const CSSdata = `--header-bg: #161b24;--bg-moreOptions-div: #000010;`
    if (!supportCss)
        changeCSSVar(CSSdata)
}
function applyLightMode() {
    const lightData =
        ` --text: #291c4e;
        --loader: #291c4e;
        --bg: #fefeff;
        --bg-sideBar: #ffffff;
        --bg-moreOptions-div: #ffffffbb;
        --note-bg: #8b6bf722;
        --quote-bg: #ffe60020;
        --header-bg: #ffffffbb;
        --console-bg: #ededed;
        --border: #ddd;
        --console-border: #ccc;
        --btn-border: #00000015;
        --invert: 0;
        --err-text: red;
        --err-code-border: #ff0000;
        --code-scrollbar-color: #ffffff55;
        --incode-bg: #00000011;
        --incode-border: #00000033;
        --scrollbar-color: #00000022;
        --p-link-hover-bg: linear-gradient(90deg, #b549f833 40%, #246bf733);`


    changeCSSVar(lightData)

    const CSSdata = ` --header-bg: #ffffff;--bg-moreOptions-div: #ffffff;`
    if (!supportCss)
        changeCSSVar(CSSdata)
}
function changeCSSVar(varData) {
    varData = varData.trim()
    varData = varData.split(';')
    varData = varData.map((data) => {
        data = data.replace('\n', '').trim()
        const index = data.indexOf(':')
        const prop = data.slice(0, index)
        const val = data.slice(index + 1).trim()
        return { prop, val }
    })

    varData.forEach((data) => {
        document.documentElement.style.setProperty(data.prop, data.val)
    })
}

class Switcher {
    constructor(status) {
        this.status = status
    }
    change() {
        this.status = (this.status + 1) % 3
        localStorage.darkMode = this.status
    }
}
