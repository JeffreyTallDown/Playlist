#include “song.h”

class Playlist{

public:
  
  
    Playlist();
  
   ~Playlist();	
  
   void Menu()const;
    void Add(char *s, char *a, Style c, int size); 
    void Remove(const char *search);
  
    double Showsize()const;
Song();
  void Set(const char* t, const char* a, Style st, intsz);
const char* GetTitle() const; // returns the title stored in the object
  const char* GetArtist() const; // returns the artist
void Find(const char *search)const;
intGetSize() const; // returns the file size in kilobytes

Style GetCategory() const; // returns the song category
    void ShowCategory(const Style genre)const; 
    void Sort(const char sortchar);


private:

Song *library;
char title[36]; // may assume title is 35 characters or less

char artist[21]; // may assume artist name is 20 characters or less

Style category; // style of the given song

int size; 
  
  int fillslots; 
    int slots;				
  
   void expand();   
    void contract(int X);		


};
