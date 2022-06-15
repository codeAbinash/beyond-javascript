// import AlertWin from './alertWindow.js'

export default async function whatsNew(){
    /*let localVersion = localStorage.local_Version_number_b_j || 0
    localVersion = Number.parseInt(localVersion)

    let fetchData, jsonData
    try{
        fetchData = await fetch('./data/version/version.json')
        jsonData = await fetchData.json()

        if(jsonData.versionNumber > localVersion){
            new AlertWin(jsonData.whatsNew).show()
            localStorage.local_Version_number_b_j = jsonData.versionNumber
        }
    }catch{
        console.warn("Something Error occurred while loading version.json from server")
    }*/
}


 // Alert Window for first time
 /*if (!localStorage.firstTime) {
    localStorage.firstTime = "no"
    setTimeout(() => {
        new AlertWin({
            heading: "Getting Started",
            text: `<p><span class="bold">Beyond JavaScript</span> may contain spelling mistakes and syntactical or 
                grammatical mistakes of \"English Language\". If you find any, please inform me at 
                <a href="mailto:codeAbinash@gmail.com" class="emailPageError">codeAbinash@gmail.com</a> </br></br>
                <span class="bold">Pro Tip :</span> Tap "Beyond JavaScript" (heading) to scroll to top of the page.
                I did not use a button to do this, because it was looking terrible. 
                </br></br><p class="bold center">"UI Matters!"</p>
                </br></p>`,
            btnTxt: "START READING"
        }).show()
    }, 3000);
}*/