window.onload = function() {
    var Light = function () {
        this.state = 'off';
        this.button;
    };
    var button = document.createElement('button');
    Light.prototype.init = function () {
        var _self = this;
        button.innerHTML = '开';
        this.button = document.body.appendChild(button);
        this.button.onclick = function () {
            _self.pressButton();
        }
    };
    Light.prototype.pressButton = function () {
        if (this.state == 'off') {
            console.log('开灯');
            button.innerHTML = '关';
            this.state = 'on'
        } else if (this.state == 'on') {
            console.log('关灯');
            this.state = 'off';
            button.innerHTML = '开';
        }
    };
    var light = new Light();
    light.init();
};