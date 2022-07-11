import loadSidebarElements from "../index/sidebar.js"
import loadFromLink from "../index/loadFromLink.js"

loadSidebarElements([
    {file:'sidebar/dsa_js.json', selector:'#dsaSidebar'},
])

loadFromLink('dsa_js/index')