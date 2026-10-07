#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	vector<unsigned int> grades;

public:
// private:
	string name = "noname";
	string group = "nogroup";
	unsigned int age = 0;
	
// public:
	string GetInfo();
	float GetAverageGrade();
	void SetGrades(initializer_list<unsigned int> grades);
};

string Student::GetInfo() {
	return this->name + " " + to_string(this->age) + " лет.";
}
float Student::GetAverageGrade() {
	float sum = 0;
	for (int i= 0; i < 10; i++) {
		sum += this->grades[i];
	}
	return sum / 10;
}
void SetGrades(initializer_list<unsigned int> grades) {
	this->grades = grades;
}

int main() {

	Student students[2];

	students[0].name = "Петров";
	students[0].group = "Б-АИ-101";
	students[0].SetGrades({3, 2, 4, 3, 4, 5, 3, 4, 3, 1});
	
	students[0].name = "Иванов";
	students[0].group = "Б-ПИ-201";
	students[0].SetGrades({4, 5, 4, 4, 3, 5, 5, 4, 3, 5});

	for (int i = 0; )
    
    return 0;
}
