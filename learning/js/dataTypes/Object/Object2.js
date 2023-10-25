let friend = {
  firstName: 'Doyel',
  lastName: 'Dey',

  fullName: function () {
    return this.firstName + ' ' + this.lastName;
  },
};

console.log(friend.fullName());
