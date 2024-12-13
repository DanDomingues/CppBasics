#include <fstream>
#include <iostream>
using namespace std;

bool contains_word(string word, string container, bool require_full_match = false)
{
    if(require_full_match)
    {
        return container == word;
    }

    if(container.length() < word.length())
    {
        return false;
    }

    int comparison_index {0};
    for(size_t i {0}; i < container.length(); i++)
    {
        if(comparison_index >= word.length())
        {
            break;
        }
        if(container.at(i) == word.at(comparison_index))
        {
            comparison_index++;
        }
        else
        {
            comparison_index = 0;
        }
    }
    
    return comparison_index >= word.length();
}

int list_matches(string query, const char* path, bool full_match_required)
{
    ifstream in_file {path};

    string word;
    int matches {0};
    while(in_file >> word)
    {
        if(full_match_required ? (word == query) : contains_word(query, word))
        {
            cout << word << (full_match_required ? " matches " : " contains ") << query << endl;
            matches++;
        }
    }
    return matches;
}

void record_report(const char* path, string query, int matches, bool full_match)
{
    ofstream out_file {path};
    auto report = 
        "Found " + to_string(matches) + 
        " references for " + query + 
        " (full match: " + (full_match ? "true" : "false") + ")";
    
    for(char c:report)
    {
        out_file.put(c);
    }
    out_file.close();
}

int main(int argc, char const *argv[])
{
    string query;
    cout << "Input word to be searched: ";
    cin >> query;

    bool full_match_required;
    cout << "Require full match? (binary)";
    cin >> full_match_required;

    auto source_path = "C:\\dev/cpp/Udemy_Course/WordFinder/romeoandjuliet.txt";
    auto matches = list_matches(query, source_path, full_match_required);
    
    auto report_path = "C:\\dev/cpp/Udemy_Course/WordFinder/output.txt";
    record_report(report_path, query, matches, full_match_required);

    return 0;
}
