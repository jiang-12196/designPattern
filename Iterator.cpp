abstract class Iterator {
    public abstract object First();
    public abstract object Next();
    public abstract bool IsDone();
    public abstract object CurrentItem();
}

abstract class Aggregate {
    public abstract Iterator CreateIterator();
}

class ConcreteIterator : Iterator {
    private ConcreteAggregate aggregate;
    private int current = 0;

    public ConcreteIterator(ConcerteAggregate aggregate){
    	this.aggregate = aggregate;
　　}
}

