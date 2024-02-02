//Graedon Beeler
//beeler@chapman.edu
//2423448
//Player.java
//Defines properties and methods for each player
//takes turn and defines logic of what card to pass along
//takes spoon when a number match of all 4 cards occurs 

import java.util.Random;
import java.util.LinkedList;

public class Player {

    private int playerNum;
    private LinkedList<Card> hand = new LinkedList<Card>();
    private boolean hasSpoon;
    private int matches;
    private int HighestMatchedCards;
    private Card match1;
    

    public Player(int player, Dealer dealer) {
        this.playerNum = player;
        this.hand = dealer.deals(4);
        matchCheck();
    }

    public Player(int player, LinkedList<Card> hand) {
        this.playerNum = player;
        this.hand = hand;
        this.matches = 0;
        this.HighestMatchedCards = 0;
        matchCheck();
    }

    public int getPlayerNum() {
        return this.playerNum;
    }

    public boolean hasSpoon() {
        return this.hasSpoon;
    }

    public LinkedList<Card> getHand() {
        return this.hand;
    }

    public int getMatches() {
        return this.matches;
    }

    public int getHighestMatch() {
        return this.HighestMatchedCards;
    }

    /*
     * Cases
     * 1. no matches, card doesn't match any card
     * even probability of any card getting passed
     * 
     * 2.no matches, card matches one of the cards in hand
     * keep that card, random other card gets discarded
     * 
     * 3. 1 or more matches, card matches card in hand
     * if theres one match of two already, and the card matches another, discard the
     * "odd one out"
     * if theres already a match of 3, discard currently passed in card
     * if theres two matches of two, input the card that matches one of the two and
     * discard one of the two "odd ones out"
     * 
     * 4. 1 or more matches, card matches no hand cards
     * -just discard that card
     */
    public Card takeTurn(Card passedCard){
        Random randy = new Random();
        int matchingExisting = 0; //counter for how many cards the new card matches
        int indexMatch = -1;
        for (int i = 0; i < 4; i++){ //for every card in the deck
            if(passedCard.equals(hand.get(i))){ //if the new card equals the card in the hand at index i
                matchingExisting++;
                indexMatch = i;
              //  System.out.println(matchingExisting + " " + indexMatch);
            }
        }
        if (matchingExisting == 0 && this.matches == 0 ){ //if it doesn't match any cards, and no cards match with themselves
            if (randy.nextBoolean() == false){
                return passedCard;
            }else{
                int randIndex = randy.nextInt(4);
                Card tempRand = this.hand.remove(randIndex);
                this.hand.add(passedCard);
                return tempRand;
            }
        
       // System.out.println(hand.indexOf(passedCard));
        } else if (this.matches == 0 && matchingExisting > 0){
            this.matches ++;
            this.HighestMatchedCards = 2;
            this.match1 = new Card(this.hand.get(indexMatch));
           for (int i = 0; i < 4; i++ ){
            if(!passedCard.equals(this.hand.get(i))){
                Card temp = this.hand.remove(i);
                this.hand.add(passedCard);
                return temp;
            }
           }
            
        } else if (this.matches > 0 && matchingExisting > 0){
            if (this.matches == 2){ //if there are currently two matches of two, discard one of the ones that doesn't match the new card
                for (int i = 0; i < 4; i++ ){
                    if((!passedCard.equals(this.hand.get(i))) /*&&(!)*/){ //combine later
                        Card temp = this.hand.remove(i);
                        this.hand.add(passedCard);
                        this.HighestMatchedCards ++;
                        checkSpoon();
                        return temp;
                    }
                 }
            }else{ //matches == 1: cases: one match of two card matches one of the other two (take the two matches), matches 3 of a kind (spoon), matches 4th card when theres already a three of a kind (return passedCard)
                if(this.HighestMatchedCards == 3 && matchingExisting == 1){
                    return passedCard;

                     }else if(this.matches == 1 && matchingExisting == 1 && this.HighestMatchedCards == 2){
                    //cant discard current match or card that matches new card
                    for (int i = 0; i<4; i++){
                        if((!passedCard.equals(this.hand.get(i))) && (!this.match1.equals(this.hand.get(i)))){
                            Card temp = this.hand.remove(i);
                            this.hand.add(passedCard);
                            this.matches ++;
                            checkSpoon();
                            return temp;
                        }
                    }
                
                }else{
                    for (int i = 0; i < 4; i++ ){
                        if((!passedCard.equals(this.hand.get(i)))){
                            Card temp = this.hand.remove(i);
                            this.hand.add(passedCard);
                            this.HighestMatchedCards ++;
                            checkSpoon();
                            return temp;
                        }

                    }
                }
            }
        } else if ((this.matches > 0 && matchingExisting == 0 )||this.matches == 4){
            return passedCard;
        }

        return (new Card(14, 1));
        
      
       
    }


    private void checkSpoon() {
        if (this.HighestMatchedCards == 4) {
            this.hasSpoon = true;
            System.out.println("Player took spoon");
        }
    }

    /*
     * Process:
     * Loop through hand
     * For every card:
     * -Loop through the rest of the deck to check for matches to that card
     * -If a match is found
     * -If this.matches is currently 0:
     * -increment matches to one
     * -make highest number of matched cards 2
     * -If this.matches is more than 0(can only be one if its still looping):
     * -check if the new matching card is the same as the other match
     * -If it is matching:
     * -this.matches stays the same and highestMatch +=1 (only the first time)
     * -if highestMatch == 4 --> take a spoon
     * -If its a new match (ie it doesn't match the previous matching cards' number)
     * -this.matches += 1 and highestMatch is still (2)
     * 
     */
    private void matchCheck() {
        Card tempCard = new Card(this.hand.get(0));
        int comparei = 0;
        for (int i = 0; i < 4; i++) { // for every card
            for (int j = i + 1; j < 4; j++) { // for every next card (loop through remaining hand)
                if (this.hand.get(i).equals(this.hand.get(j))) { // if card i and j are the same value
                    if (this.matches == 0) { // if there are currently no mathces, increment matches by one, and make
                                             // the number of matching cards 2
                        this.matches++;
                        this.HighestMatchedCards = 2;
                        this.match1 = new Card(this.hand.get(i));
                        tempCard = this.hand.get(i);
                        comparei = i;
                    } else if (tempCard.equals(this.hand.get(i))) {
                        if (i == comparei) {
                            this.HighestMatchedCards++;
                            checkSpoon();
                            ;
                        }

                    } else {
                        this.matches++;
                        tempCard = this.hand.get(i);
                    }

                }
            }
        }
    }

    public void stealSpoon() {
        this.hasSpoon = true;
        System.out.println("Player stole a spoon");
    }

}
