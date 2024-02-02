//SpoonsDriver.java
//Graedon Beeler
//beeler@chapman.edu
//2423448
import java.util.LinkedList;

public class SpoonsDriver {
    public static void main(String[] args) {
        /*LinkedList<Card> testHand = new LinkedList<Card>();
        testHand.add(new Card(3, Card.HEARTS));
        testHand.add(new Card(3, Card.SPADES));
        testHand.add(new Card(8, Card.DIAMONDS));
        testHand.add(new Card(9, Card.HEARTS));
        Player p1 = new Player(1, testHand);
        System.out.println(p1.getHand());
        System.out.println(p1.getMatches());
        System.out.println(p1.getHighestMatch());
        System.out.println(p1.takeTurn(new Card(3, Card.CLUBS)));
        Player p2 = new Player(2, new Dealer());
        System.out.println(p2.getHand());
        p2 = p1;
        System.out.println(p2.getHand());
        */
        Game spoons = new Game(5);
        System.out.println(spoons.play());

    }
}
