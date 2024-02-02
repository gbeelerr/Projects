

public class Artist extends Account{

    public Artist(String name){
        super(name);
    }

    public Artist(Artist a){
        super(a);
    }
    
    @Override
    public String toString(){
        return "Artist: " + this.m_userID;
    }
}
