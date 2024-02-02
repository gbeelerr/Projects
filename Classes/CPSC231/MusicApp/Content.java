


public abstract class Content implements Comparable<Content> {
    protected int m_streams;
    protected String m_title;
    protected Artist m_artist;

    public Content(String title, String artist){
        this.m_title = title;
        this.m_artist = new Artist(artist);
        this.m_streams = 0;
    }

   
    public Content(String title, Artist a){
        this.m_title = title;
        this.m_artist = new Artist(a);
    }
    public void play(){
        this.m_streams++;
        System.out.println("Now playing:\n" + this.toString() + "\n-o--------" );
    }
    public String getTitle(){
        return this.m_title;
    }
    public int getStreams(){
        return this.m_streams;
    }
    public int compareTo(Content otherContent){
        return otherContent.m_streams - this.m_streams;
    }
    public String toString(){
        return this.m_title + " | " + this.m_artist.toString();
    }
}
