const str = '50 multiplied by 3 is 50';

console.log(str.replace(/\d+$/, replaceFunc));

function replaceFunc(match) {
  return Number(match) * 3;
}
