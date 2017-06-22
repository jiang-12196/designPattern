class Leifeng {
    public void Sweep() {
        Console.WriteLine('扫地');
    }

    public void Wash() {
        Console.WriteLine("洗衣");
    }

    public void BuyRice() {
        Console.WriteLine('买米');
    }
}


class Undergraduate : Leifeng {}
class Volunteer : Leifeng {}

// 简单工厂模式

Class SimpleFactory {
    public static Leifeng CreateLeifeng(string type) {
        Leifeng result = null;
        switch(type) {
            case "Undergraduate":
                result = new Undergraduate();
                break;
            case 'Volunteer':
                result = new Volunteer();
                break;
        }
        return result;
    }
}

Leifeng student1 = SimpleFactory.CreateLeifeng('Undergraduate');
Leifeng student2 = SimpleFactory.CreateLeifeng('Undergraduate');
Leifeng student3 = SimpleFactory.CreateLeifeng('Undergraduate');

student1.Sweep();
student2.Sweep();
student3.Sweep();

// 工厂模式

interface IFactory {
    Leifeng CreateLeifeng();
}

class UndergraduateFactory : IFactory {
    public Leifeng CreateLeifeng() {
        return new Undergraduate();
    }
}

class VolunteerFactory : IFactory {
    public Leifeng CreateLeifeng() {
        return new Volunteer();
    }
}

IFactory factory = new UndergraduateFactory();

Leifeng student = factory.CreateLeifeng();

student.