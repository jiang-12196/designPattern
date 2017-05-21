//
// Created by jiang on 17-5-21.
//

class Cat
{
private: string name = "";
public:
    Cat(string name) {
        this.name = name;
    }
    Cat() {
        this.name = "无名";
    }
    string Shout() {
        return "我的名字叫"+name;
    }
};

private void button1_Click(object sender, EventArgs e) {
    cat = New Cat("cat");
    MessageBox.Show(cat.Shout());
}


class Animal {
protected: string name = "";
    int shoutNum = 3;
public: Animal(string name){
        this.name = name;
    }
    Animal(){
        this.name = "无名";
    }

public:  int ShoutNum {
            get {
                return shoutNum;
            }
            set {
                shoutNum = value;
            };
    };
public:virtual string Shout(){
        string result = "";
        for (int i =0 ; i<shoutNum; i++) {
            result += getShoutSound() + ",";
        }
        return result;
    }

protected:virtual string getShoutSound() {
        return "";
    }
};


class Cat: Animal {
public:Cat():base(){

    }

public:Cat(string name):base(name){

    }

protected:override string getShoutSound() {
        return "喵";
    }

//public: string override Shout(){
//        string result = "";
//        for(int i=0; i < shoutNum; i++){
//            result += "喵";
//        }
//        return "我的名字叫"+name;
//    }
};

interface IChange {
        string ChangeThing(string thing);
};

class MachineCat: Cat, IChange {
public:MachineCat() {
        : base(){}
        MachineCat(string name) {
            : base(name)
        }
        string ChangeThing(string thing) {
            return base.Shout() + "我有万能的口袋，我能变成"+ thing;
        }
    }
};

private void button6_Click(object sender,EventArgs e) {
    MachineCat mcat = new MachineCat("小叮当");
    StoneMonkey wukong = new StoneMonkey("孙悟空");
    IChange[] array = new IChange[2];
    array[0] = mcat;
    array[1] = wukong;
    MessageBox.Show(array[0].ChangeThing("every thing"));
    MessageBox.Show(array[1].ChangeThing("72 bian"));
}