const fruits = ['Apple', 'Banana', 'Pineapple']

fruits.find((element, index, arr) => {
    // You can access element, index and the original array in this way
    if (element == 'Banana') {
        console.log(index) // 1
        arr[index] = 'Found!' // You can modify elements
        return true
    }
})

console.log(fruits) // [ 'Apple', 'Found!', 'Pineapple' ]