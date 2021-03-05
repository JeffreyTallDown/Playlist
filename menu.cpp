Menu.cpp

// An object of type Song will store information about a single

// digitally recorded song file.

#include

#include “song.h”

#include “playlist.h”

#include"playlist.h"

#include<iostream>

#include<iomanip>

int Int();
char Char();

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
int main(){

  
  
    Style style;
 
    Playlist library;
    char x;
    bool X = true; 
    char genre
    int size;
Style c;

chartempStyle; //to read in Style

int s = 0;

cout<< “Enter a song title: ” <
char *title  = new char[36];
cin.getline(t, 36);
  bool y = true;

cout<< “Enter a song artist: ” <
	char *artist = new char[21];
  bool a = true;
cin.getline(a, 21);

  
  x = Character();
cout<< “Enter a song category: ” <

cout<< “(P = pop, R = rock, A = alternative, C = country, H = hiphop, Y = parody)” <

cin>>tempStyle;
switch(x){
                case 'A':
                case 'a':

while (tempStyle != ‘P’ &&tempStyle != ‘p’ &&tempStyle != ‘R’ &&tempStyle != ‘r’ &&

tempStyle != ‘A’ &&tempStyle != ‘a’ &&tempStyle != ‘C’ &&tempStyle != ‘c’ &&

tempStyle != ‘H’ &&tempStyle != ‘h’ &&tempStyle != ‘Y’ &&tempStyle != ‘y’) {
genre = Char();
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
  s = size; 
size = Integer();
if (s <= 0) {

cout<< “Must enter a positive size. Please re-enter: ” <
size = Integer();

}
if (size > 0){
					a = false;
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
library.Add(title,artist,style,size); 


Song song;

charlookupString[36];

command = GetCommand();
  delete [] title;
  delete [] artist;

switch (command) {

case ‘A’:

GetInput(song);

p.Insert(song);

break;

case ‘F’:

cout<< “\tType a SONG TITLE or ARTIST to be searched, followed by : “;

cin.getline(lookupString, 36);
  library.Find(title);
delete [] title;
break;


p.Lookup(lookupString); break;

case ‘D’:

cout<< “\nType name to be removed, followed by : “;
cin.clear();
cin.getline(lookupString, 36);
 library.Remove(title);


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

case ‘O’:  x = FindCharacter();
p.SortSong(); p.DisplayPlaylist(); break;
	case 'x':
      
           
case ‘X’: break;
check = false;
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
    return x; 
default: break;
cin.peek() != '\n'){
 cin.ignore();
}

} while (command != ‘X’ && command != ‘x’);
cin.peek() != '\n'){
 cin.ignore();

return 0;


} 
