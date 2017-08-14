window.onload = function () {
    function extend(newobj, obj) {
        var F = function () {};
        F.prototype = obj.prototype;
        newobj.prototype = new F();
    }
    
    var Field = function (id) {
        this.id = id;
    };
    Field.prototype.save = function () {
        sessionStorage.setItem(this.id, this.getValue());
        console.log(sessionStorage.getItem(this.id));
    };
    Field.prototype.getValue = function () {
        throw new Error("you should override this method");
    };

    var InputField = function (label, id, type) {
        Field.call(this, id);
        this.input = document.createElement('input');
        this.input.id = id;
        this.input.type = type;
        this.label = document.createElement('label');
        var labelTextNode = document.createTextNode(label);
        this.label.appendChild(labelTextNode);
        this.divElement = document.createElement('div');
        this.divElement.className = 'input-field';
        this.divElement.appendChild(this.label);
        this.divElement.appendChild(this.input);
    };
    extend(InputField, Field);
    InputField.prototype.getValue = function () {
        return this.input.value;
    };

    var SelectField = function (label, id, arr) {
        Field.call(this, id);
        this.select = document.createElement('select');
        this.select.id = id;
        for(var i=0; i<arr.length; i++) {
            var option = document.createElement('option');
            option.text = arr[i]['text'];
            option.value = arr[i]['value'];
            this.select.options[i] = option;
        }
        this.label = document.createElement('label');
        var labelTextNode = document.createTextNode(label);
        this.label.appendChild(labelTextNode);
        this.divElement = document.createElement('div');
        this.divElement.className = 'select-field';
        this.divElement.appendChild(this.label);
        this.divElement.appendChild(this.select);
    };
    extend(SelectField, Field);
    SelectField.prototype.getValue = function () {
        return this.select.options[this.select.selectedIndex].value;
    };

    var input = new InputField('用户名', 'userName', 'text');
    var select = new SelectField('国家', 'country', [{text: '美国', value: 'us'}, {text: '中国', value: 'china'}]);

    document.body.appendChild(input.divElement);
    document.body.appendChild(select.divElement);

    function sub() {
        input.save();
        select.save();
    }
};