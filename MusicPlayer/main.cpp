
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <functional>
using namespace std;

struct Track
{
    string name;
    string author;
    int rating;

    friend ostream& operator<<(ostream& os, const Track& rhs)
    {
        os << setw(30) << left << rhs.name;
        os << setw(25) << rhs.author;
        os << setw(15) << right << rhs.rating << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Track& rhs)
    {
        string name, author, rating;
        cout << "Name:" << endl;
        cin >> name;
        //getline(cin, name);
        cout << "Author:" << endl;
        cin >> author;
        //getline(cin, author);
        cout << "Rating:" << endl;
        cin >> rating;
        //getline(cin, rating);
        rhs = Track{ name, author, stoi(rating) };
        return is;
    }
};

enum Action
{
    PlayFirst,
    PlayNext,
    PlayPrevious,
    PlayNew,
    ListTracks,
    None
};

list<Track> tracks;
list<Track>::iterator it;

list<Track> get_initial_tracks()
{
    return
    {
        { "God's Plan", "Drake", 3 },
        { "Never Be The Same", "Camila Cabello", 5 },
        { "Pray For Me", "The Weekend and K. Lamar", 4 },
        { "The Middle", "The Middle", 5 },
        { "Wait", "Maroone 5", 4 },
        { "Whatever It Takes", "Imagine Dragons", 5 },
    };
}

map<Action, string> get_actions()
{
    return
    {
        { PlayFirst, "F - Play First Song" },
        { PlayNext, "N - Play Next Song" },
        { PlayPrevious, "P - Play Previous song" },
        { PlayNew, "A - Add and play a new Song" },
        { ListTracks, "L - List Songs" },
    };
}

void output_tracks()
{
    for_each(tracks.begin(), tracks.end(), [](auto track) { cout << track; });
}

void display_inputs(map<Action, string> inputs)
{
    for_each(inputs.begin(), inputs.end(), [] (pair<Action, string> kvp)
    {
        cout << kvp.second << endl;
    });
}

Action get_inputted_action(map<Action, string> inputs)
{
    char c;
    Action output {None};
    while(true)
    {
        cin >> c;
        c = toupper(c);
        for(auto kvp:inputs)
        {
            if(c == kvp.second.at(0))
            {
                return kvp.first;
            }
        }
    }
    return output;
}

void play_track(Track track)
{
    cout << "Now playing:" << endl;
    cout << track;
}

void play_track_at(function<list<Track>::iterator()> it_get)
{
    it = it_get();
    play_track(*it);
}

list<Track>::iterator advance_iterator(
    list<Track>::iterator& it, 
    list<Track>::iterator begin, 
    list<Track>::iterator end, 
    int amount)
{
    end--;

    if(it == begin && amount < 0)
    {
        it = end;
        it--;
    }
    else if(it == end && amount > 0)
    {
        it = begin;
    }
    else
    {
        advance(it, amount);
    }

    return it;
}

list<Track>::iterator advance_iterator(list<Track>::iterator& it, int amount)
{
    return advance_iterator(it, tracks.begin(), tracks.end(), amount);
}

list<Track>::iterator advance_iterator(int amount)
{
    return advance_iterator(it, amount);
}

void play_new()
{
    Track track; 
    cin >> track;
    tracks.insert(it, track);
    it--;
    play_track(*it);
}

void run_action(Action action)
{
    switch (action)
    {
        case PlayFirst:
        play_track_at([=]() mutable { return tracks.begin(); });
        break;
    
        case PlayNext:
        play_track_at([]() mutable 
        { 
            return advance_iterator(1); 
        });
        break;
    
        case PlayPrevious:
        play_track_at([]() mutable 
        { 
            return advance_iterator(-1); 
        });            
        break;
    
        case PlayNew:
        play_new();
        break;
    
        case ListTracks:
        output_tracks();
        break;
    
        default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    auto inputs = get_actions();
    tracks = get_initial_tracks();
    run_action(PlayFirst);

    while(true)
    {
        display_inputs(inputs);
        auto action = get_inputted_action(inputs);
        cout << "\n";
        run_action(action);
        cout << "\n";
    }

    return 0;
}