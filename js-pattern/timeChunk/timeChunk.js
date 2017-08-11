window.onload = function () {
  var arr = [];
  for(var i=0; i < 34; i++) {
      arr.push({'name': i});
  }
  var createOneFriend = function (data) {
      var div = document.createElement('span');
      div.innerHTML = 'firend : '+data.name;
      document.body.appendChild(div);
  };

  var timeChunk = function (arr, fn, count) {
      var timer;
      var start = function () {
          var len = arr.length;
          for(var i=0;i<Math.min(count, len);i++){
              var obj = arr.shift();
              fn(obj)
          }
      };
      return function () {
          timer = setInterval(function () {
              if(arr.length === 0) {
                  clearInterval(timer);
                  return;
              }
              start();
          }, 500)
      }
  };
  var renderList = timeChunk(arr, createOneFriend, 10);
  renderList();
};