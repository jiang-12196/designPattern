class Originator {
    private string state;
    private string State{
        get {return state;}
        set {state = value;}
    }
    public Memento CreateMemento(){
        return (new Memento(state))
    }
    public void SetMemento(Memento memento){
        state = memento.State;
    }
    public void Show(){
        Console.WriteLine('state='+ state);
    }
}

class Memento {
    private string state;
    public Memento(string state){
        this.state = state;
    }
    public string State{
        get {return state;}
    }
}

class Caretaker{
    private Memento memento;
    public Memento Memento {
        get {return memento;}
        set {memento = value;}
    }
}

static void Main(string[] args){
    Originator o = new Originator();
    o.State = 'on';
    o.Show();

    Caretaker c = new Caretaker();
    c.Memento = o.CreateMemento();

    o.State = 'off';
    o.show();

    o.SetMemento(c.Memento);
    o.show();

    Console.Read();
}


// example


class GameRole {
    public RoleStateMemento saveState(){
        return (new RoleStateMemento(vit, atk, def));
    }

    public void RecoveryState(RoleStateMemento memento){
        this.vit = memento.Vitality;
        this.ack = memento.Attack;
        this.def = memento.Defense;
    }
    ...
}

class RoleStateMemento{
    private int vit;
    private int atk;
    private int def;
    public RoleStateMemento(int vit, int atk, int def) {
        this.vit = vit;
        this.atk = atk;
        this.def = def;
    }
    public int Vitality {
        get {return vit;}
        set {vit = value;}
    }

    public int Attack {
        get {return atk;}
        set {atk = value;}
    }

    public int Defense {
        get {return def;}
        set {def = value;}
    }
}

class RoleStateCaretaker{
    private RoleStateMemento memento;
    public RoleStateMemento Memento {
        get {return memento;}
        set {memento = value;}
    }
}

static void Main(string[] args){
    GameRole jiang = new GameRole();
    jiang.GetInitState();
    jiang.StateDisplay();

    RoleStateCaretaker stateAdmin = new RoleStateCaretaker();
    stateAdmin.Memento = jiang.SaveState();

    jiang.Fight();
    jiang.StateDisplay();

    jiang.RecoverState(stateAdmin.Memento);
    jiang.StateDisplay();

    Console.Read();
}