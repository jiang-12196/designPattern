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


// 客户端代码
Boss jiang = new Boss();

StockObserver  tongshi1 = new StockObserver('zuohan', jiang)
NBAObserver tongshi2 = new NBAObserver("hanhan", jiang)

jiang.Attach(tongshi1);
jiang.Attach(tongshi2);

jiang.Detach(tongshi1);

jiang.SubjectState = 'bost come back';
jiang.Notify();



// 
abstract class Subject {
    private IList<Observer> observer = new List<Observer>

    public void Attach(Observer observer){
        Observers.Add(Observer)
    }

    public void Detach(Observer observer){
        Observer.Remove(observer);
    }

    public void Notify() {
        foreach (Observer o in observers) {
            o.Update();
        }
    }
}

abstract class Observer {
    public abstract void Update();
}

class ConcreteSubject :Subject {
    private string SubjectState;
    public string SubjectState {
        get {return SubjectState; }
        set {SubjectState = value; }
    }
}

class ConcreteObserver : Observer {
    private string name;
    private string observerState;
    private ConcreteSubject subject;

    public ConcreteObserver(ConcreteSubject subject, string name){
        this.subject = subject;
        this.name = name;
    }

    public override void Update() {
        observerState = subject.SubjectState;
        Console.ＷriteLine("观察者｛０｝的状态｛１｝", name, observerState);
    }

    public ConcreteSubject Subject{
        get {return subject}
        set {subject = value}
    }
}


static void Main(string[] args) {
    ConcreteSubject s = new ConcreteSubject();
    s.Attach(new ConcreteObserver(s, "x"))
    s.Attach(new ConcreteObserver(s, "y"))
    s.Attach(new ConcreteObserver(s, "z"))

    s.SubjectState = "happy";

    s.Notify();

    Console.Read();
}