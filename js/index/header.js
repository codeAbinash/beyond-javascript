import debounce from '../debounce.js';
import filterSearch from './filterSearch.js';

let menuIcon = document.getElementById('menuIcon');
let sideBar = document.getElementById('sideBar');
let sideBarCancel = document.getElementById('sidebarCancel');
let searchBar = document.getElementById('search');
let sideBarClickHide = document.querySelectorAll('.body .sideBar .list');
let mainLogo = document.getElementById('logo');

mainLogo.addEventListener('click', () => {
  scrollToTop();
});

let menuOpen = false;
const animDuration = getAnimDuration();
export function hideMenu() {
  if (window.innerWidth >= 900) return;
  sideBar.style.left = 'calc(-80%)';
  sideBarCancel.style.backgroundColor = '#00000000';
  setTimeout(() => {
    sideBarCancel.style.display = 'none';
  }, animDuration);
  menuOpen = false;
  searchBar.blur();
}

export function showMenu() {
  sideBar.style.left = 0;
  sideBarCancel.style.display = 'block';
  setTimeout(() => {
    sideBarCancel.style.backgroundColor = '#00000033';
  }, 10);
  menuOpen = true;
}

export function menuOperation() {
  if (window.innerWidth >= 900) return;

  setTimeout(() => {
    if (menuOpen) {
      hideMenu();
    } else {
      showMenu();
    }
  }, 50);
}

function getAnimDuration() {
  const style = getComputedStyle(document.body);
  const cssVar = style.getPropertyValue('--anim-duration');
  const animDuration = parseFloat(cssVar) * 1000;
  return animDuration;
}
export default function handelMenu() {
  menuIcon.addEventListener('click', menuOperation);
  sideBarCancel.addEventListener('click', hideMenu);

  sideBarClickHide.forEach((listElement) => {
    listElement.addEventListener('click', function () {
      menuOperation();
      clearSearch();
    });
  });

  searchBar.addEventListener(
    'input',
    debounce(
      () => {
        filterSearch(searchBar.value);
      },
      300,
      false,
    ),
  );

  let moreOptions = document.getElementById('moreOptions');
  let moreOptionsDiv = document.getElementById('moreOptionsDiv');
  moreOptions.onclick = function () {
    moreOptionsDiv.style.left = 0;
  };

  moreOptionsDiv.onclick = closeMoreOptions;
  function closeMoreOptions() {
    setTimeout(() => {
      moreOptionsDiv.style.left = '100%';
    }, 50);
  }

  function clearSearch() {
    searchBar.value = '';
    filterSearch('');
  }
}

function scrollToTop() {
  window.scrollTo({
    top: 0,
    left: 0,
    behavior: 'smooth',
  });
}

/// Add Escape Event Listener to Search bar
searchBar.onkeydown = (e) => {
  if (e.key === 'Escape') {
    e.preventDefault();
    searchBar.blur();
  }
};

// Different Window Width Operation
let windowWidth = window.innerWidth;
if (windowWidth >= 900) {
  searchBar.placeholder = 'Shift + F to Search';
}
