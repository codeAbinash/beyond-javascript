let i = 1, j = 1

myLoop:
while (i < 3){
    j = 0
    while (j < 3) {
        if(i == 2 && j == 2)
            break myLoop
        console.log(i, j)
        j++
    }
    i++
}