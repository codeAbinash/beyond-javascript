const str = 'Distance from Iceland to UK is 1362km and US is 5710 km';

console.log(str.replace(/\d+.?km/gi, replaceKm));

function replaceKm(match) {
  const km = Number.parseInt(match);
  const mile = (0.62137119 * km).toFixed(3);
  return mile + ' miles';
}
