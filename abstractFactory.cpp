interface IUser {
    void Insert(User user);
    User GetUser(int id);
}

class SqlserverUser : IUser {
    public void Insert(User user) {
        Console.WriteLine("在ＳＱＬ Server中给user表增加一条记录")；
    }
    public User GetUser(int id) {
        Console.WriteLine("在sql server 中根据ｉｄ得到Ｕser表一条记录");
        return null;
    }

}

class AccessUser : IUser {
    public void Insert(User user) {
        Console.WriteLine("在Access中给Ｕｓｅｒ表增加一条记录");
    }

    public User GetUser(int id) {
        Console.WriteLine("在Ａｃcess中根据ＩＤ得到Ｕser表一条记录")；
        return null;
    }
}

interface IFactory {
    IUser CreateUser();
}

class SqlServerFactory : IFactory {
    public IUser CreateUser(){
        return new SqlserverUser();
    }
}

class AccessFactory : IFactory {
    public IUser CreateUser(){
        return new AccessUser()
    }
}

static void Main(string[] args) {
    User user = new User();
    IFactory factory = new SqlServerFactory();
    IUser iu = factory.CreateUser();
    iu.Insert(user);
    iu.GetUser(1);
    Console.Read();
}


// simpleFactory

class DataAccess {
    private static readonly string db = 'SqlServer';
    private static readonly string db = 'AccessServer';

    public static IUser CreateUser() {
        IUser result = null;
        switch(db) {
            case 'SqlServer':
                resule = new SqlServerUser();
                break
            case 'AccessServer':
                result = new AccessUser();
                break;

        }
        return result
    }


    public static IDepartment CreateDepartment() {
        IDepartment result = null;
        switch(db) {
            case 'SqlServer':
                resule = new SqlServerDepartment();
                break
            case 'AccessServer':
                result = new AccessDepartment();
                break;

        }
        return result
    }
}


static void Main(string[] args) {
    User user = new User();
    Department department = new Department();

    IUser iu = DataAccess.CreateUser();

    iu.Insert(user);
    iu.GetUser(1);


    IDepartment idep = DataAccess.CreateUser();

    idep.Insert(department);
    idep.GetUser(1);

    Console.Read();

}