abstract class PersonBuilder {
    protected Graphics g;
    protected Pen p;

    public PersonBuilder(Graphics g, Pen p) {
        this.g = g;
        this.p = p;
    }
    public abstract void BuildHead();
    public abstract void BuildBody();
    public abstract void BuildArmLeft();
    public abstract void BuildArmRight();
    public abstract void BuildLegLeft();
    public abstract void BuildLegRight();
}

class PersonThinBuilder : PersonBuilder {
    public PersonThinBuilder(Graphic g, Pen p) : base(g, p){}
    public override void BuildHead(){
        g.DrawEllipse(p, 50, 20, 30, 30);
    };
    public override void BuildBody(){
        g.DrawReactangle(p, 60, 50, 10, 50);
    };
    public override void BuildArmLeft(){
        g.DrawLine(p, 60, 50, 40, 100);
    };
    public override void BuildArmRight(){
        g.DrawLine(p, 70, 50, 90, 100);
    };
    public override void BuildLegLeft(){
        g.DrawLine(p, 60, 100, 45, 100);
    };
    public override void BuildLegRight(){
        g.DrawLine(p, 70, 1000, 85, 100);
    };
}

class PersonDirector {
    private PersonBuilder pb;
    public PersonDirector(PersonBuilder pb){
        this.pb = pb;
    }
    public void CreatePerson(){
        pb.BuildHead();
        pb.BuildBody();
        pb.BuildArmLeft();
        pb.BuildArmRight();
        pb.BuildLegRight();
        pb.BuildLegLeft();
    }

}


Pen p = new Pen(Color.Yellow);
PersonThinBuilder ptb = new PersonThinBuilder(pictureBox1.CreateGraphics(), p);
PersonDirector pbThin = new PersonDirector(ptb);
pbThin.CreatePerson();

PersonFatBuilder pfb = new PersonFatBuilder(pictureBox2.CreateGraphics(), p);
PersonDirector pdFat = new PersonDirector(pfb);
pdFat.CreatePerson();


// 建造者模式

//产品类， 可以是小人，也可以是食品，由多个部件组成
class Product{
    IList<string> parts = new List<string>();

    public void Add(string part){
        parts.Add(part);
    }

    public void Show(){
        Console.WriteLine('产品：');
        foreach(string part in parts){
            Console.WriteLine(part);
        }
    }
}

// 抽象建造者类
abstract class Builder{
    public abstract void BuildPartA();
    public abstract void BuildPartb();
    public abstract Product GetResult();
}
// 具体建造者类
class ConcreteBuilder1 : Builder{
    private Product product = new Product();

    public override void BuildPartA(){
        product.Add('部件A');
    }


    public override void BuildPartB(){
        product.Add('部件B');
    }

    public override Product GetResult(){
        return product;
    }
}

class ConcreteBuilder2 : Builder{
    private Product product = new Product();

    public override void BuildPartA(){
        product.Add('部件X');
    }


    public override void BuildPartB(){
        product.Add('部件Y');
    }

    public override Product GetResult(){
        return product;
    }
}

//指挥者类
class Director {
    public void Construct(Builder builder){
        builder.BuildPartA();
        builder.BuildPartB();
    }
}

static void Main(string[] args){
    Director director = new Director();
    Builder b1 = new ConcreteBuilder1();
    Builder b2 = new ConcreteBuilder2();

    director.Construct(b1);
    product p1 = b1.GetResult();
    p1.Show();

    director.Construct(b2);
    product p2 = b2.GetResult();
    p2.Show();

    Console.Read();
}