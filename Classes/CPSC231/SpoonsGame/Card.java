//Card.java
//Graedon Beeler
//beeler@chapman.edu

/*
*Defines object Card which has the attributes of suit and value, both stored as integers
*private member variable m_cardVal which holds current card's value, stored as an int
*private member variable m_suitVal which holds current card's suit, stored as an int
*static constants that define ints JACK, QUEEN, KING, and ACE as the card values 11,12,13, and 14, respectively
*(note that an ACE card is strictly 14 rather than a varying value)
*static constants that define integer values for suits
-Hearts is 0, Spades is 1, Clubs is 2, and Diamonds is 3
 */
public class Card{

    //card values
    private int m_cardVal;

    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;

    //suits
    private int m_suitVal;

    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;

    //default constructor
    public Card(){
        this.m_cardVal = ACE;
        this.m_suitVal = SPADES;
    }

    //overloaded constructor
    public Card(int val, int suit){
        if ((val>=2 && val<=14) && (suit >= 0 && suit <= 3)){
            this.m_cardVal = val;
            this.m_suitVal= suit;
        
        }else{
            
            this.m_cardVal = ACE;
            this.m_suitVal = SPADES;
        }
    }

    //copy constructor
    public Card(Card cardToCopy){
        this.m_cardVal = cardToCopy.m_cardVal;
        this.m_suitVal = cardToCopy.m_suitVal;
    }

    //just val (for comparison)
    
    

    //accessors
    public int getValue(){
        return this.m_cardVal;
    }
    public int getSuit(){
        return this.m_suitVal;
    }

    //mutators
    public void setValue(int newVal){
        if (newVal >= 2 && newVal <= 14){
        this.m_cardVal = newVal;
        }
    }
    public void setSuit(int newSuit){
        if (newSuit >= 0 && newSuit <= 3){
        this.m_suitVal = newSuit;
        }
    }

    //toString
    //in format "Value of Suit"
    public String toString(){
        String printCard = "";
        switch(this.m_cardVal){
            case 11: printCard += "Jack";
                    break;
            case 12: printCard += "Queen";
                    break;
            case 13: printCard += "King";
                    break;
            case 14: printCard += "Ace";
                    break;
            default: printCard += Integer.toString(this.m_cardVal);
                    break;
        }
        printCard += " of ";
        switch(this.m_suitVal){
            case 0: printCard += "Hearts";
                    break;
            case 1: printCard += "Spades";
                    break;
            case 2: printCard += "Clubs";
                    break;
            case 3: printCard += "Diamonds";
                    break;
            default: printCard += "Invalid Suit";
                    break;
        }
        return printCard;
    }

    //equals
    //two Cards are equal if they have the same Card value
    //note (suit is ignored)
    public boolean equals(Object o){
        if (!(o instanceof Card)) {
            return false;
        } else {
            Card otherCard = (Card) o;
            return this.m_cardVal == otherCard.m_cardVal;
    }
}

}