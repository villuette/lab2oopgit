#include <iostream>
#include <string>
#include <locale>
using namespace std;
class Human {
protected:
	string Name;
	string Surname;
	int YearsOld;
	long Money = 0;
	char monthes = 0;
	void LiveMonth() {		
		this->Money -= 10'000 * LifeCondition; //чем лучше жизнь тем дороже жить
		monthes = (monthes + 1) % 12;
		
	}
public:
	int GetMonthes() { return monthes; }
	int GetYears() { return YearsOld; }
public:
	int LifeCondition = 1;
	Human(string name, string surname, int years) {//all humans MUST HAVE these parameters
		this->Name = name;
		this->Surname = surname;
		YearsOld = years;
	}

};
class Worker : Human {
private:
	bool Retired = false; //на пенсии, по умолчанию НЕТ
	int Salary = 0;
	int contractYears = 0;
public:
	void WorkMonth() {
		LiveMonth();
		Money += Salary;
	}
	void Hire(int contractYears, int salary) {
		this->Salary = salary;
		this->contractYears = contractYears;
	}
	Worker(string n, string s, int y, int lifecondition) :Human(n, s, y) {
		int yearoptimize = int(YearsOld / (YearsOld - 5));
		this->LifeCondition = 1 / Surname.length() + yearoptimize + Salary/100'000;
	};
};
//__interface IProvidePopularity { //сюда пока не лезем )
//	void RaisePopularity() {};
//};
//__interface IProvideInvestitions {
//	void AttractInvestments() {};
//};
class Company{
private:
	int producing = 1;
	long Budget;
	int popularity;
	int rawmaterials = 0;
	long products = 0;
	int rating = 1; //чем выше рейтинг, тем дешевле компания закупает продукты
protected:
	virtual void AllsWorkMonth(Worker wkr[], int count) { //common working conditions
		for (int i = 0; i < count; i++) {
			products += count * producing;
			rawmaterials -= products;
			wkr[i].WorkMonth();
			
		}
	}
	virtual void SellProducts(Company& cmp, int sellCount) {
		
	}
	virtual void BuyProducts(Company& cmp) {

	}
};
class MyCompany : Company {
private:
	Worker** workers;
public:
	void HireManyWorkers(int count, int theirSalary, string names[], string surnames[], int years[], int theirLifeCond[], int contractYears[]) {
		if (count < 0) throw new exception();
		for (int i = 0; i < count; ++i) {
			workers[i] = new Worker(names[i], surnames[i], years[i], theirLifeCond[i]);
			workers[i]->Hire(contractYears[i], theirSalary);
		}
	}
};
int main()
{

}
