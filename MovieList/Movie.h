#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;

class Movie
{
private:
	std::string name;
	std::string rating;
	std::string notes;
	int times_watched;
	
public:
	Movie();
	Movie(string name, string rating, string notes = "", int times_watched = 0);
	~Movie();
	
	//get methods
	std::string get_name() const;
	std::string get_rating() const;
	std::string get_notes() const;
	int get_watched_times() const;
	
	//set methods
	void increment_watched_times();
	void set_watched_times(const int& amount);
	void set_notes(const string& notes);
	void set_rating(const string& rating); 
	void set_name(const string& name);
};

#endif // MOVIE_H
