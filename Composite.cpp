abstract class Component{
    protected string name;
    public Component(string name){
        this.name = name
    }

    public abstract void Add(Component c);
    public abstract void Remove(Component c);
    public abstract void Display(int depth);
}

class Leaf : Component {
    public Leaf(string name){
        : base(name) {}
    }
    public override void Add(Component c) {
        Console.WriteLine('Cannot add to a leaf');
    }
    public override void Remove(Component c) {
        Console.WriteLine('Cannot remove to a leaf');
    }
    public override void Display(int depth) {
        Console.WriteLine(new String('-', depth) + name);
    }
    
}

class Composite : Component {
    private List<Component>children = new List<Component>();

    public Component(string name) : base(name)()

    public override void Add(Component c){
        children.Add(c)
    }
    public override void Remove(Component c){
        children.Remove(c)
    }
    public override void Display(int depth){
        Console.WriteLine(new String('-', depth) + name);
        foreach(Component component in children) {
            component.Display(depth + 2);
        }
    }
}

static void Main(string[] args){
    Composite root = new Composite('root');
    root.Add(new Leaf('A'));
    root.Add(new Leaf('b'));

    Composite comp = new Composite('X');
    comp.Add(new Leaf('XA'));
    comp.Add(new Leaf('Xb'));
    
    root.Add(comp);

    Composite comp2 = new Composite('XY');
    comp2.Add(new Leaf('XYA'));
    comp2.Add(new Leaf('XYb'));
    
    comp.Add(comp2);

    root.Display();
    Console.Read();
}