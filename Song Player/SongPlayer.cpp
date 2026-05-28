//Title: SongPlayer.cpp
//Author: Tahmid Khan
//Date: 11/23/2025
//Description: Loads the catalog, lets the user search songs, manages the playlist, and handles menu options


using namespace std;
//Includes the SongPlayer header file
#include "SongPlayer.h"
#include <limits>
#include <iostream>
#include <fstream>

//Constructor that initializes the filename and playlist
SongPlayer::SongPlayer() {
  m_filename = FILE_NAME;
}

//Constructor that also initializes the filename and playlist
SongPlayer::SongPlayer(string filename) {
  m_filename = filename;
 
}


//Destructor that deletes the playlist and clears the song catalog
SongPlayer::~SongPlayer() {
  
  //Deletes each song in the song catalog
  for(unsigned int i = 0; i < m_songCatalog.size(); i++) {
    delete m_songCatalog[i];
  }
  m_songCatalog.clear();
}

//Converts a string to lowercase
string SongPlayer::ToLower(string word) {
  //Converts each character in the string to lowercase
  for(unsigned int i = 0; i < word.length(); i++) {
    word[i] = tolower(static_cast<unsigned char>(word[i]));
  }
  return word;
}

//Loads the song catalog from the file
void SongPlayer::LoadCatalog() {
  m_songCatalog.clear();
  //Opens the file and reads each line
  ifstream input(m_filename.c_str());
  if(!input.is_open()) {
    cout << "Could not open file " << m_filename << endl;
    return;
  }
  //Reads each line and creates a new song object
  string title, album, artist;
  string spotifyStr, ytStr, ttStr;
  while(getline(input, title, '|')) {
    //Reads the rest of the line and creates a new song object
    if(getline(input, album, '|') && getline(input, artist, '|') && getline(input, spotifyStr, '|') && getline(input, ytStr, '|') && getline(input, ttStr)) {
      //Converts the string to a long and creates a new song object
      long spotify = stol(spotifyStr);
      long yt = stol(ytStr);
      long tt = stol(ttStr);
      Song* song = new Song(title, album, artist, spotify, yt, tt);
      m_songCatalog.push_back(song);
    } else {
      //If the line is not formatted correctly, it skips the line
      title = "";
      album = "";
      artist = "";
      spotifyStr = "";
      ytStr = "";
      ttStr = "";
      continue;
    }
  }
  input.close();
}

//Displays the main menu and handles user input
void SongPlayer::MainMenu() {
  int choice = 0;
  while(choice != 5) {
    cout << "What would you like to do?" << endl;
    cout << "1. Display Song by Title, Artist, and Album" << endl;
    cout << "2. Add Song to Playlist" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Sort Playlist by Spotify Streams" << endl;
    cout << "5. Quit" << endl;
    cout << "What would you like to do? " << endl;
    cin >> choice; 
    //If the input is not an integer, it clears the input and prompts the user again
    if(cin.fail()) {
      cin.clear();
      //Ignores the rest of the line
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> choice;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //Handles the user's choice
    switch (choice) {
      case 1:
        DisplaySong();
        break;
      case 2:
        AddSong();
        break;
      case 3:
        DisplayPlaylist();
        break;
      case 4:
        SortPlaylist();
        break;
      case 5:
        cout << "Thank you for using the UMBC Song Player!" << endl;
        break;
    }
  }
}

//Displays the search options and handles user input
int SongPlayer::SearchOptions() {
  int option;
  cout << "Would you rather search by artist or title?" << endl;
  cout << "1. Artist" << endl;
  cout << "2. Title" << endl;
  cin >> option;
  //If the input is not an integer, it clears the input and prompts the user again
  while (!cin||(option != 1 && option != 2)) {
    cin.clear();
    //Ignores the rest of the line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Choice. Please enter 1 for artist or 2 for title: " << endl;
    cin >> option;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return option;
}

//Displays the search type and handles user input
string SongPlayer::SearchType(string type) {
  cout << "Which "<< type << " would you like to display?"<< endl;
  string search;
  //Gets the search term from the user
  getline(cin, search);
  return ToLower(search);
}

//Displays the songs in the catalog and handles user input
int SongPlayer::DisplaySong() {
  //If the song catalog is empty, it displays a message and returns 0
  if (m_songCatalog.empty()) {
    cout << "No songs in catalog." << endl;
    return 0;
  }
  int option = SearchOptions();
  //Gets the search term from the user
  string type = option == 1 ? "artist" : "title";
  string search = SearchType(type);
  cout << "SONGS TOTAL: " << m_songCatalog.size() << endl;
  int count = 0;
  //Displays the songs that match the search term
  for(unsigned int i = 0; i < m_songCatalog.size(); i++) {
    Song* song = m_songCatalog[i];
    //Converts the artist or title to lowercase and checks if it contains the search term
    string field = (option == 1) ? ToLower(song->GetArtist()) : ToLower(song->GetTitle());
    //If the field contains the search term, it displays the song and increments the count
    if(field.find(search) != string::npos) {
      cout << i << " " << song -> GetTitle() << " by " << song->GetArtist() << " from " << song->GetAlbum() << endl;
      count++;
    }
  }
  cout << count << " songs found." << endl;
  return count;
}

//Adds a song to the playlist and handles user input
void SongPlayer::AddSong() {
  //If the song catalog is empty, it displays a message and returns
  if(m_songCatalog.empty()) {
    cout << "No songs in catalog." << endl;
    return;
  }
  //Displays the songs in the catalog and gets the index of the song to add
  DisplaySong();
  cout << "Enter the number of the song you would like to add: " << endl;
  int index;
  cin >> index;
  //If the input is not an integer, it clears the input and prompts the user again
  if(!cin) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input" << endl;
    return;
  }
  //If the index is out of range, it displays a message and returns
  if(index < 0 || index >= static_cast<int>(m_songCatalog.size())) {
    cout << "Song choice out of range" << endl;
    return;
  }
  //Adds the song to the playlist and displays the details of the song
  Song* chosen = m_songCatalog[index];
  m_playList.PushBack(chosen);
  cout << chosen -> GetTitle() << " by " << chosen->GetArtist() <<" from "<< chosen->GetAlbum()<< " added to playlist." << endl;
}


//Displays the songs in the playlist
void SongPlayer::DisplayPlaylist() {
  //If the playlist is empty, it displays a message and returns
  if(m_playList.IsEmpty()) {
    cout << "Playlist is empty." << endl;
    return;
  }
  //Using Queue's copy constructor to create a temporary queue
  Queue<Song*> temp(m_playList);
  while (!temp.IsEmpty()) {
    Song* song = temp.PopFront();
    cout << *song << endl;
  }
}

//Sorts the playlist by Spotify streams
void SongPlayer::SortPlaylist() {
  //If the playlist has fewer than 2 songs, it will not sort
  if(m_playList.GetSize() < 2) {
    cout << "Playlist has fewer than 2 songs, nothing to sort." << endl;
    return;
  }
  m_playList.Sort();
  cout << "Playlist sorted by Spotify streams." << endl;
}

//Starts the song player and displays the welcome message
void SongPlayer::StartPlayer() {
  LoadCatalog();
  cout << "Welcome to UMBC Song Player" << endl;
  cout << m_songCatalog.size() << " song files loaded." << endl;
  MainMenu();
}
 
