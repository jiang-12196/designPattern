interface IGiveGift{
    void GiveDolls();
    void GiveFlowers();
    void GiveChocolate();
}

class Pursuit: IGiveGift {
    SchoolGirl mm;
    public Pursuit(SchoolGirl mm) {
        this.mm = mm
    }
    public void GiveDolls() {
        Console.WriteLine(mm.name + "give you dolls");
    }
    public void GiveFlowers() {
        Console.WriteLine(mm.name + "give you flowers");
    }
    public void GiveChocolate() {
        Console.WriteLine(mm.name + "give you chocolate");
    }
}

class Proxy : IGiveGift {
    Pursuit gg;
    public Proxy (SchoolGirl mm) {
        gg = new Pursuit(mm)
    }
    public void GiveDolls() {
        gg.GiveDolls();
    }
    public void GiveFlowers() {
        gg.GiveFlowers();
    }
    public void GiveChocolate() {
        gg.GiveChocolate();
    }
}


static void Main(string[] args) {
    SchoolGirl xiaoya = new SchoolGirl();
    xiaoya.name = 'xiaoya';
    Proxy daili = new Proxy(xiaoya);
    daili.GiveDolls();
    daili.GiveFlowers();
    daili.GiveChocolate();

    Console.Read();
}