

public abstract class Account {
    protected String m_userID;

    public Account(String name){
        this.m_userID = name;
    }

    public Account(Account a){
        this.m_userID = a.m_userID;
    }
    public String getUser(){
        return this.m_userID;
    }

    public String toString(){
        return "User: " + this.m_userID;
    }

}
