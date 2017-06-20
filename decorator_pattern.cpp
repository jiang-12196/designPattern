class Person {
    public Person () {
    }

    private string name;
    public Person(string name) {
        this.name = name;
    }

    public virtual void Show() {
        Console.WriteLine('装扮的{0}'， name);
    }
}

class Finery : Person {
    protected Person component;
    
    public void Decorate(Person component) {
        this.component = component;
    }

    public override void show() {
        if (component != null){
            component.Show();
        }
    }
}

class Tshirts : Finery {
    public override void Show() {
        Console.Write('大T恤')
        base.Show();
    }
}

class BigTrouser: Finery {
    public override void Show() {
        Console.Write('垮裤')
        base.Show();
    }
}

class Sneaker: Finery {
    public override void Show() {
        Console.Write('破球鞋')
        base.Show();
    }
}

#...类似

static void Main(string[] args) {
    Person jiang = new Person("jiang");

    Console.WriteLine('\n 第一种打扮')；
    Sneaker pqx = new Sneaker();
    BigTrouser kk = new BigTrouser();
    Tshirts dtx = new Tshirts();

    #装饰过程
    pqx.Decorate(jiang);
    kk.Decorate(pqx);
    dtx.Decorate(kk);
    dtx.Show();

    Console.WriteLine('\n 第二种打扮')；
    LeatherShoes px = new LeatherShoes();
    Tie ld = new Tie();
    Suit xz = new Suit();

    #装饰过程
    px.Decorate(jiang);
    ld.Decorate(px);
    xz.Decorate(ld);
    xz.Show();

    Console.Read();
}