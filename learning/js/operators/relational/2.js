const flowers = ['Rose', 'Lily', 'Tulip', 'Orchid'];

0 in flowers; // true
'Rose' in flowers; // false
// because `flowers[0]` exists, not `flowers['Rose']`

flowers['Rose'] = 'Flower-Rose';
'Rose' in flowers; // true, now it exists
flowers['Rose'];

'length' in flowers; // true
'map' in flowers; // true
// because 'length' and 'map' are array properties
