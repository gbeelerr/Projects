

public class Song extends Content{
    
    public Song(String title, String artist){
        super(title,artist);
    }

    public Song(String title, Artist a){
        super(title,a);
    }
   
}
