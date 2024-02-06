#Richard Graedon Beeler
#2423448
#beeler@chapman.edu
#Assignment 10

playlist = {
    'Playlist Name':"My Playlist:",
    'Song List': []
    #^maps to a list of dictionaries
}

def add_song(playlist):
    name = input("Enter song name: ")
    artist = input("Enter artist: ")
    genre = input("Enter genre: ")
    year = input("Enter year: ")
    song = {
        'Name': name,
        'Artist': artist,
        'Genre':genre,
        'Year': year
    }
    playlist['Song List'].append(song)

def remove_song(playlist):
    while True:
        show_playlist(playlist)
        song_name = input("Enter song to delete: ")
        try:
            for i in playlist['Song List']:
                if i['Name'] == song_name:
                    playlist['Song List'].remove(i)
                    print("Song sucessfully deleted from playlist \n")
                    break
            break
        except:
            print("Error, try again")

def update_song(playlist):
    show_playlist(playlist)
    while True:
        try:
            song_update = int(input("Select index of song to edit: "))
            playlist['Song List'].pop(song_update)
            name = input("Enter song name: ")
            artist = input("Enter artist: ")
            genre = input("Enter genre: ")
            year = input("Enter year: ")
            song = {
                'Name': name,
                'Artist': artist,
                'Genre':genre,
                'Year': year
            }
            playlist['Song List'].insert(song_update,song)
            break
        except:
            print("Invalid index")
            break


def show_playlist(playlist):
   print(playlist["Playlist Name"])
   for i in playlist['Song List']:
        print(i)


print("\nWelcome to playlist editor!")


while True:
    print("\nSelect playlist option: \n1) Add Song\n2) Remove Song\n3) Update Song\n4) Show Playlist\n5) Quit \n")
    try:
        selection = int(input())
        if selection == 1:
            add_song(playlist)
        elif selection == 2:
            remove_song(playlist)
        elif selection == 3:
            update_song(playlist)
        elif selection == 4:
            show_playlist(playlist)
        elif selection == 5:
            print("Goodbye!")
            break
    except:
        print("Invalid selection, please try again.")
       