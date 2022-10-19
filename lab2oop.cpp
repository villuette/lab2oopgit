#include <iostream>
#include <string>
#include <locale>
using namespace std;
class Human {
private:
	string Name; //жалко што нельзя :(
	string Surname;
	int YearsOld;
	long money;
	int LifeCondition;
	Human(string name, string surname, int years) {
		this->Name = name;
		this->Surname = surname;
		this->YearsOld = years;
	}
	void LiveMonth() {
		this->money -= 
	}
};
class Worker : Human {
	bool Retired = false; //на пенсии, по умолчанию НЕТ
	int Salary;
	void Hire(int salary) {
		this->Salary = salary;
	}
	void WorkMonth() {

	}
};
int main()
{

}
