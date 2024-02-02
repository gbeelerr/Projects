import java.util.LinkedList;
import java.util.Collections;
public class Listener extends Account {

    protected LinkedList<Content> m_favorites;
   
   
    public Listener(String name){
        super(name);
        this.m_favorites = new LinkedList<Content>();
    }

    public void favorite(Content c){
        this.m_favorites.add(c);
        Collections.sort(this.m_favorites);
    }

    public LinkedList<Content> getFavorites(){
        return this.m_favorites;
    }

    public void printFavorites(){
        System.out.println("Favorites:");
        for (Content c: this.m_favorites){
            System.out.println(c + " | Streams: " + c.getStreams());
        }
    }
    
}
