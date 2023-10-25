{
  // TDZ of "a" starts from here
  console.log('Hello');

  if (true) {
    // TDZ of 'a' remains here too
    console.log('Abinash');
  }

  let a; // TDZ of 'a' ends here
  a = 100;
  console.log(a);
}
