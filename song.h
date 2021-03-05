#include
using namespace std;
#ifndef _SONG_H
#define _SONG_H
enum Style {POP, ROCK, ALTERNATIVE, COUNTRY,
HIPHOP, PARODY};
class Song
{
// operator overload — described at bottom
friend ostream& operator<<(ostream&os, const
Song& s);
public:
Song(); // default constructor,
sets up blank song object
void Set(const char* t, const char* a, Style st,intsz);
// the Set function should allow incoming data tobe received through

// parameters and loaded into the member data ofthe object. (i.e.
// this function “sets” the state of the object
to the data passed in).
// The parameters t, a, st, and sz represent the
title, artist, style,
// and size of the song file, respectively.

const char* GetTitle() const; // returnsthe title stored in the object
const char* GetArtist() const; // returnsthe artist
intGetSize() const; // returns
the file size in kilobytes
Style GetCategory() const; // returnsthe song category
private:
char title[36]; // may assume title is 35characters or less
char artist[21]; // may assume artist nameis 20 characters or less
Style category; // style of the given song
int size; // file size, stored inkilobytes
};
/* operator<< function
The operator<< overload should print out a Song
object on one line (tothe given ostream) — use no more than 80
characters per line – asfollows, in an organized manner. Size should beprinted in Megabytes
(use 1000 kilobytes = 1 MB for this calculation),to 1 decimal place.
The category abbreviations used should be: Pop,Rock, Alt, Ctry, HH, Par
Title Artist
Style Size (MB)
Examples:
Pictures of You The Cure
Alt 4.4
Bohemian Rhapsody Queen
Rock 5.7
What Does the Fox Say Ylvis
Par 12.6
*/
#endif

Solution

Menu.cpp

// An object of type Song will store information about a single

// digitally recorded song file.

#include

#include “song.h”

#include “playlist.h”

#include

using namespace std;

//ShowMenu()

voidShowMenu()

{

cout<< ” *** Playlist Menu *** ” << ‘\n’;

cout<< “\tA or a \tAdd a song to the playlist” << ‘\n’;

cout<< “\tF or f \tFind a song on the playlist” << ‘\n’;

cout<< “\tD or d \tDelete a song from the playlist” << ‘\n’;

cout<< “\tS or s \tShow the entire playlist” << ‘\n’;

cout<< “\tC or c \tCategory summary” << ‘\n’;

cout<< “\tZ or z \tShow playlist size” << ‘\n’;

cout<< “\tM or m \tShow this Menu” << ‘\n’;

cout<< “\tO or o \tsOrt playlist” << ‘\n’;

cout<< “\tX or x \teXit the program” << ‘\n’;

}

//GetChar()

charGetAChar(const char* promptString)

{

char response; // the char to be returned

cout<

cin>> response; // Get a char,

response = toupper(response); // and convert it to uppercase

cin.get(); // Discard newline char from input.

return response;

}

// Legal()

char Legal(char c)

{

return ((c == ‘A’) || (c == ‘F’) || (c == ‘D’) || (c == ‘S’) ||

(c == ‘C’) || (c == ‘Z’) || (c == ‘M’) || (c == ‘X’) ||

(c == ‘a’) || (c == ‘f’) || (c == ‘d’) || (c == ‘s’) ||

(c == ‘c’) || (c == ‘z’) || (c == ‘m’) || (c == ‘x’) ||

(c == ‘O’) || (c == ‘o’));

}

//GetCommand()

charGetCommand()

{

charcmd = GetAChar(“\n\n>”); // Get a command character.

while (!Legal(cmd)) { // As long as it’s not a legal command,display menu and try again.

cout<< “\nIllegal command, please try again . . .” << ‘\n’;

ShowMenu();

cmd = GetAChar(“\n\n>”);

}

returncmd;

}

//GetInput()

voidGetInput(Song& song)

