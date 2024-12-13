#ifndef MOVIELIST_H
#define MOVIELIST_H
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

class MovieList
{

private:
	vector<Movie> movies;
public:
	MovieList();
	~MovieList();
	Movie* get_movie(const int& movie_index);
	bool add_movie(const Movie& movie);
	void remove_movie(const int& movie_index);
	bool movie_is_added(const string& movie_name);
	void list_movies(bool detailed, bool includeHeader = true) const;
	void clear();
};

#endif //MOVIELIST_H