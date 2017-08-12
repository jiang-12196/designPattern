var data = {
    items: [
        {id: 1, name :'jiang', score: {math: 88, english: 72}, interest: ['football', 'pingpang']},
        {id: 2, name :'zuo', score: {math: 82, english: 92}, interest: ['football', 'pingpang']},
        {id: 3, name :'han', score: {math: 88, english: 72}, interest: ['football', 'pingpang']}
    ],
    status: 200
};

var obj = {};

shallowCopy(data, obj);

obj.status = 201;
obj.items[0].name = 'jiangzuohan';
console.log('子对象－－－－>',JSON.stringify(obj));
console.log('父对象－－－>',JSON.stringify(data));
//浅拷贝，改变子对象的值，父对象也跟着改变


function shallowCopy(src, des) {
    var desObj = des || {};
    for (var key in src) {
        if(!des.hasOwnProperty(key)){
            desObj[key] = src[key]
        }
    }
    return desObj;
}