Graedon Beeler
*******
beeler@chapman.edu
CPSC 231-01

Sources:
https://www.baeldung.com/java-compareto
https://social.msdn.microsoft.com/Forums/vstudio/en-US/e16464c8-1b72-4485-9891-94da63c4ec2e/is-it-possible-to-tell-if-a-class-has-been-instantiated?forum=csharpgeneral#:~:text=If%20you%20want%20to%20see,often%20it's%20being%20created%20directly.


Write Up:

Overview of each class/interface:

-Account.java
    Account is an abstract class, meaning it can't be instantiated.
    However, it serves as a base class and framework for the 2 subclasses
    that draw from it, Artist and Listener Account doesn't have many methods, 
    just a toString and an accessor to return the account name.

    -Artist.java
        Artist also doesn't have many methods. It overrides toString to make it display. Its main function is
        for usage when instantiating content, where Artist is a variable/attribute of content(song or podcast)

    -Listener.java
        Listener is an Account for the user. Its main function relates to its unique attribute (separate from Account and Artist) 
        favorites. This allows a user to favorite content, which can be later saved and outputted to a file


-Content.java
    Content is another abstract class. It defines the framework for podcasts and songs, which are very similar but have their own object classes to define their differences. They implement the Comparable interface and contain the compareTo
method which compares two Content objects by the number of times they have been streamed (which increments every time the 
play() method is called)

	-Song.java
			not any different than content, but used to differentiate from a podcast

	-Podcast.java
		Podcast contains an extra member variable, the episode number.

-ContentCollections.java
    ContentCollections contains LinkedLists of Content. These are in the form of
    playlists or albums. ContentCollections implements Comparable, which compares
    the size (number of songs/podcasts) of two ContentCollections

    Playlist.java
        Playlists play a LinkedList of Content. They play it using the shuffle() method,
        which randomly selects the next song in the playlist to play until all songs have
        been played.

    Album.java
        Albums play only Songs in a Content LinkedList. Their play() method plays songs in sequential order

UI.java
    The driver for the program. Continuously gives the user options: Create listener account,
    List Playlists and Albums, Add songs to existing playlist, Shuffle an existing Playlist or listen to an Album,  Add content to favorites,
    or Export favorites 


Diagram:

Account        ContentCollections
    |                   |                 (used as in ContentCollections, Listener as a type in LinkedList)
    |                   |                     Content
    |                   |                          |
   \ /                 \ /                         |
Artist|Listener     Playlist|Album                \ /
                                               Song|Podcast
          
                         UI
                      (Driver)

Using abstract classes is the most reusable and efficient way to achieve this solution. While Accounts,
Content, ContentCollections, aren't tangeable objects that can be instantiated, their subclasses,
which share all the same methods and attributes, but with slight additions and
modifications (overritten)

Challenges:

With a project with so many classes and functions, lots of little issues can arise. If not planned out properly,
the debugging process can be difficult.

Future Features:
An obvious extention to this project would be making it actually be able to play music.
Additionally, it could be extended so thats its user interface is more graphical ie not on the terminal
