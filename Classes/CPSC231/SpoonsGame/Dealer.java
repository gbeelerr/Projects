//Dealer.java
//Graedon Beeler
//beeler@chapman.edu

/*
 * Object that works directly with Deck object to deal multiple cards
 * One member variable m_Deck of type Deck
 */
import java.util.LinkedList;

public class Dealer {
    
    private Deck m_Deck;

    //Default (and only) constructor
    public Dealer() {
        m_Deck = new Deck();
    }

    //appended Dealer for spoons
    public Dealer(Deck passedDeck){
        this.m_Deck = passedDeck;

    }

    //uses deal method of Deck class to deal n amount of cards and print them out,
    //removing those cards from the current deck m_Deck
    public LinkedList<Card> deals (int n){
        LinkedList<Card> dealtCards = new LinkedList<Card>();
        if(this.m_Deck.size() == 0){
        return dealtCards;
        }else{
            if (this.m_Deck.size() != 0){
            for (int i = 0; i < n; ++i){
                dealtCards.add(this.m_Deck.deal());
            }
            }
            return dealtCards;
        }
    }

    //toString
    //uses Deck toString which uses LinkedList toString()
    public String toString(){
        return this.m_Deck.toString();
    }

//returns number of cards in current deck
//uses Deck size() method which uses LinkedList size()
    public int size(){
        return this.m_Deck.size();
    }
}
