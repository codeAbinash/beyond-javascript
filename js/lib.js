export default function () {
  let year = new Date().getUTCFullYear();
  let yearElements = document.querySelectorAll('.currentYear');
  yearElements.forEach((elem) => {
    elem.textContent = year;
  });
}