{

char t[36];

char a[21];

Style c;

chartempStyle; //to read in Style

int s = 0;

cout<< “Enter a song title: ” <

cin.getline(t, 36);

cout<< “Enter a song artist: ” <

cin.getline(a, 21);

cout<< “Enter a song category: ” <

cout<< “(P = pop, R = rock, A = alternative, C = country, H = hiphop, Y = parody)” <

cin>>tempStyle;

while (tempStyle != ‘P’ &&tempStyle != ‘p’ &&tempStyle != ‘R’ &&tempStyle != ‘r’ &&

tempStyle != ‘A’ &&tempStyle != ‘a’ &&tempStyle != ‘C’ &&tempStyle != ‘c’ &&

tempStyle != ‘H’ &&tempStyle != ‘h’ &&tempStyle != ‘Y’ &&tempStyle != ‘y’) {

cout<< “Invalid category. Please re-enter: ” <

cin>>tempStyle;

}

if (tempStyle == ‘P’ || tempStyle == ‘p’) {

c = POP;

}

else if (tempStyle == ‘R’ || tempStyle == ‘r’) {

c = ROCK;

}

else if (tempStyle == ‘A’ || tempStyle == ‘a’) {

c = ALTERNATIVE;

}

else if (tempStyle == ‘C’ || tempStyle == ‘c’) {

c = COUNTRY;

}

else if (tempStyle == ‘H’ || tempStyle == ‘h’) {

c = HIPHOP;

}

else if (tempStyle == ‘Y’ || tempStyle == ‘y’) {

c = PARODY;

}

else {

cout<< “Invalid category. Please re-enter: ” <

}

cin.ignore();

while (s <= 0) {

cout<< “Enter a song size (kb): ” <

cin>> s;

if (s <= 0) {

cout<< “Must enter a positive size. Please re-enter: ” <

}

}

song.Set(t, a, c, s);

}

// main()

int main()

{

Playlist p;

char command;

do {

ShowMenu();

Song song;

charlookupString[36];

command = GetCommand();

switch (command) {

case ‘A’:

GetInput(song);

p.Insert(song);

break;

case ‘F’:

cout<< “\tType a SONG TITLE or ARTIST to be searched, followed by : “;

cin.getline(lookupString, 36);

p.Lookup(lookupString); break;

case ‘D’:

cout<< “\nType name to be removed, followed by : “;

cin.getline(lookupString, 36);

p.Remove(lookupString);

break;

case ‘S’:

p.DisplayPlaylist();

p.ShowPlaylistSize();

break;

case ‘C’:

cout<< ” Please enter category: ” << ‘\n’;

cin.getline(lookupString, 36);

p.DisplayPlaylistCategory(lookupString);

; break;

case ‘Z’: p.ShowPlaylistSizeKB(); break;

case ‘M’: ShowMenu(); break;

case ‘O’: p.SortSong(); p.DisplayPlaylist(); break;

case ‘X’: break;

case ‘a’:

GetInput(song);

p.Insert(song);

break;

case ‘f’:

cout<< “\tType a SONG TITLE or ARTIST to be searched, followed by : “;

cin.getline(lookupString, 36);

p.Lookup(lookupString); break;

case ‘d’:

cout<< “\nType name to be removed, followed by : “;

cin.getline(lookupString, 36);

p.Remove(lookupString);

break;

case ‘s’: p.DisplayPlaylist(); break;

case ‘c’:

cout<< ” Please enter category: ” << ‘\n’;

cin.getline(lookupString, 36);

p.DisplayPlaylistCategory(lookupString);

break;

case ‘z’: p.ShowPlaylistSizeKB(); break;

case ‘m’: ShowMenu(); break;

case ‘o’: p.SortSong(); p.DisplayPlaylist(); break;

case ‘x’: break;

default: break;

}

} while (command != ‘X’ && command != ‘x’);

return 0;

} 

Playlist.cpp

#include

#include

#include “playlist.h”

#include

#include

#include

// Default constructer

Playlist::Playlist()

{

maxSize = 5;

currentSize = 0;

songList = new Song[maxSize];

}

// Destructor

Playlist::~Playlist()

{

delete[] songList;

}

// Insert()

void Playlist::Insert(Song& song)

/* since the variables being passed in the */

{

if (currentSize == maxSize) {

Resize();

}

songList[currentSize++] = song; //implicity calls songList[currentSize++]’s defaul constructor before assigning song into that element

}

// Lookup()

