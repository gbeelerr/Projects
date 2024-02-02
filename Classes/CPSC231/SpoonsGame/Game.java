//Graedon Beeler
//2423448
//beeler@chapman.edu
//Game.java
//implements player and all other dependent classes to create a spoons game that returns the loser
// (or the only player to not have a spoon at the end of the round)

import java.util.LinkedList;
import java.util.Random;

public class Game {
    private Player[] players;
    private Dealer dealer;
    private LinkedList<Card> discardPile = new LinkedList<Card>();
    private int nSpoons;

    public Game() {
        this.dealer = new Dealer();
        this.players = new Player[4];
        for (int i = 0; i < players.length; ++i) {
            Player player = new Player(i, this.dealer);
            players[i] = player;
        }
       this.nSpoons = 3;
    }

    public Game(int nPlayers) {
        this.dealer = new Dealer();
        this.players = new Player[nPlayers];
        for (int i = 0; i < this.players.length; ++i) {
            Player player = new Player(i, this.dealer);
            this.players[i] = player;
        }
        this.nSpoons = nPlayers - 1;
    }

    public Player[] getPlayers() {
        return this.players;
    }

    public Dealer getDealer() {
        return this.dealer;
    }

    public int getSpoons() {
        return this.nSpoons;
    }

    public int play() { // returns "the loser" who didn't end up with a spoon
        Random randy = new Random();
        Card passedCard;
        while (this.nSpoons > 0) {

            if (this.nSpoons < this.players.length - 1 && this.players[0].hasSpoon() == false) { // if a spoon has already been taken and the player does not yet have a spoon
                if (randy.nextInt(100) <= 33) { // 33% chance of being true
                    this.players[0].stealSpoon();
                    this.nSpoons--;
                    System.out.println(getSpoons());
                    if (this.nSpoons == 0){
                        break;
                    }
                }
            }
           
            if(this.dealer.size() == 0){
                Deck reload = new Deck(this.discardPile);
                System.out.println(reload);
                this.dealer = new Dealer(reload);
                this.discardPile.clear();
            }

            LinkedList<Card> deck = dealer.deals(1);
            Card next = deck.getFirst();

            boolean p1HasCardBeforeTurn = this.players[0].hasSpoon();
            passedCard = new Card(this.players[0].takeTurn(next));
            System.out.println(passedCard);
            boolean p1HasCardAfterTurn = this.players[0].hasSpoon();

            if (!p1HasCardBeforeTurn && p1HasCardAfterTurn) {
                nSpoons--;
            }
            for (int i = 1; i < this.players.length; i++) {
                if (this.nSpoons < this.players.length - 1 && this.players[i].hasSpoon() == false) { // if a spoon has already been taken
                    if (randy.nextInt(100) <= 33) { // 33% chance of being true
                        this.players[i].stealSpoon();
                        this.nSpoons--;
                        System.out.println(nSpoons);
                        if (this.nSpoons == 0) {
                            break;
                        }
                    }
                }
                boolean hasCardBefore = this.players[i].hasSpoon();
                passedCard = this.players[i].takeTurn(passedCard);
                System.out.println(passedCard);
                boolean hasCardAfter = this.players[i].hasSpoon();
                if (!hasCardBefore && hasCardAfter) {
                    nSpoons--;
                }
                if (i == this.players.length - 1) { // if its the last person, put the discarded card in the discard  pile
                    this.discardPile.add(passedCard);
                }
            }
        }
        for (Player player : players) {
            if (player.hasSpoon() == false) {
                return player.getPlayerNum();
            }
        }
        return -1;
    }
}
