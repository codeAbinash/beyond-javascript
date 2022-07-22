let i = 1

outerLoop:
while (i <= 3) {
    let j = 1
    while (j <= 3) {
        console.log(i + ' ' + j)
        j++
    }
    i++
}