5 > 'JS'; // false, "JS" is converted to NaN
NaN > '55'; // false
NaN > NaN; // false
'4' > NaN; // false
4 > { name: 'Abinash' }; // false the object is converted to NaN
