import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Scanner;

import java.util.Collections;

import java.util.ArrayList;
import java.util.LinkedList;
import java.io.IOException;
import java.io.PrintWriter;

public class UI {

    public static void main(String[] args) {
        ArrayList<ContentCollections> contents = new ArrayList<ContentCollections>();
        Playlist defaultPlaylist = new Playlist("Default Playlist", new LinkedList<Content>());
        Song defaultSong = new Song("Any Way You Want It", "Journey");
        defaultPlaylist.add(defaultSong);
        defaultPlaylist.add(new Song("Pon de Replay", "Rihanna"));
        defaultPlaylist.add(new Podcast("The Joe Rogan Experience", "Joe Rogan", 1556));
        Artist mj = new Artist("Michael Jackson");
        Album thriller = new Album("Thriller", new LinkedList<Song>(){{
            add(new Song("Wanna Be Startin' Somethin'", mj));
            add(new Song("Baby Be Mine", mj));
            add (new Song("The Girl Is Mine (with Paul McCartney)", mj));
            add(new Song("Thriller", mj));
            add (new Song("Beat It", mj));
            add(new Song("Billie Jean", mj));
            add(new Song("Human Nature", mj));
            add(new Song("P.Y.T (Pretty Young Thing)", mj));
            add(new Song("The Lady in My Life", mj));
        }});
        contents.add(defaultPlaylist);
        contents.add(thriller);
        contents.add(new Playlist("User Playlist", new LinkedList<Content>()));
        Collections.sort(contents);
        
        System.out.println("Welcome to MP Music App!\n " +
                "\n Menu:\n" +
                " 1. Create listener account\n" +
                " 2. List Playlists and Albums\n" +
                " 3. Add songs to existing playlist\n" +
                " 4. Shuffle an existing Playlist or listen to an Album\n" +
                " 5. Add content to favorites\n" +
                " 6. Export favorites\n" +
                " 7. Exit\n");

        Scanner scan = new Scanner(System.in);
        int selection = 0;
        Listener listener = null;
        do {
            try {
                selection = scan.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Enter an integer value for selection");
                scan.nextLine();
                continue;
            }

            switch (selection) {
                case 1:
                    listener = UI.optionOne(scan, listener);
                    break;

                case 2:
                    UI.optionTwo(scan, contents);
                    break;
                case 3:
                    UI.optionThree(scan, contents);
                    break;
                case 4:
                    UI.optionFour(scan, contents);
                    break;
                case 5:
                    UI.optionFive(scan, listener, contents);
                    break;
                case 6:
                    UI.optionSix(listener);
                    break;
                case 7:
                    break;
                default:
                    System.out.println("Invalid Selection; Enter a number between 1 and 7");
                    break;

            }

            System.out.println(  "\n Menu:\n" +
                " 1. Create listener account\n" +
                " 2. List Playlists and Albums\n" +
                " 3. Add songs to existing playlist\n" +
                " 4. Shuffle an existing Playlist or listen to an Album\n" +
                " 5. Add content to favorites\n" +
                " 6. Export favorites\n" +
                " 7. Exit\n");
            // selection = scan.nextInt();
        } while (selection != 7);
        scan.close();
    }

    public static Listener optionOne(Scanner scan, Listener listener) {
        System.out.println("Enter your user ID:");
        scan.nextLine();
        String name = scan.nextLine();
        listener = new Listener(name);
        System.out.println(listener.toString());
        return listener;
    }

    public static void optionTwo(Scanner scan, ArrayList<ContentCollections> contents) {
        Collections.sort(contents);
        for (ContentCollections cc : contents) {
            System.out.println(cc);

        }
    }