void Playlist::Lookup(char* aName) const

{

inttitleEntry = FindSongbyTitle(aName); // Locate the name in the directory.

intartistEntry = FindSongbyArtist(aName); // Locate the name in the directory.

if (titleEntry == -1 &&artistEntry == -1) {

cout<

}

else {

if (titleEntry != -1) {

//at this point, aName, the SONG TITLE found in playlist

cout<< “\nEntry found: “;

cout<

}

if (artistEntry != -1) {

cout<< “\nEntry found: “;

for (int i = 0; i

if (strcmp(songList[i].GetArtist(), aName) == 0) {

cout<

}

}

}

 

}

}

// Remove()

void Playlist::Remove(char* aName)

{

intthisEntry = FindSong(aName); // Locate the name in the directory.

if (thisEntry == -1)

cout<

else {

// Shift each succeding element “down” one position in the

// Entry array, thereby deleting the desired entry.

for (int j = thisEntry + 1; j

songList[j – 1] = songList[j];

currentSize–; // Decrement the current number of entries.

cout<< “Entry removed.\n”;

}

if (maxSize>= currentSize + 6) {

//maxSize

Resize();

}

}

// DisplayPlaylist()

void Playlist::DisplayPlaylist() const

{

if (currentSize == 0) {

cout<< “\nCurrent playlist is empty.\n”;

return;

}

// Display a header.

cout<< “\n\t***Title***\t\t\t***Artist***\t\t***Style***\t\t***Size (MB)***\n\n”;

 

for (int i = 0; i

cout<

}

// DisplayPlaylistCategory()

void Playlist::DisplayPlaylistCategory(char* cat) const

{

intoriginalPrecision = cout.precision();

 

if (currentSize == 0) {

cout<< “\nCurrent playlist is empty.\n”;

return;

}

// Display a header.

cout<< “\n\t***Title***\t\t\t***Artist***\t\t***Style***\t\t***Size (MB)***\n\n”;

doublesumSize(0);

intnumSongs(0);

for (int i = 0; i

Style style = songList[i].GetCategory();

char temp = ‘ ‘;

//P, R, A, C, H, and Y

if (style == POP) {

temp = ‘P’;

}

else if (style == ROCK) {

temp = ‘R’;

}

else if (style == ALTERNATIVE) {

temp = ‘A’;

}

else if (style == COUNTRY) {

temp = ‘C’;

}

else if (style == HIPHOP) {

temp = ‘H’;

}

else if (style == PARODY) {

temp = ‘Y’;

}

else {

cout<< “Invalid category.” << ‘\n’;

}

//at this point cat variable is all uppercase

if (temp == toupper(cat[0])) {

cout<

sumSize += songList[i].GetCategory();

numSongs++;

}

}

cout<< “Total size of playlist: ” <(sumSize / 1000)

<

cout<

}

// Resize()

void Playlist::Resize()

{

maxSize = currentSize + 5;

Song* newList = new Song[maxSize];

for (int i = 0; i

{

newList[i] = songList[i];

}

delete[] songList;

songList = newList;

cout<< “Array is being resized to ” <

}

// FindSongbyTitle()

int Playlist::FindSongbyTitle(char* aName) const

// Locate a name in the directory. Returns the

// position of the entry list as an integer if found.

// and returns -1 if the entry is not found in the directory.

{

for (int i = 0; i

// make both the database song name and search song name uppercase for proper matching

int j = 0;

char* songList_song = const_cast(songList[i].GetTitle());

char c;

while (songList_song[j]) {

c = songList_song[j];

c = toupper(c);

songList_song[j] = c;

j++;

}

int k = 0;

char* search_song = const_cast(aName);

char d;

while (search_song[k]) {

d = search_song[k];

d = toupper(d);

search_song[k] = d;

k++;

}

if (strcmp(songList_song, search_song) == 0) {

return i; // If found, return position and exit.

}

}

return -1; // Return -1 if never found.

}

// FindSongbyArtist()

int Playlist::FindSongbyArtist(char* aName) const

// Locate a name in the directory. Returns the

// position of the entry list as an integer if found.

// and returns -1 if the entry is not found in the directory.

{

for (int i = 0; i

// make both the database song name and search song name uppercase for proper matching

int j = 0;

const char* songList_artist = songList[i].GetArtist();

char* songList_artist2 = const_cast(songList_artist);

char c;

while (songList_artist2[j]) {

c = songList_artist2[j];

c = toupper(c);

songList_artist2[j] = c;

j++;

}

int k = 0;

char* search_artist = aName;

char d;

while (search_artist[k]) {

d = search_artist[k];

d = toupper(d);

search_artist[k] = d;

k++;

}

if (strcmp(songList_artist2, search_artist) == 0)

return i; // If found, return position and exit.

}

return -1; // Return -1 if never found.

}

// FindSong()

int Playlist::FindSong(char* aName) const

// Locate a name in the directory. Returns the

// position of the entry list as an integer if found.

// and returns -1 if the entry is not found in the directory.

{

for (int i = 0; i

if ((strcmp(songList[i].GetTitle(), aName)) == 0 || (strcmp(songList[i].GetArtist(), aName) == 0))

return i; // If found, return position and exit.

}

return -1; // Return -1 if never found.

}

void Playlist::ShowPlaylistSize()

{

intoriginalPrecision = cout.precision();

double sum = 0;

cout<< “Total no. of songs in playlist: ” <

for (int i = 0; i

sum = sum + songList[i].GetSize();

}

cout<< “Total size of playlist: ” <(sum / 1000)

<

cout<< ‘\n’;

}

void Playlist::ShowPlaylistSizeKB()

{

int sum = 0;

for (int i = 0; i

sum = sum + songList[i].GetSize();

}

cout<< “Total size of playlist: ” << sum << ‘\n’;

cout<< ‘\n’;

}

// SortSong()

void Playlist::SortSong()

{

cout<< “\tA or a \tSort playlist via Artist” << ‘\n’;

cout<< “\tT or t \tSort playlist via Title” << ‘\n’;

cout<< “\n> “;

charcmd; // the char to be returned

cin>>cmd; // Get a char,

cmd = toupper(cmd); // and convert it to uppercase

cin.get(); // Discard newline char from input.

if (cmd == ‘A’)

SortSongbyArtist();

else if (cmd = ‘T’)

SortSongbyTitle();

else

cout<< “Invalid input. Back to main menu.”<< ‘\n’;

}

// SortSongbyArtist

void Playlist::SortSongbyArtist()

{

for (int i = 0; i

{

for (int j = i; j

{

if (strcmp(songList[i].GetArtist(), songList[j].GetArtist()) > 0) //need to sort

{

//swap song infomation

Song tempSong;

tempSong.Set(songList[i].GetTitle(), songList[i].GetArtist(), songList[i].GetCategory(), songList[i].GetSize());

songList[i].Set(songList[j].GetTitle(), songList[j].GetArtist(), songList[j].GetCategory(), songList[j].GetSize());

songList[j].Set(tempSong.GetTitle(), tempSong.GetArtist(), tempSong.GetCategory(), tempSong.GetSize());

}

}

}

}

//SortSongbyTitle()

void Playlist::SortSongbyTitle()

{

for (int i = 0; i

{

for (int j = i; j

{

if (strcmp(songList[i].GetTitle(), songList[j].GetTitle()) > 0) //need to sort

{

//swap song infomation

Song tempSong;

tempSong.Set(songList[i].GetTitle(), songList[i].GetArtist(), songList[i].GetCategory(), songList[i].GetSize());

songList[i].Set(songList[j].GetTitle(), songList[j].GetArtist(), songList[j].GetCategory(), songList[j].GetSize());

songList[j].Set(tempSong.GetTitle(), tempSong.GetArtist(), tempSong.GetCategory(), tempSong.GetSize());

}

}

}

}

 Playlist.h

 // An object of type Song will store information about a single

// digitally recorded song file.

#pragma once

#include

#include “song.h”

using namespace std;

class Playlist

{

public:

Playlist();

~Playlist();

void Insert(Song& song);

void Lookup(char* aName) const;

void Remove(char* aName);

voidDisplayPlaylist() const;

voidDisplayPlaylistCategory(char* cat) const;

voidShowPlaylistSize();

voidShowPlaylistSizeKB();

voidSortSong();

private:

intmaxSize;

intcurrentSize;

Song* songList;

void Resize();

intFindSong(char* aName) const;

intFindSongbyTitle(char* aName) const;

intFindSongbyArtist(char* aName) const;

voidSortSongbyTitle();

voidSortSongbyArtist();

}; 

Song.cpp

#include

#include “song.h”

#include

#ifndef _SONG_CPP

#define _SONG_CPP

using namespace std;

// default constructor, sets up blank song object

Song::Song()

{

strcpy(title, ” “);

strcpy(artist, ” “);

size = 0;

}

// Set()

void Song::Set(const char* t, const char* a, Style st, intsz)

{

strcpy(title, t);

strcpy(artist, a);

category = st;

size = sz;

}

// GetTitle()

const char* Song::GetTitle() const

{

return title;

}

// GetArtist()

const char* Song::GetArtist() const

{

return artist;

}

// GetSize()

int Song::GetSize() const

{

return size;

}

// GetCategory()

Style Song::GetCategory() const

{

return category;

}

// Display()

ostream& operator<<(ostream&os, const Song& s)

{

os<< ‘\t’ <

for (int i = strlen(s.GetTitle()) + 1; i < 36; i++)

os.put(‘ ‘);

os<< ‘\t’ <

for (int i = strlen(s.GetArtist()) + 1; i < 21; i++)

os.put(‘ ‘);

//cout<< ‘\t’ << category;

if (s.GetCategory() == 0)

{

os<< ‘\t’ << “Pop”;

}

else if (s.GetCategory() == 1) {

os<< ‘\t’ << “Rock”;

}

else if (s.GetCategory() == 2) {

os<< ‘\t’ << “Alternative”;

}

else if (s.GetCategory() == 3) {

os<< ‘\t’ << “Country”;

}

else if (s.GetCategory() == 4) {

os<< ‘\t’ << “Hip Hop”;

}

else if (s.GetCategory() == 5) {

os<< ‘\t’ << “Parody”;

}

else {

os<< ‘\t’ << “Wrong Input”;

}

os<< ‘\t’ <(static_cast(s.GetSize()) / 1000);

os<< ‘\n’ << ‘\n’;

returnos;

}

#endif 

Song.h

#pragma once

// An object of type Song will store information about a single

// digitally recorded song file.

// The variable “category” stores the category of the song

// (one of the six items in the enumerated type Style).

#include

using namespace std;

#ifndef _SONG_H

#define _SONG_H

enum Style { POP, ROCK, ALTERNATIVE, COUNTRY, HIPHOP, PARODY };

class Song

{

// operator overload — described at bottom

friendostream& operator<<(ostream&os, const Song& s);

public:

Song(); // default constructor, sets up blank song object

void Set(const char* t, const char* a, Style st, intsz);

// the Set function should allow incoming data to be received through

// parameters and loaded into the member data of the object. (i.e.

// this function “sets” the state of the object to the data passed in).

// The parameters t, a, st, and sz represent the title, artist, style,

// and size of the song file, respectively.

const char* GetTitle() const; // returns the title stored in the object

const char* GetArtist() const; // returns the artist

intGetSize() const; // returns the file size in kilobytes

Style GetCategory() const; // returns the song category

private:

char title[36]; // may assume title is 35 characters or less

char artist[21]; // may assume artist name is 20 characters or less

Style category; // style of the given song

int size; // file size, stored in kilobytes

};

/* operator<< function

The operator<< overload should print out a Song object on one line

(use no more than 80 characters per line) as follows, in an organized

manner. Size should be printed in Megabytes (use 1000 kilobytes = 1 MB

for this calculation), to 1 decimal place. The category abbreviations

used should be: Pop, Rock, Alt, Ctry, HH, Par

Title Artist Style Size (MB)

Examples:

Pictures of You The Cure Alt 4.4

Bohemian Rhapsody Queen Rock 5.7

What Does the Fox Say Ylvis Par 12.6

Output:

Bohemian Rhapsody Queen 0 46

*/

#endif
