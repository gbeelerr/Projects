//Deck.java
//Graedon Beeler
//beeler@chapman.edu

/*
 * Creates a new LinkedList of type Card, initializes to a fresh deck of 52 cards, and has the ability to "deal" out a card
 * Member variable m_cards of type LinkedList<Card>
 */
import java.util.LinkedList;
import java.util.Random;

public class Deck {

    private LinkedList<Card> m_cards = new LinkedList<Card>();

    //default constructor; fresh set of 52 cards
    public Deck(){
        for (int i = 0; i <= 3; i++){
            for (int j = 2; j <= 14; j++){
                Card cardToAdd = new Card(); //creates new card object each iteration to add to LinkedList
                cardToAdd.setSuit(i);
                cardToAdd.setValue(j);
                this.m_cards.add(cardToAdd);
            }
        }
    }

    //copy constructor
    public Deck(Deck deckToCopy){
        LinkedList<Card> cardCopy = new LinkedList<Card>();
        for (Card c : deckToCopy.m_cards){
            cardCopy.add(new Card(c)); //deep copy
        }
        this.m_cards = cardCopy;
    }

    public Deck(LinkedList<Card> passedCards){//added later for spoons
        this.m_cards = new LinkedList(passedCards);
    }

    //toString
    //borrows toString() function directky from LinkedList class
    public String toString(){
        return this.m_cards.toString();
    }

    //size method
    //returns number of cards in current deck
    //uses LinkedList size() method
    public int size(){
        return m_cards.size();
    }

    //deal method
    //picks a random index in the deck, returns the card, and removes it from the deck
    public Card deal(){
        if (m_cards.size() == 0){
            return null;
        }else{
        Random randy = new Random();
        int randIndex = randy.nextInt(this.m_cards.size());
        Card dealtCard = this.m_cards.get(randIndex);
        m_cards.remove(randIndex);
        return dealtCard;
        }
       
        
    }
}
