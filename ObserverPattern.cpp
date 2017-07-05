abstract class Observer {
    protected string name;
    protected Secretary sub;

    public Observer (string name, Secretary sub) {
        this.name = name;
        this.sub = sub
    }

    public abstract void Update();
}

class StockObserver : Observer {
    public StockObserver(string name, Secretary sub) : base(name, sub) {}

    public override void Update() {
        Console.log{" {0} {1}关闭股票行情，继续工作！", sub.SecretaryAction, name};
    }
}

class NBAObserver : Observer {
    public NBAObserver(string name, Secretary sub) : base(name, sub){}

    public override void Update(){
        Console.WriteLine("{0} {1}关闭NBA, 继续工作",  sub.SecretaryAction, name};
    }
}

class Secretary {
    private IList<
}
// wrong 
// ----------------------------------------------------------

interface Subject {
    void Attach (Observer oberver);
    void Detach (Observer observer);
    void Notify();
    string SubjectState {
        get;
        set;
    }
}

class Boss： Subject {
    private Ilist<Observer> Observer = new List<Observer>();
    private string action;

    public void Attach(Observer observer){
        observers.Add(Observer)
    }

    public void Detach(Observer observer){
        Observer.Remove(observer)
    }

    public void Notify(){
        foreach (Observer o in observers)
            o.Update();
    }

    public string SubjectState {
        get {return action};
        set {action = value}
    }
}

abstract class Observer {
    protected string name;
    protected Subject sub;
    public Observer(string name, Subject sub){
        this.name = name;
        this.sub = sub;
    }
    public abstract void Update();
}

class StockObserver : Observer {
    public StockObserver(string name, Subject sub) : base(name, sub) {};

    public override void Update() {
        Console.WriteLine("{0} {1}关闭股票行情，继续工作！"，　sub.SubjectState, name);
    }
}

class NBAObserver : Observer {
    public NBAObserver(string name, Subject sub) : base(name, sub) {};

    public override void Update() {
        Console.WriteLine("{0} {1}关闭股票行情，继续工作！"，　sub.SubjectState, name);
    }
}

Boss jiang = new Boss();

StockObserver  tongshi1 = new StockObserver('zuohan', jiang)
NBAObserver tongshi2 = new NBAObserver("hanhan", jiang)

jiang.Attach(tongshi1);
jiang.Attach(tongshi2);

jiang.Detach(tongshi1);

jiang.SubjectState = 'bost come back';
jiang.Notify();


abstract class Subject 