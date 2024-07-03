let name = "Sajjit";
// String Manipulation
let length = name.length;
let strSlice = name.slice(5);
let strSubString = name.substring(0, 3);
let strUpperCase = name.toUpperCase();
let strConcat = name.concat(" is My Name");

document.write(
  "Length: " +
    length +
    "<br>Slice: " +
    strSlice +
    "<br>Sub String from 0 to 3: " +
    strSubString +
    "<br>Upper Case: " +
    strUpperCase +
    "<br>Concatination: " +
    strConcat
);