let x = "alert	all	anchor	anchors area assign blur button checkbox clearInterval clearTimeout clientInformation close closed confirm constructor crypto decodeURI decodeURIComponent defaultStatus document element elements embed embeds encodeURI encodeURIComponent escape event fileUpload focus form forms frame innerHeight innerWidth layer layers link location mimeTypes navigate navigator frames frameRate hidden history image images offscreenBuffering open opener option outerHeight outerWidth packages pageXOffset pageYOffset parent parseFloat parseInt password pkcs11 plugin prompt propertyIsEnum radio reset screenX screenY scroll secure select self setInterval setTimeout status submit taint text textarea top unescape untaint window"
x = "onblur	onclick	onerror	onfocus onkeydown onkeypress onkeyup onmouseover onload onmouseup onmousedown onsubmit"

let y = x.split(" ")
y.forEach((data)=>{
    console.log(`<span class="incode">${data}</span>`);
})

