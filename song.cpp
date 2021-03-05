	istream &operator>>(istream &is, Song &song)
	{
		IgnoreNewLines();
		cin.getline(song.title, Song::MAX_CHARS, ',');

		if (cin.peek() == ' ')
			cin.ignore();

		IgnoreNewLines();

		cin.getline(song.artist, Song::MAX_CHARS);

		return is;
	}
	ostream &operator<<(ostream &os, const Song &song)
	{
		os << song.title << ", " << song.artist;


		return os;
	}
  
  void Song::Set(const char* t, const char* a, Style st, intsz)

{


size = sz;

category = st;

strcpy(Title, t);

strcpy(Artist, a);


}
  
  
  
Song::Song()

{

strcpy(Title, ” “);

strcpy(Artist, ” “);

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




