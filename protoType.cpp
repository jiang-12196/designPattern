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
        Console.WriteLine("work experience {0} {1}", timeArea, company);
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
    han.Display();

    Console.Read(); 
}

//深复制

class WorkExperience : ICloneable {
    private string workDate;
    public string WorkDate {
        get {return workDate};
        set { workDate = value};
    }

    private string company;
    public string Company {
        get {return company};
        set {company = value};
    }
    
    public Object Clone() {
        return (Object)this.MemberwiseClone();
    }
}

class Resume : ICloneable {
    private string name;
    private string sex;
    private string age;
    private WorkExperience work;

    public Resume(string name) {
        this.name = name;
        work = new WorkEcperience();
    }
    private Resume(WorkExperience work) {
        this.work = (WorkExperience)work.Clone();
    }
    public void SetPersonalInfo(string sex, string age) {
        this.sex = sex;
        this.age = age;
    }
    public void SetWorkExperience(string workDate, string company) {
        work.WorkDate = workDate;
        work.Company = company;
    }
    public void Display() {
        Console.WriteLine("{0} {1} {2}", name, sex, age);
        Console.WriteLine("work experience {0} {1}", work.WorkDate, work.Company);
    }

    public Object Clone(){
        Resume obj = new Resume(this.work);
        obj.name = this.name;
        obj.sex = this.sex;
        obj.age = this.age;
        return obj;
    }
}