    public static void optionThree(Scanner scan, ArrayList<ContentCollections> contents) {
        Collections.sort(contents);
        for (int i = 0; i < contents.size(); i++) {
            if (contents.get(i) instanceof Playlist) {
                System.out.println(" " + (i + 1) + ". " + contents.get(i).getTitle());
            } else {
                System.out.println(" " + (i + 1) + " (not playlist)");
            }
        }
        System.out.println("Select number playlist to add content:");
        int playlistAdd = 0;
        try {
            playlistAdd = scan.nextInt();
            if (playlistAdd - 1 > contents.size() || playlistAdd - 1 < 0){
                throw new IndexOutOfBoundsException("Invalid playlist number.");
            }
            if(!(contents.get(playlistAdd - 1) instanceof Playlist)){
                throw new IndexOutOfBoundsException("That item is not a playlist");

            }
            System.out.println("Enter 1 to add song and 2 to add podcast:");
            int songOrPodcast = scan.nextInt();
            if (songOrPodcast != 1 && songOrPodcast != 2) {
                throw new IndexOutOfBoundsException("You didn't enter 1 or 2 to add content!");
            }
            System.out.println("Enter song/podcast title:");
            scan.nextLine();
            String title = scan.nextLine();
            System.out.println("Enter artist:");
            String artist = scan.nextLine();
           
            if (songOrPodcast == 1) {
                Content songAdd = new Song(title, artist);
                Playlist selectedPlaylist = (Playlist) contents.get(playlistAdd - 1);
                selectedPlaylist.add(songAdd);
            } else if (songOrPodcast == 2) {
                System.out.println("Enter podcast episode:");
                int episode = scan.nextInt();
                Podcast podcastAdd = new Podcast(title, artist, episode);
                Playlist selectedPlaylist = (Playlist) contents.get(playlistAdd - 1);
                selectedPlaylist.add(podcastAdd);
            } 
                
            
        }catch(IndexOutOfBoundsException e){
        System.out.println(e.getMessage());
        
        } catch (Exception e) {
            System.out.println("Playlist number or song/podcast selection must be integer numbers");
        }
    }

    public static void optionFour(Scanner scan,ArrayList<ContentCollections> contents){
        UI.optionTwo(scan, contents);
        try{
        System.out.println("Select name of album or playlist to listen to");
        scan.nextLine();
        String nameSelect = scan.nextLine();
        boolean foundSong = false;
        for (ContentCollections cc : contents){
            if (cc.getTitle().toLowerCase().equals(nameSelect.toLowerCase())){
                foundSong = true;
               cc.play();
            }
        }
        if (foundSong == false){
            throw new Exception();
        }
    }catch(Exception e){
        System.out.println("Playlist or album name not found!");

    }
    }



    public static void optionFive(Scanner scan, Listener listener, ArrayList<ContentCollections> contents) {

        if (listener != null) {
            System.out.println(listener.toString());
            for (ContentCollections cc : contents){
                for (Content c : cc.getContent()){
                    System.out.println(c);
                }
            }
            System.out.println("Select name of song or podcast to add:");
            scan.nextLine();
            String songPodName = scan.nextLine();
            boolean addedFavorite = false;
            for (ContentCollections cc : contents) {
                for (Content c : cc.getContent()) {
                    if (c.getTitle().toLowerCase().equals(songPodName.toLowerCase())) {
                        listener.favorite(c);
                        addedFavorite = true;
                    }
                }
            }
            if (addedFavorite == false) {
                System.out.println("Could not find content matching that name.");
            }
            listener.printFavorites();

        } else {
            System.out.println("Listener account must be made to create list of favorites");
        }
    }

    public static void optionSix(Listener listener){
    
        try{
        if (listener != null){
            PrintWriter writer = new PrintWriter("favorites.txt");
            writer.println(listener.toString() + "\nFavorites:");
            for (Content c: listener.getFavorites()){
                writer.println(c + " | Streams: " + c.getStreams());
            }
            writer.close();
        }else{
            throw new NullPointerException("A listener account has not been created yet.");
        }


    }catch(IOException e){
        System.out.println("File error!");
    }catch(NullPointerException e){
        System.out.println(e.getMessage());

    }
    }

}
