import loadSidebarElements from "../index/sidebar.js"
import loadFromLink from '../index/loadFromLink.js'

loadSidebarElements([
    {file:'sidebar/js.json', selector:'#jsSidebar'},
    {file:'sidebar/other.json', selector:'#referenceSidebar'},
    {file:'sidebar/usefulConcepts.json', selector:'#usefulConcepts'},
])


loadFromLink("index/Javascript Home")