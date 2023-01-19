#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
	string name{""};
	int grade{0};
};

int getStudentsNum()
{
	int num{};
	do
	{
		std::cout << " # of students ? ";
		std::cin >> num;
	} while (num <= 0);
	return num;
}

vector<Student> getStudents()
{
	using Students = std::vector<Student>;

	int numOfStudents{ getStudentsNum() };

	Students students(static_cast<Students::size_type>(numOfStudents));
	int studentNumber{ 1 };

	for (auto& student : students)
	{
		std::cout << "Name #" << studentNumber <<"?";
		std::cin >> student.name;
		std::cout<<"grade of #" << studentNumber << "?";
		std::cin >> student.grade;
		studentNumber += 1;
	}
	return students;
}

bool compare(const Student& a, const Student& b)
{
	return (a.grade > b.grade);
}





int main()
{


	vector<Student> students{ getStudents() };
	std::sort(students.begin(), students.end(), compare);

	for (const auto& student : students)
	{
		std::cout << student.name << " / grade : " << student.grade << "\n";
	}
	return 0;
}

