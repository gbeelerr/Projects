import java.util.LinkedList;

public class Album extends ContentCollections {
    
    public Album(String title,LinkedList<Song> songs){
        super(title, new LinkedList<Content>(songs));
        
        
    }
}
