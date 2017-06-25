class TestPaper{
    public void TestQuestion1() {
        Console.WriteLine('问题：A,B，C,D')
        Console.WriteLine('answer:'+ Answer());
    }
    protected virtual string Answer1(){
        return '';
    }
}

class Student1Paper : TestPaper {
    protected override string Answer1(){
        return 'b'
    }
}


class Student2Paper : TestPaper {
    protected override string Answer1(){
        return 'c'
    }
}

static void Main(string[] args) {
    Console.WriteLine('student1 answer:');
    TestPaper student1 = new Student1Paper();
    student1.TestQuestion1();

    Console.WriteLine('student1 answer:');
    TestPaper student2 = new Student2Paper();
    student2.TestQuestion1();

    Console.Read();
}