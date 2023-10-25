class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
}

const me = new Person('Abinash', 20);

me instanceof Person; // true
