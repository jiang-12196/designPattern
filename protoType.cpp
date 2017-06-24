class Resume : ICloneable {
    private string name;
    private string sex;
    private string age;
    private string timeArea;
    private string company;

    public Resume(string name) {
        this.name = name;
    }

    public void SetPersonalInfo(string sex, string age){
        this.sex = sex;
        this.age = age;
    }

    public void SetWorkExperience(string timeArea, string company) {
        this.timeArea = timeArea;
        this.company = company;
    }

    public void Display() {
        Console.WriteLine("{0} {1} {2}", name, sex, age);
        Console.WriteLine("work experience {0} {1}", t;timeArea, company);
    }

    public Object Clone (){
        return (Object)this.MemberwiseClone();
    }
}


static void Main(string[] args) {
    Resume jiang = new Resume('jiang');
    jiang.setPersonalInfo('man', '26');
    jiang.SetWorkExperience('2016-2017', 'trantect');

    Resume zuo = jiang.Clone();
    zuo.setPersonalInfo('man', '26');
    zuo.SetWorkExperience('2016-2017', 'trantect');
    ...han;

    jiang.Display();
    zuo.Display();
}