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


// actual code

abstract class Company {
    protected string name;

    public Company(string name){
        this.name = name;
    }
    public abstract void Add(Company c);
    public abstract void Remove(Company c);
    public abstract void Display(int depth);
    public abstract void LineOfDuty();
}

class ConcreteCompany : Company {
    private List<Company>children=new List<Company>;
    public ConcreteCompany(string name) : base(string name){}
    public abstract void Add(Company c) {
        children.Add(c)
    };
    
    public abstract void Remove(Company c) {
        children.Remove(c)
    };

    public abstract void Display(int depth) {
        Console.WriteLine(new String('-', depth) + name);
        foreach(Component component in children) {
            component.Display(depth + 2);
        }
    };

    public override void LineOfDuty(){
        foreach (Company component in children){
            component.LineOfDuty();
        }
    }
}

class HRDepartment : Company {
    public HRDepartment(string name) : base(name){}
    public override void Add(Company c) {};
    public override void Remove(Company c) {};

    public override void Display(int depth){
         Console.WriteLine(new String('-', depth) + name);
    }

    public override void LineOfDuty(){
        Console.WriteLine("{0} 员工招聘培训管理". name);
    }

}


class FinanceDepartment : Company {
    public FinanceDepartment(string name) : base(name){}
    public override void Add(Company c) {};
    public override void Remove(Company c) {};

    public override void Display(int depth){
         Console.WriteLine(new String('-', depth) + name);
    }

    public override void LineOfDuty(){
        Console.WriteLine("{0} 公司财务收支管理". name);
    }
}

static void Main(string[] args) {
    ConcreteCompany root = new ConcreteCompany('北京总公司');
    root.Add(new HRDepartment('总公司人事资源部'))；
    root.Add(new HRDepartment('总公司财务部'))；
    

    ConcreteCompany comp = new ConcreteCompany('华北分公司');
    comp.Add(new HRDepartment('华北分公司人事资源部'))；
    comp.Add(new HRDepartment('华北分公司财务部'))；
    root.Add(comp)
    
    ConcreteCompany comp1 = new ConcreteCompany('华南分公司');
    comp1.Add(new HRDepartment('华南分公司人事资源部'))；
    comp1.Add(new HRDepartment('华南分公司财务部'))；
    root.Add(comp１)

    root.Display(1);

    root.LineOfDuty(1);
    Console.Read();
}
