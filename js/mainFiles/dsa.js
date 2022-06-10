import loadSidebarElements from "../index/sidebar.js";
import loadFromLink from "../index/loadFromLink.js";

loadSidebarElements([
    {file:'sidebar/dsa.json', selector:'#dsaSidebar'},
])

loadFromLink('dsa/index')