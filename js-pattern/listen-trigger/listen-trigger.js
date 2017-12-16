const salesOffices = {};

salesOffices.clientList = [];

salesOffices.listen = function(fn) {
    this.clientList.push(fn);
};

salesOffices.trigger = function() {
    for (let i = 0, fn; fn = this.clientList[i++];) {
        fn.apply(this, arguments);
    }
}

salesOffices.listen(function(price, squareMeter) {
    console.log("price--->", price);
    console.log("squareMeter--->", squareMeter);
})


salesOffices.listen(function(price, squareMeter) {
    console.log("价格--->", price);
    console.log("平方--->", squareMeter);
})

salesOffices.trigger(2000, 80);