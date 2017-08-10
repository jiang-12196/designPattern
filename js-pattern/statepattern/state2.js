window.onload = function () {
  var StateMachine = {
      off: {
          pressButton: function () {
              console.log('关灯');
              this.button.innerHTML = '下次按我是开灯';
              this.currentState = this.on;
          }
      },
      on: {
          pressButton: function () {
              console.log('开灯');
              this.button.innerHTML = '下次按我是关灯';
              this.currentState = this.off;
          }
      }
  };

  var delegate = function (client, todoObj) {
      return {
          pressButton: function () {
              return todoObj.pressButton.apply(client, arguments);
          }
      };
  };

  var Light = function () {
      this.off = delegate(this, StateMachine.off);
      this.on = delegate(this, StateMachine.on);
      this.currentState = this.off;
      this.button = null;
  };
  Light.prototype.init = function () {
      var button = document.createElement('button');
      var _self = this;
      button.innerHTML = '灯关了';
      this.button = document.body.appendChild(button);
      this.button.onclick = function () {
          _self.currentState.pressButton()
      };
  };
  var light = new Light();
  light.init();
};