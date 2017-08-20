var event = {
    eventList: {},
    listen: function (key, fn) {
        if(!this.eventList[key]) {
            this.eventList[key] = [];
        }
        this.eventList[key].push(fn);
    },
    trigger: function () {
        var key = Array.prototype.shift.call(arguments);
        var fns = this.eventList[key];
        if(!fns || fns.length === 0) {
            return false;
        }
        for(var i=0; i<fns.length;i++) {
            fns[i].apply(this, arguments);
        }
    },
    remove: function (key, fn) {
        var fns = this.eventList[key];
        if(!fns) {
            return false;
        }
        if(!fn) {
            fns && (fns.length = 0);
        } else {
            for (var i=0; i<fns.length;i++) {
                if(fns[i] === fn) {
                    fns.splice(i,1);
                }
            }
        }
    }
};

var installEvent = function (obj) {
  for(var i in event) {
      obj[i] = event[i];
  }
};
var login = {};
installEvent(login);
function a() {
    console.log('显示用户头像');
}
function b() {
    console.log('显示消失列表');
}
login.listen('loginSuccess', a);
login.listen('loginSuccess', b);
login.trigger('loginSuccess');
console.log('------------------------->');
login.remove('loginSuccess', a);
login.trigger('loginSuccess');