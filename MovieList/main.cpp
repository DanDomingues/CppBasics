//#include <stdio.h>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"
#include "MovieList.h"

using namespace std;

enum class Action 
{
	List,
	Detail,
	Add,
	Edit,
	Clear,
	None
};

enum class Property
{
	Name,
	Rating,
	Notes,
	TimesWatched,
	Remove,
	None
};

struct Input_Action_Settings
{
	char key;
	string description;
	Action input;
};

struct Property_Settings
{
	char key;
	string description;
	Property property;
};

vector<Input_Action_Settings> input_actions;
vector<Property_Settings> movie_properties;

MovieList movies;

MovieList initialize_list()
{
	MovieList movies;
	movies.add_movie(Movie("Avatar", "PG-13"));
	movies.add_movie(Movie("Kirby", "E"));
	movies.add_movie(Movie("Mario", "E"));
	return movies;
}

void initialize_inputs()
{
	input_actions = vector<Input_Action_Settings>
	{
		{ 'L', "List movies", Action::List },
		{ 'D', "Show detailed view", Action::Detail },
		{ 'A', "Add movie", Action::Add },
		{ 'E', "Edit movie", Action::Edit },
		{ 'C', "Clear list", Action::Clear },
	};

	movie_properties = vector<Property_Settings>
	{
		{ 'N', "Name", Property::Name },
		{ 'R', "Rating", Property::Rating },
		{ 'M', "Memo", Property::Notes },
		{ 'T', "Times Watched", Property::TimesWatched },
		{ 'D', "Delete", Property::Remove },
	};
}

template<typename T>
void draw_inputs(vector<T> values, string header = "")
{
	if(header != "")
	{
		cout << header;
	}

	for(auto s:values)
	{
		std::cout << s.key << " - " << s.description << endl;
	}
}

template <typename T1, typename T2>
T2 get_input_action(char input, vector<T1> inputs, function<char(T1)> get_key, function<T2(T1)> get_value, T2 default_value)
{
	input = toupper(input);
	for(auto setting:inputs)
	{
		auto key = get_key(setting);
		if(key == input)
		{
			return get_value(setting);
		}
	}
	return default_value;
}

Action read_action_input()
{
	char input;
	auto action {Action::None};
	while(action == Action::None)
	{
		std::cin >> input;
		action = get_input_action<Input_Action_Settings, Action>(
			input,
			input_actions,
			[](auto s){ return s.key; },
			[](auto s){ return s.input; },
			Action::None);

		if(action == Action::None)
		{
			std::cout << "Invalid input, try again." << endl;
		}
	}
	return action;
}

void add_movie()
{
	string name, rating, memo;
	int watched_times;
	std::cout << "\n";
	std::cout << "Please input name and rating and notes (avoid spaces, use underscores)" << endl;

	do
	{
		std::cout << "Name: ";
		std::cin >> name;
		if(movies.movie_is_added(name))
		{
			std::cout << "Already registered, please try again." << endl;
		}
	}
	while(movies.movie_is_added(name));

	std::cout << "Rating: ";
	std::cin >> rating;
	std::cout << "Notes: ";
	std::cin >> memo;
	std::cout << "Watched times: ";
	std::cin >> watched_times;
	
	movies.add_movie(Movie(name, rating, memo, watched_times));
	std::cout << "\n";
}

void clear_movies()
{
	movies.clear();
	std::cout << "Movies have been cleared\n" << endl;
}

string get_property_value(Movie* movie, Property property)
{
	switch(property)
	{
		case Property::Name: return movie->get_name();
		case Property::Rating: return movie->get_rating();
		case Property::Notes: return movie->get_notes();
		case Property::TimesWatched: return std::to_string(movie->get_watched_times());
		default: return "";
	}
}

void set_property_value(Movie* movie, Property property, string input)
{
	switch(property)
	{
		case Property::Name:
		movie->set_name(input);
		break;

		case Property::Rating:
		movie->set_rating(input);
		break;

		case Property::Notes:
		movie->set_notes(input);
		break;

		case Property::TimesWatched:
		movie->set_watched_times(stoi(input));
		break;
		
		default:
		break;
	}
}

void edit_movie(Movie* movie_ptr, int index)
{
	draw_inputs(movie_properties, "Select a property to edit:\n\n");
	
	//Reads property input
	char input;
	Property property {Property::None};
	while(property == Property::None)
	{
		std::cin >> input;
		property = get_input_action<Property_Settings, Property>(
			input,
			movie_properties,
			[](auto s){ return s.key; },
			[](auto s){ return s.property; },
			Property::None);

		if(property == Property::None)
		{
			std::cout << "Invalid input, try again." << endl;
		}
	}
	
	//Removes movie if input is matching
	if(property == Property::Remove)
	{
		std::cout << "Removed entry from list.\n" << endl;
		movies.remove_movie(index);
		return;
	}
	
	//Lists current value
	std::cout << "Current: " << get_property_value(movie_ptr, property) << endl;
	
	//Read new value input
	string inputted_string;
	do
	{
		std::cout << "Input new value (no spaces): ";	
		std::cin >> inputted_string;
		if(property == Property::Name && movies.movie_is_added(inputted_string))
		{
			std::cout << "Already registered, please try again." << endl;
		}
	} 
	while (property == Property::Name && movies.movie_is_added(inputted_string));
	std::cout << "\n";
	

	//Applies to movie values
	set_property_value(movie_ptr, property, inputted_string);
}
int main(int argc, char **argv)
{
	movies = initialize_list();
	initialize_inputs();
	
	std::cout << "Welcome to My Movie List" << endl;
	
	Action action;	
	while(true)
	{
		draw_inputs(input_actions);
		action = read_action_input();

		//Performs action
		switch(action)
		{
			case Action::List:
			movies.list_movies(false);
			break;
			
			case Action::Detail:
			movies.list_movies(true);
			break;
			
			case Action::Add:
			add_movie();
			break;
			
			case Action::Clear:
			clear_movies();
			break;
			
			default:
			break;
		}
		
		if(action != Action::Edit)
		{
			continue;
		}
		
		//Draws movie inputs
		std::cout << "\nSelect a movie to edit:\n";
		movies.list_movies(false);
		
		//Reads input and forwards to edit movie
		int inputted_int;
		std::cin >> inputted_int;
		int movie_index = inputted_int - 1;
		auto movie = movies.get_movie(movie_index);
		edit_movie(movie, movie_index);
	}
	return 0;
}