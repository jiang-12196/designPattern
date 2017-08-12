var strategies = {
  minLength: function (value, num ,errorMsg) {
      if(value.length < num) {
          return errorMsg
      }
      return null;
  },
  isNotEmpty: function (value, errorMsg) {
      if (value === '') {
          return errorMsg
      }
      return null;
  },
  isMobile: function (value, errorMsg) {
    if (!/^1[3|5|8][0-9]{9}$/.test(value)) {
      return errorMsg
    }
    return null;
  }
};
var Validator = function () {
    this.cache = [];
};

Validator.prototype.add = function (dom, rule, errorMsg) {
    var arr = rule.split(":");
    this.cache.push(function () {
        var strategy = arr.shift();
        arr.unshift(dom);
        arr.push(errorMsg);
        return strategies[strategy].apply(dom, arr);
    })
};

Validator.prototype.start = function () {
    for(var i=0; i<this.cache.length; i++) {
        var msg = this.cache[i]();
        if(msg) {
            return msg;
        }
    }
    return 'nothing';
};

var validator = new Validator();
validator.add('jiang123','minLength:6','密码长度不能小于６');
validator.add('123','isNotEmpty','密码长度不能为空');
validator.add('13562777777','isMobile','手机格式不对');
console.log(validator.start());