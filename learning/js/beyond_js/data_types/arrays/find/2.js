const foods =[
    {name : 'Pizza', price : 100},
    {name : 'Noodles', price : 50},
    {name : 'Momo', price : 60},
    {name : 'Cold Drinks', price : 40}
]

console.log(foods.find(elem => elem.price == 60))