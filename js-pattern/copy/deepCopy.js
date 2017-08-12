var data = {
    items: [
        {id: 1, name :'jiang', score: {math: 88, english: 72}, interest: ['football', 'pingpang']},
        {id: 2, name :'zuo', score: {math: 82, english: 92}, interest: ['football', 'pingpang']},
        {id: 3, name :'han', score: {math: 88, english: 72}, interest: ['football', 'pingpang']}
    ],
    status: 200
};


var obj = {};

deepCopy(data, obj);

obj.status = 201;
obj.items[0].name = 'jiangzuohan';
console.log('子对象－－－－>',JSON.stringify(obj));
console.log('父对象－－－>',JSON.stringify(data));


function deepCopy(src, destObj) {
    var destObj = destObj || {};
    for (var key in src) {
        if(!destObj.hasOwnProperty(key)) {
            if(typeof src[key] === 'object') {
                destObj[key] = (src[key].constructor === Array) ? [] : {};
                deepCopy(src[key], destObj[key])
            } else {
                destObj[key] = src[key]
            }
        }
    }
    return destObj;
}