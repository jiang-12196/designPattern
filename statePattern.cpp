abstract class State {
    public abstract void Handle(Context context);
}

class ConcreteStateA : State {
    public override void Handle(Context context) {
        context.State = new ConcreteStateB();
    }
}

class ConcreteStateB : State {
    public override void Handle(Context context) {
        context.State = new ConcreteStateA();
    }
}

class Context {
    private State state;
    public Context(State state) {
        this.state = state;
    }
    public State state{
        get (return state;)
            set {
        state = value;
        Console.WriteLine("now state"+ state.GetType().Name);
        }
    }
    public void Request(){
        state.Handle(this)
    }
}


static void Main(string[] args) {
    Context c = new Context(new ConcreteStateA());
    c.Request();
    c.Request();
    c.Request();

    Console.Read();
}

// actual code 

public abstract class state {
    public abstract void WriteProgram(Work w);
}

public class ForenoonState : State {
    public override void WriteProgram (Work w){
        if (w.Hour < 12) {
            Console.WriteLine("Current time: {0} Work in the morning, full of energy", w.Hour);
        } else {
            w.SetState(new NoonState());
            w.WriteProgram();
        }
    }
}

public class NoonState : State {
    public override void WriteProgram(Work w){
        if (w.Hour < 13) {
            Console.WriteLine("Current time {0}, sleep at noon", w.Hour);
        } else {
            w.setState(new AfternoonState());
            w.WriteProgram()
        }
    }
}

public class AfternoonState : State {
    public override void WriteProgram(Work w){
        if (w.Hour < 1７) {
            Console.WriteLine("Current time {0}, working at afternoon", w.Hour);
        } else {
            w.setState(new EveningState());
            w.WriteProgram();
        }
    }
}

public class EveningState : State {
    public override void WriteProgram(Work w) {
        if (w.TaskFinished){
            w.setState(new RestState());
            w.WriteProgram();
        } else {
            if (w.Hour < 21 ) {
                Console.WriteLine("Current time {0}, overtime working", w.Hour);
            } else {
                w.setState(new SleepingState())
                w.WriteProgram();
            }
        }
    }
}

public class SleepingState : State {
    public override void WriteProgram(Work w){
        Console.WriteLine("Current time {0}, sleeping", w.Hour);
    }
}

public class RestState : State {
    public override void WriteProgram(Work w) {
        Console.WriteLine("Current time {0}, go home", w.Hour);
    }
}

public class Work {
    private State current;
    public Work() {
        current = new ForenoonState();
    }

    private double hour;
    public double Hour{
        get {return hour;}
        set {hour = value;}
    }

    private bool finish = false;
    public bool TaskFinished {
        get {return finisth;}
        set {finish = value;}
    }
    public void SetState(State s){
        current = s;
    }
    public void WriteProgram {
        current.WriteProgram(this);
    }
}

static void Main(string[] args) {
    Work emergencyProjects = new Work();
    emergencyProjects.Hour = 9;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 10;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 12;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 13;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 14;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 15;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 17;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 18;

    // emergencyProjects.TaskFinished = true
    emergencyProjects.TaskFinished = false
    emergencyProjects.Hour = 20;
    emergencyProjects.WriteProgram();
    emergencyProjects.Hour = 20;
    emergencyProjects.WriteProgram();

    Console.Read();
}
