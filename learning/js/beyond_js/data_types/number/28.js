let num = 123456789;
const formatObject = {
  style: 'currency',
  currency: 'INR',
};

num.toLocaleString('en-IN', formatObject); // '₹12,34,56,789.00
