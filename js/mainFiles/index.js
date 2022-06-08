import loadSidebarElements from "../index/sidebar.js";
import loadFromLink from '../index/loadFromLink.js'

loadSidebarElements([
    {file:'js.json', selector:'#jsSidebar'},
    {file:'other.json', selector:'#referenceSidebar'},
    {file:'usefulConcepts.json', selector:'#usefulConcepts'},
])


loadFromLink()