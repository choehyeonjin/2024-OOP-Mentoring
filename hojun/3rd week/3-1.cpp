#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee//class declare
{
private:
	char name[20];
	int age = 0;
	char country[20];
	char job[20];
public:
	Employee(char* name, int age, char* country, char* job);
	bool isNameCorrect(char* name) const;
	void print() const;
	void change(char* name, int age, char* country, char* job);
};

Employee* emp[10];//employee array

int main()
{
	int emp_num = 0;//employee number
	char input[10] = {};//command input array
	char fi[20];
	///input information variable
	char name[20];
	int age;
	char country[20];
	char job[20];
	//////////////////

	while (1)
	{
		cin >> input;

		if (strcmp(input, "exit") == 0) { break; }
		else if (strcmp(input, "print") == 0)
		{
			cout << "=====print=====\n";
			for (int i = 0; i < emp_num; i++)
				emp[i]->print();
		}
		else if (strcmp(input, "insert") == 0)
		{
			cout << "새로운 직원\n";
			cin >> name >> age >> country >> job;
			emp[emp_num] = new Employee(name, age, country, job);
			emp_num++;
		}
		else if (strcmp(input, "find") == 0)
		{
			cin >> fi;
			for (int i = 0; i < emp_num; i++)
			{
				if (emp[i]->isNameCorrect(fi))
				{
					cout << "=====find=====\n";
					emp[i]->print();
				}
			}
		}
		else if (strcmp(input, "change") == 0)
		{
			cin >> input >> name >> age >> country >> job;
			for (int i = 0; i < emp_num; i++)
			{
				if (emp[i]->isNameCorrect(input))
				{
					emp[i]->change(name, age, country, job);
					break;
				}
			}
		}

	}
}

//////class member function define part/////////
Employee::Employee(char* name, int age, char* country, char* job)
{
	strcpy(this->name, name);
	strcpy(this->country, country);
	strcpy(this->job, job);
	this->age = age;
}

bool Employee::isNameCorrect(char* name) const
{
	bool k = !strcmp(this->name, name);
	return k;
}

void Employee::print() const
{
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl;
	cout << "----------\n";
}

void Employee::change(char* name, int age, char* country, char* job)
{
	strcpy(this->name, name);
	strcpy(this->country, country);
	strcpy(this->job, job);
	this->age = age;
}