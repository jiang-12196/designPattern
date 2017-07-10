class Target {
    public virtual void Request() {
        Console.WriteLine("普通请求！");
    }
}

clas Adaptee {
    public void SpecificRequest(){
        Console.WriteLine("特殊请求");
    }
}

class Adapter : Target {
    private Adaptee adaptee = new Adaptee();

    public override void Request(){
        adaptee.SpecificRequest();
    }
}

static void Main(string[] args){
    Target target = new Adapter();
    target.Request();
    Console.Read();
}



abstract class Player{
    protected string name;
    public Player(string name){
        this.name = name;
    }
    public abstract void Attack();
    public abstract void Defense();
}

class Forwards : Player {
    public Forwards(string name) : base(name){

    }
    public override void Attack(){
        Console.WriteLine('go, go, go {0}', this.name)
    }
    public override void Defense(){
        Console.WriteLine('come, come, come {0}', this.name)
    } 
}

class Center : Player {
    ...
}

class Guards : Player {
    ...
}

class ForeignCenter {
    private string name;
    public string Name {
        get {return name;}
        set {name = value;}
    }
    public void 进攻(){
        Console.WriteLine('进攻');
    }
    public void 防守(){
        Console.WriteLine('防守');
    }
}

class Translator : Player {
    private ForeignCenter wjzf = new ForeignCenter();

    public Translator(string name) : base(name) {
        wjzf.Name = name;
    }
    public override void Attack(){
        wjzf.进攻()
    }
    public override void Defense(){
        wjzf.防守()
    }
}

static void Main(string[] args){
    Player b = new Forwards('badier');
    b.Attack();
    Player j = new Center('john');
    j.Defense();
    Player ym = new Translator('姚明');
    ym.Attack();
    ym.Defense();

    Console.Read();
}