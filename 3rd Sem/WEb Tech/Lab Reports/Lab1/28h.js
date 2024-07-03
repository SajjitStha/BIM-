let list = [2, 3, 4, 5, 6, 7, 8, 9];
let sum = 0;

list.forEach(sumOfOdd);

function sumOfOdd(n) {
  if (n % 2 != 0) sum += n;
}

console.log(sum);