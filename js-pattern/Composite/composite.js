var CompositeForm = function (id) {
  this.formComponents = [];
  this.formElement = document.createElement('from');
  this.formElement.id = id;
  this.formElement.onsumbit = function () {
      return false
  }
};

CompositeForm.prototype.add = function (child) {
  this.formComponents.push(child);  
};

CompositeForm.prototype.loadElements = function () {
  for(var i=0;i<this.formComponents.length;i++) {
      this.formElement.appendChild(this.formComponents[i].divElement);
  }
  var submitButton = document.createElement('input');
  submitButton.id = 'sub';
  submitButton.type = 'submit';
  this.formElement.appendChild(submitButton);
};

CompositeForm.prototype.save = function () {
  for(var i=0;i<this.formComponents.length;i++) {
      this.formComponents[i].save();
  }
};

var InputField = function (label, id, type) {
  this.input = document.createElement('input');
  this.input.id = id;
  this.input.type = type;
  this.label = document.ccreateElement('input');
  var labelTextNode = document.createTextNode(label);
  this.label.appendChild(labelTextNode);
  this.divElement = document.createElement('div');
  this.divElement.className = 'input-field';
  this.divElement.appendChild(this.label);
  this.divElement.appendChild(this.input);
};

InputField.prototype.save = function () {
    var value = this.input.value;
    sessionStorage.setItem(this.input.id, value);
    console.log(sessionStorage.getItem(this.input.id));
};

var form = new CompositeForm('myform');

form.add(new InputField('用户名'), 'userName', 'text');
form.add(new InputField('密码'), 'passWd', 'password');
form.add(new InputField('邮箱'), 'email', 'text');
form.loadElements();
document.body.appendChild(from.formElement);
document.getElementById('sub').onclick = function () { form.save() };

