import load from "./load.js"


export default function loadFromLink(fileName = "") {
    let url = window.location
    let search = new URL(url).searchParams.get('file')
    if (!search) {
        load(fileName)
        return
    }
    load(search)
}