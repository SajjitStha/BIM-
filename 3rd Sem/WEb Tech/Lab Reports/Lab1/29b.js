let para1 = document.getElementById("para1");
let para2 = document.getElementById("para2");
let para3 = document.getElementById("para3");

function addNewElement() {
  para1.innerHTML = "New Element is Inserterted in paragraph 1";
  para2.innerHTML = "New Element is Inserterted in paaragraph 2";
}

function addElement() {
  para3.innerHTML = para1.textContent + " " + para2.textContent;
}

function deleteElement() {
  para1.innerHTML = para2.innerHTML = para3.innerHTML = "";
}