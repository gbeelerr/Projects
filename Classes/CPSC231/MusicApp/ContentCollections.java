import java.util.Random;
import java.util.LinkedList;

public abstract class ContentCollections implements Comparable<ContentCollections>{
    protected String m_title;
    protected LinkedList<Content> contentList;
    protected int itemsInList;

    public ContentCollections(String title, LinkedList<Content> content){
        this.m_title = title;
        this.contentList = new LinkedList<Content>(content);
        this.itemsInList = content.size();
    }
    
    public void shuffle(){
        Random rand = new Random();
        LinkedList<Content> contentCopy = new LinkedList<Content>(contentList);
        int selectedContent;
        for (int i = 0; i < contentList.size(); i++){
            selectedContent = rand.nextInt(contentCopy.size());
            contentCopy.get(selectedContent).play();
            contentCopy.remove(selectedContent);
        }
        
    }
    public void play(){
        for (Content c: contentList){
            c.play();
        }
    }
    public int compareTo(ContentCollections otherCollection){
        return otherCollection.itemsInList - this.itemsInList;
    }

    public LinkedList<Content> getContent(){
        return this.contentList;
    }

    public String getTitle(){
        return this.m_title;
    }

    public String toString(){
        String contentsOfCollection = "";
        for (int i = 0; i < this.itemsInList; i++){
            contentsOfCollection += (" " + (i+1) + ". " + this.contentList.get(i).toString() + "\n");
        }
        return this.getClass().getSimpleName() + " Name: " + this.m_title +  "\n" + contentsOfCollection;
       }

}
