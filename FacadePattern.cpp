class SubSystemOne {
    public void MethodOne() {
        Console.WriteLine('sub system one')
    }
}

class SubSystemTwo {
    public void MethodTwo() {
        Console.WriteLine('sub system two')
    }
}

class SubSystemThree {
    public void MethodThree() {
        Console.WriteLine('sub system three')
    }
}

class SubSystemFour {
    public void MethodFour() {
        Console.WriteLine('sub system four')
    }
}

class Facade{
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;
    SubSystemFour four;

    public Facade() {
        one = new SubSystemOne();
        two = new SubSystemTwo();
        three = new SubSystemThree();
        four = new SubSystemFour();
    }

    public void MethodA(){
        Console.WriteLine('method A')
        one.MethodOne();
        two.MethodTwo();
        four.MethodFour();
    }

    public void MethodB(){
        Console.WriteLine('method B')
        one.MethodOne();
        two.MethodTwo();
        three.MethodThree();
    }
}

static void Main(tring[] args) {
    Facade facade = new Facade();
    facade.MethodA();
    facade.MethodB();
    Console.Read();
}