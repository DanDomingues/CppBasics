#include "Movie.h"
#include <string>

Movie::Movie()
{
	name = "Undefined";
	rating = "PG";
	times_watched = 0;
	notes = "";
}

Movie::Movie(std::string name, std::string rating, std::string notes, int times_watched) :
name{name}, rating{rating}, notes{notes}, times_watched{times_watched}
{
	//this->name = name;
	//this->rating = rating;
	//this->times_watched = times_watched;
	//this->notes = notes;
}

Movie::~Movie()
{
	
}

std::string Movie::get_name() const { return name; }

std::string Movie::get_rating() const { return rating; }

std::string Movie::get_notes() const { return notes; }

int Movie::get_watched_times() const { return times_watched; }

void Movie::set_name(const std::string& name)
{
	this->name = name;
}

void Movie::set_rating(const std::string& rating)
{
	this->rating = rating;
}

void Movie::set_notes(const std::string& notes)
{
	this->notes = notes;
}

void Movie::set_watched_times(const int& amount)
{
	times_watched = amount;
}

void Movie::increment_watched_times()
{
	times_watched++;
}