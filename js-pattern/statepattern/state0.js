window.onload = function () {
  var offState = function (light) {
      this.light = light;
  };
  offState.prototype.pressButton = function () {
    console.log('弱光');
    this.light.setState(this.light.weak);
  };

  var weakState = function (light) {
    this.light = light;
  };
  weakState.prototype.pressButton = function () {
    console.log('强光');
    this.light.setState(this.light.strong);
  };

  var strongState = function (light) {
    this.light = light;
  };
  strongState.prototype.pressButton = function () {
    console.log('关闭');
    this.light.setState(this.light.off);
  };

  var Light = function () {
      this.off = new offState(this);
      this.weak = new weakState(this);
      this.strong = new strongState(this);
      this.button = null;
  };
  Light.prototype.init = function () {
      var button = document.createElement('button');
      var _self = this;
      this.button = document.body.appendChild(button);
      this.button.innerHTML = '三种状态开关';
      this.currentState = this.off;
      this.button.onclick = function () {
          _self.currentState.pressButton()
      };
  };

  Light.prototype.setState = function (newState) {
      this.currentState = newState;
  };
  var light = new Light();
  light.init();
};