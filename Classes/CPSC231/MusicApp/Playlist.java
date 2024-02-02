import java.util.LinkedList;

public class Playlist extends ContentCollections{
    
    public Playlist(String title, LinkedList<Content> content){
        super(title,content);
    }

   public void add(Content c){
    this.contentList.add(c);
    this.itemsInList++;
   }

   public void remove(int index){
    this.contentList.remove(index);
    this.itemsInList --;
   }
   public void remove(Content c){
    this.contentList.remove(c);
    this.itemsInList --;
   }

   @Override
   public void play(){
    this.shuffle();
   }
   
}
