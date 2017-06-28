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