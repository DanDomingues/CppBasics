#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//Class def
class Test
{
private:
    int data;
public:
    Test() : data{0} 
    { 
        cout << "\tTest constructor (" << data << ")" << endl;
    }
    Test(int data) : data {data} 
    { 
        cout << "\tTest constructor (" << data << ")" << endl;
    }
    ~Test() 
    {
        cout << "\tTest destructor (" << data << ")" << endl; 
    }

    int get_data() const { return data; }
};

//Main headers
unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display(const vector<shared_ptr<Test>>&vec);

//main method
int main() 
{
    auto vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

unique_ptr<vector<shared_ptr<Test>>> make()
{
    auto ptr = make_unique<vector<shared_ptr<Test>>>();
    return ptr;
}

void fill(vector<shared_ptr<Test>> &vec, int num)
{
    int value;
    for (int i {0}; i < num; i++)
    {
        value = (i + 1) * 10;
        auto ptr = make_shared<Test>(value);
        vec.push_back(ptr);
    }
}

void display(const vector<shared_ptr<Test>>&vec)
{
    int i {0};
    for(auto &ptr:vec)
    {
        cout << "Pointer #" << i + 1 << ": " << ptr->get_data() << endl;
        i++;
    }
}