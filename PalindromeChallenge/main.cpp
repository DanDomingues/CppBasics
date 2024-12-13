#include <cctype>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <functional>

using namespace std;

vector<string> get_test_cases()
{
    return
    {
        "a",
        "aa", 
        "aba", 
        "abba", 
        "abbcbba", 
        "ab", 
        "abc", 
        "radar", 
        "bob", 
        "ana",
        "avid diva", 
        "Amore, Roma", 
        "A Toyota's a toyota", 
        "A Santa at NASA", 
        "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", 
        "This is a palindrome", 
        "palindrome"
    };
}

template <typename T>
T to_char_collection(string s, function<void(T&, char)> add_character)
{
    T output; 
    for(char c:s)
    {
        if(isalpha(c) == 0)
        {
            continue;
        }
        add_character(output, tolower(c));
    }
    return output;
}

deque<char> to_char_deque(string s)
{
    return to_char_collection<deque<char>>(
        s, 
        [](auto d, char c) {d.push_back(c);});
    
}

queue<char> to_char_queue(string s)
{
    return to_char_collection<queue<char>>(
        s, 
        [](auto& queue, char c) {queue.push(c);});
}

stack<char> to_char_stack(string s)
{
    return to_char_collection<stack<char>>(
        s, 
        [](auto& stack, char c) {stack.push(c);});
}

bool is_palindrome_deque(const string& s)
{
    auto deque = to_char_deque(s);

    if(deque.size() <= 0)
    {
        return false;
    }

    while(deque.size() > 1)
    {
        if(deque.back() != deque.front())
        {
            return false;
        }

        deque.pop_back();
        deque.pop_front();
    }

    return true;
}

bool is_palindrome_stack_queue(const string& s)
{
    auto stack = to_char_stack(s);
    auto queue = to_char_queue(s);
    while(!stack.empty() || !queue.empty())
    {
        if(stack.top() != queue.front())
        {
            return false;
        }
        stack.pop();
        queue.pop();
    }

    return true;
}

void run_test_cases()
{
    auto test_strings = get_test_cases();
    cout << boolalpha;
    cout << setw(8) << left << "Result" << "String" << endl;
    for(const auto& s : test_strings) 
    {
        cout << setw(8) << left << is_palindrome_stack_queue(s)  << s << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    run_test_cases();
    return 0;
}