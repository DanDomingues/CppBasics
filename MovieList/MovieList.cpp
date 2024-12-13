#include "MovieList.h"
#include <vector>
#include "Movie.h"
#include <iostream>

using namespace std;

MovieList::MovieList()
{
	
}

MovieList::~MovieList()
{
	
}


bool MovieList::add_movie(const Movie& movie)
{
	for(auto m:movies)
	{
		if(m.get_name() == movie.get_name())
		{
			return false;
		}
	}
	
	movies.push_back(movie);
	return true;
}

void MovieList::list_movies(bool detailed, bool includeHeader) const
{
	cout << "\n";

	if(movies.size() == 0)
	{
		cout << "Collection is empty.\n\n";
		return;
	}
	
	if(includeHeader)
	{
		cout << "Listing movies..." << endl;
	}
	
	int i {0};
	for(auto movie:movies)
	{
		if(detailed)
		{
			cout << "\n";
			cout << i + 1 << "." << endl;
			cout << "Name: " << movie.get_name() << endl;
			cout << "Rating: " << movie.get_rating() << endl;
			cout << "Times Watched: " << movie.get_watched_times() << endl;
			cout << "Notes: " << movie.get_notes() << endl;
		}
		else
		{
			cout << i + 1 << " - " << movies.at(i).get_name() << endl;
		}
		i++;
	}
	
	cout << "\n";
}

Movie* MovieList::get_movie(const int& movie_index)
{
	Movie* ptr {nullptr};
	ptr = &movies.at(movie_index);
	return ptr;
}

void MovieList::remove_movie(const int& movie_index)
{
	movies.erase(movies.begin() + movie_index);
}

bool MovieList::movie_is_added(const string& movie_name) 
{
	for(auto &movie:movies)
	{
		if(movie.get_name() == movie_name)
		{
			return true;
		}
	}
	return false; 
}

void MovieList::clear()
{
	cout << "\n";

	if(movies.size() == 0)
	{
		cout << "Collection is empty.\n\n";
		return;
	}
	
	cout << "Collection cleared." << endl;
	cout << "\n";

	movies.clear();
}