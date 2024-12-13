#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Student_Attempt
{
    std::string name;
    std::string answer;
    int score;
};

int get_score(std::string attempt, std::string reference)
{
    int score {0};
    for(size_t i {0}; i < reference.length(); i++)
    {
        if(attempt.at(i) == reference.at(i))
        {
            score++;
        }
    }
    return score;
}

double get_score_avg(std::vector<Student_Attempt> attempts)
{
    double total {0.0};
    for(auto a:attempts)
    {
        total += a.score;
    }
    return total / attempts.size();
}

std::vector<Student_Attempt> read_test_results(std::string file_path)
{
    std::ifstream in_file;
    in_file.open(file_path, std::ifstream::in);
    if(!in_file)
    {
        std::cerr << "Issue with file loading!: " << in_file.badbit << std::endl;
        throw -1;
    }

    std::string answers;
    std::getline(in_file, answers);
    
    std::string student_count_str;
    std::getline(in_file, student_count_str);
    int student_count {std::stoi(student_count_str)};

    std::vector<Student_Attempt> students;
    std::string name, student_answer;  
    for(int i {0}; i < student_count; i++)
    {
        std::getline(in_file, name);
        std::getline(in_file, student_answer);
        students.push_back(Student_Attempt 
        {
            name,
            student_answer, 
            get_score(student_answer, answers)
        });
    }
    in_file.close();
    return students;
}

int main(int argc, char const *argv[])
{
    auto path = "grades.txt";
    auto results = read_test_results(path);

    //Builds header
    int left_size {15}, right_size {15};
    std::cout << std::setw(left_size) << std::left << "Student";
    std::cout << std::setw(right_size) << std::right << "Score" << std::endl;
    std::cout << std::string(left_size + right_size, '-') << std::endl;

    //Outputs student name and score
    for(auto s:results)
    {
        std::cout << std::setw(left_size) << std::left << s.name;
        std::cout << std::setw(right_size) << std::right << s.score << std::endl;
    }
    std::cout << std::string(left_size + right_size, '-') << std::endl;

    //Outputs students avg
    std::cout << std::setw(left_size) << std::left << "Average score";
    std::cout << std::setw(right_size) << std::right << get_score_avg(results) << std::endl;

    return 0;
}