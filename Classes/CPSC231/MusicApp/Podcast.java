

public class Podcast extends Content {
    
    protected int m_episodeNumber;

    public Podcast (String title, String artist, int episodeNumber){
        super(title,artist);
        this.m_episodeNumber = episodeNumber;
    }

    @Override
    public String toString(){
        return this.m_title + ", Episode " + this.m_episodeNumber + " by " + this.m_artist;
    }

}
