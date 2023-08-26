document.addEventListener("DOMContentLoaded", function() {
  const form = document.getElementById("form");
  const fullname = document.getElementById("fullname");
  const email = document.getElementById("email");
  const rollno = document.getElementById("rollno");
  const contact = document.getElementById("contact");
  const radioButtons = document.querySelectorAll('input[name="branch"]');

  form.addEventListener("submit", function(event) {
    event.preventDefault();

    const isFullNameValid = checkInput(fullname);
    const isEmailValid = checkEmail(email);
    const isRollNoValid = checkInput(rollno);
    const isContactValid = checkContact(contact);
    const isRadioButtonSelected = checkRadioButtons(radioButtons);

    if (isFullNameValid && isEmailValid && isRollNoValid && isContactValid && isRadioButtonSelected) {
      alert("Form submitted successfully!");
    }
  });

  function checkInput(input) {
    const formControl = input.parentElement;
    if (input.value.trim() === "") {
      showError(formControl, `${getFieldName(input)} can not be empty`);
      return false;
    } else {
      showSuccess(formControl);
      return true;
    }
  }

  function checkEmail(input) {
    const formControl = input.parentElement;
    if (input.value.trim() === "") {
      showError(formControl, `${getFieldName(input)} can not be empty`);
      return false;
    } 
    else {
      if (isValidEmail(input.value) == true)
      {
        showSuccess(formControl);
        return true;
      }  
      else {
        showError(formControl, "Invalid Email");
        return false;
      }
    }
  }

  function isValidEmail(email) {
    const re = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    return re.test(email);
  }

  function checkContact(input) {
    const formControl = input.parentElement;
    if (input.value.trim() === "") {
      showError(formControl, `${getFieldName(input)} can not be empty`);
      return false;
    } 
    else {
      if (isValidPhoneNumber(input.value) == true)
      {
        showSuccess(formControl);
        return true;
      }  
      else {
        showError(formControl, "Invalid Contact");
        return false;
      }
    }
  }

  function isValidPhoneNumber(phoneNumber) {
    const sanitizedPhoneNumber = phoneNumber.replace(/\D/g, ""); // Remove non-digit characters
    return sanitizedPhoneNumber.length === 10;
  }

  function checkRadioButtons(radioButtons) {
    const formControl = radioButtons[0].closest(".form-control");
    if (Array.from(radioButtons).some(button => button.checked)) {
      showSuccess(formControl);
      return true;
    } else {
      showError(formControl, "Please select a department");
      return false;
    }
  }

  function showError(formControl, message) {
    const small = formControl.querySelector("small");
    formControl.className = "form-control error";
    small.innerText = message;
    small.style.color = "red"; // Set error message color to red
  }

  function showSuccess(formControl) {
    formControl.className = "form-control success";
    const small = formControl.querySelector("small");
    small.innerText = "";
  }

  function getFieldName(input) {
    return input.id.charAt(0).toUpperCase() + input.id.slice(1);
  }

  // Clear error message on input
  [fullname, email, rollno, contact].forEach(input => {
    input.addEventListener("input", function() {
      const formControl = input.parentElement;
      const small = formControl.querySelector("small");
      formControl.classList.remove("error");
      small.innerText = "";
    });
  });
});
