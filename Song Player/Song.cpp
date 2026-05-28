//Title: Song.cpp
//Author: Tahmid Khan
//Date: 11/22/25
//Description: Implementation for Song.cpp it defines how a single Song object is created, stored, printed, and compared so that your music player and playlist can function.

//Includes the Song.h file
#include "Song.h"

//Constructors
Song::Song() {
  m_title = "";
  m_album = "";
  m_artist = "";
  m_spotify = 0;
  m_youtube = 0;
  m_tiktok = 0;
}

//Constructor with parameters this is helpful for creating a song object with specific values
Song::Song(string title, string album, string artist, long spotify, long youtube, long tiktok) {
  m_title = title;
  m_album = album;
  m_artist = artist;
  m_spotify = spotify;
  m_youtube = youtube;
  m_tiktok = tiktok;
}

// Accessors
//These functions allow you to retrieve the values of the private member variables of a Song object.
string Song::GetTitle() const {
  return m_title;
}

//This function returns the album name of the song.
string Song::GetAlbum() const {
  return m_album;
}

//This function returns the artist name of the song.
string Song::GetArtist() const {
  return m_artist;
}

//This function returns the number of Spotify streams for the song.
long Song::GetSpotify() const {
  return m_spotify;
}

//This function returns the number of YouTube views for the song.
long Song::GetYouTube() const {
  return m_youtube;
}

//This function returns the number of TikTok views for the song.
long Song::GetTikTok() const {
  return m_tiktok;
}

// Mutators
//These functions allow you to modify the values of the private member variables of a Song object.
void Song::SetTitle(string title) {
  m_title = title;
}

//This function sets the album name of the song.
void Song::SetAlbum(string album) {
  m_album = album;
}

//This function sets the artist name of the song.
void Song::SetArtist(string artist) {
  m_artist = artist;
}

//This function sets the number of Spotify streams for the song.
void Song::SetSpotify(long spotify) {
  m_spotify = spotify;
}

//This function sets the number of YouTube views for the song.
void Song::SetYouTube(long youtube) {
  m_youtube = youtube;
}

//This function sets the number of TikTok views for the song.
void Song::SetTikTok(long tiktok) {
  m_tiktok = tiktok;
}

//This prints the song title, artist, and album name
ostream& operator<<(ostream& out, Song& m) {
  out << m.m_title << " by " << m.m_artist << " from " << m.m_album;
  return out;
}

//This function compares the number of Spotify streams for two songs and returns true if the current song has fewer Spotify streams than the other song.
bool Song::operator<(const Song& m) {
  return m_spotify < m.m_spotify;
}
