function validate() {
    const name = document.getElementById("name").value;
    const age = document.getElementById("age").value;
    const gender = document.getElementById("gender").value;
    const email = document.getElementById("email").value;
    const cc = document.getElementById("cc").value;
    const country = document.getElementById("country").value;
    const err = document.getElementById("err");
  
    if (name === "" || age === "" || gender == "" || email === "" || cc === "") {
      err.innerHTML = "All Fields Should be Filled";
      return false;
    }
    if (!/^\d+$/.test(age)) {
      err.innerHTML = "Age should only be a number and cannot be empty";
      return false;
    }
    if (!email.includes("@") || !email.includes(".")) {
      err.innerHTML = "Incorrect Email Format";
      return false;
    }
    if (!/^\d+$/.test(cc) || cc.length > 3) {
      err.innerHTML = "Country Code should only be a number and 3 digits long";
      return false;
    }
    if (country === "Null") {
      err.innerHTML = "Choose a Country";
      return false;
    }
  
    return true;
  }