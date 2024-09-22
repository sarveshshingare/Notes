let arr = [1, 2, 3, 4, 5, 7, 54, 21, 67, 12, 89];
const greaterThan = (e) => {
  if (e > 5) {
    return true;
  }
  return false;
};
console.log(arr);
console.log(arr.filter(greaterThan));
