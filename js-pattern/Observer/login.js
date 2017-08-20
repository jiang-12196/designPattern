var login = {};
login.eventList = {};
login.listen = function (key, fn) {
  if(!this.eventList[key]) {
      this.eventList[key] = [];
  }
  this.eventList[key].push(fn);
};
login.trigger = function (key) {
  var fns = this.eventList[key];
  if(!fns || fns.length === 0) {
      return false;
  }
  for(var i=0;i<fns.length;i++) {
      fns[i]();
  }
};
login.listen('loginSuccess',function () {
    console.log('显示用户头像');
});
login.listen('loginSuccess',function () {
    console.log('显示消息列表');
});
console.log(login.eventList);
login.trigger('loginSuccess');