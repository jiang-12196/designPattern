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
};


class Cat: Animal {
public:Cat():base(){

    }

public:Cat(string name):base(name){

    }

public: string Shout(){
        string result = "";
        for(int i=0; i < shoutNum; i++){
            result += "喵";
        }
        return "我的名字叫"+name;
    }
};