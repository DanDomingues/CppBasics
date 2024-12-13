#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> read_source_file(string path)
{
    ifstream in_file {path};
    string line;
    vector<string> output;
    while(getline(in_file, line))
    {
        output.push_back(line);
    }
    in_file.close();
    return output;
}

string get_clean_string(string input)
{
    string s {""};
    for(auto c:input)
    {
        if(c == '\'')
        {
            break;
        }
        if(c == ',' || c == '.' || c == ';')
        {
            continue;
        }
        s += c;
    }
    return s;
}

template<typename T> map<string, T> 
process_content(
    vector<string> lines, 
    function<T(int line)> initial_value, 
    function<void(T&, int line)> add_to_value)
{
    string word;
    map<string, T> map;
    int line_number {0};
    for(auto s:lines)
    {
        stringstream stream {s};
        while(stream >> word)
        {
            word = get_clean_string(word);

            if(map.count(word) != 0)
            {
                add_to_value(map[word], line_number);
            }
            else
            {
                map[word] = initial_value(line_number);
            }
            line_number++;
        }
    }
    return map;
}

map<string, int> get_word_count_new(vector<string> lines)
{
    return process_content<int>(
        lines, 
        [](auto _){ return 1; }, 
        [](auto& counter, auto line) { counter++; });
}

map<string, set<int>> get_word_lines_new(vector<string> lines)
{
    return process_content<set<int>>(
        lines,
        [](auto line){ return set<int> { line }; },
        [](auto& set, auto line) { set.insert(set.begin(), line); });
}

string int_array_to_string(set<int> set)
{
    string s {"[ "};
    size_t limit {45};
    int counter {0};
    for(auto n:set)
    {
        if(s.length() >= limit)
        {
            auto omitted = set.size() - counter;
            s += string("... (+" + to_string(omitted) + ") ");
            break;
        }
        s += to_string(n) + " ";
        counter++;
    }
    s += "]";
    return s;
}

template<typename T1, typename T2> 
vector<pair<T1, T2>> sort_map(map<T1, T2> map, function<int(T2, T2)> comparison)
{
    vector<pair<T1, T2>> vector;
    for(auto pair:map) vector.push_back(pair);
    sort(vector.begin(), vector.end(), [comparison](pair<T1, T2> a, pair<T1, T2> b)
    {
        return comparison(a.second, b.second);
    });
    return vector;
}

void output_word_count(map<string, int> word_count)
{
    auto vec = sort_map<string, int>(
        word_count, 
        [](auto a, auto b){ return a > b; });

    cout << setw(20) << left << "Word";
    cout << right << "Count" << endl;
    cout << string(40, '=') << endl;

    for(auto kvp:vec)
    {
        if(kvp.second > 1)
        {
            cout << setw(20) << left << kvp.first;
            cout << right << kvp.second << endl;
        }
    }
    cout << "\n\n";
}

void output_word_lines(map<string, set<int>> word_lines)
{
    auto vec = sort_map<string, set<int>>(
        word_lines, 
        [](auto a, auto b)
        {
            return a.size() != b.size() ? (a.size() > b.size()) : (*a.begin() < *b.begin());
        });

    cout << setw(20) << left << "Word";
    cout << setw(200) << left << "Lines";
    cout << string(80, '=') << endl;

    for(auto pair:vec)
    {       
        cout << setw(20) << left << pair.first;
        cout << setw(60) << right << int_array_to_string(pair.second) << endl;
    }
}

int main(int argc, char const *argv[])
{
    auto path = "C:\\dev/cpp/Udemy_Course/OzCounterChallenge/words.txt";
    auto lines = read_source_file(path);
    auto word_lines = get_word_lines_new(lines);
    output_word_count(get_word_count_new(lines));
    output_word_lines(get_word_lines_new(lines));
    return 0;
}