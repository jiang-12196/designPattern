window.onload = function () {
    var throttle = function (fn, interval) {
        var _self = fn;
        var timer;
        var firstTime = true;
        return function () {
            var args = arguments;
            console.log('arg--->',arguments);
            var _me = this;
            console.log(_me);
            if(firstTime){
                _self.apply(_me, args);
                firstTime = false;
                return;
            }
            if(timer){
                return;
            }
            timer = setTimeout(function () {
                clearTimeout(timer);
                timer = null;
                _self.apply(_me, args);
            }, interval || 500)
        }
    };
    window.onresize = throttle(function () {
        console.log("hello");
    }, 1000);
};