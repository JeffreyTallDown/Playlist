#include"playlist.h"
#include<cstring>
#include<iomanip>

#pragma once

Playlist::Playlist()

{

slots = 5;

openslots = 0;
   library = new Song[5];
}

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

     void Playlist::Remove(const char *search){		
    if( fillslots == 0 ) {
    	std::cout << "Nothing .\n";
	return;
    }
void Playlist::SortSong()

{

cout<< “\tA or a \tSort playlist via Artist” << ‘\n’;

cout<< “\tT or t \tSort playlist via Title” << ‘\n’;

cout<< “\n> “;
earches for information then points to it in array
			std::cout << library[i];
		}
	}

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
if( strcmp(search, library[i].GetTitle()) == 0){
		std::cout<< "\nTitles That Matched Search:\n";count++; break;
	}
    }

}

// SortSongbyArtist

void Playlist::SortSongbyArtist()

{

for (int i = 0; i
    int count = 0;
	std::cout<< "Title" << setw(38) << "Artist" << setw(21)<< "Style" << setw(18) << "Size (MB)\n\n";
		for (int i = 0; i < fillspaces; i++){
        		if(strcmp( search, library[i].GetArtist()) == 0){
				std::cout << library[i];

    for (int i = 0; i < fillspaces; i++){
        if ( genre == library[i].GetCategory()) {
                std::cout<<library[i]; count ++;
        }
    }

    if(count == 0){
         std::cout<< "No Songs In Library With This Genre.\n";
    }
}
{

for (int j = i; j

{

if (strcmp(songList[i].GetArtist(), songList[j].GetArtist()) > 0) //need to sort

{
temp[a].Set(min.GetTitle(),min.GetArtist(),min.GetCategory(),min.GetSize());
        	Remove(min.GetTitle()); a++;
	}
	
//swap song infomation

Song tempSong;

tempSong.Set(songList[i].GetTitle(), songList[i].GetArtist(), songList[i].GetCategory(), songList[i].GetSize());

songList[i].Set(songList[j].GetTitle(), songList[j].GetArtist(), songList[j].GetCategory(), songList[j].GetSize());
  f(fillslots == 0 ) {std::cout<< "Nothing.\n"; return;}
    std::cout<< "Title" << setw(38) << "Artist" << setw(21) <<

songList[j].Set(tempSong.GetTitle(), tempSong.GetArtist(), tempSong.GetCategory(), tempSong.GetSize());
  temp[i].Set(GetCategory(),library[a].GetSize());
	}
    }

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
temp[filled-1],library[0].GetSize());
    }
{
double Playlist::Showsize()const{
    double sum=0;

    for(int i = 0; i < fillspaces; i++){
    	sum = sum + library[i].GetSize();
    }

    return sum;
}
//swap song infomation

Song tempSong;

tempSong.Set(songList[i].GetTitle(), songList[i].GetArtist(), songList[i].GetCategory(), songList[i].GetSize());

songList[i].Set(songList[j].GetTitle(), songList[j].GetArtist(), songList[j].GetCategory(), songList[j].GetSize());

songList[j].Set(tempSong.GetTitle(), tempSong.GetArtist(), tempSong.GetCategory(), tempSong.GetSize());

}

}

}

}
     void Playlist::expand(){  
    slots += 5;
    Song *temp = new Song[ spaces ];
     }
     void Playlist::contract(int a){   
    slots = slots - a;
     }
    delete [] library;
    library = temp;
}
