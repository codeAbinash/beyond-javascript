function myFunction(num){
    if(num>5){
        let num = num * 5 
        // temporal dead zone is not ended but accessing
        console.log(num)
    }
}

myFunction(10)