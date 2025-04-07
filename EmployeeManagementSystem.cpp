#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
public:
	char storeName[50];
	int id;
	float salary;
public:
	Employee(char* n, int i, float s)
	{
		strcpy_s(storeName, 50, n);
		id = i;
		salary = s;
	}

	void display() const 
	{
		cout << "ID: " << id << "  Name: " << storeName << " Salary: " << salary << endl;
	}

};

class EmployeeManagement 
{
private:
	Employee* emp[5];
	int currentSize = 0;
public:
	void addEmployee(char* n, int i, float s)
	{
		emp[currentSize++] = new Employee(n, i, s);
	}

	void sortingEmployee()
	{
		for (int i = 0; i < currentSize; i++)
		{
			for (int j = 0; j < currentSize - i - 1; j++)
			{
				if (emp[j]->salary > emp[j + 1]->salary)
				{
					Employee* temp = emp[j];
					emp[j] = emp[j + 1];
					emp[j + 1] = temp;
				}
			}
		}
	}

	void sortEmployeebyID()
	{
		for (int i = 0; i < currentSize; i++)
		{
			for (int j = 0; j < currentSize - i - 1; j++)
			{
				if (emp[j]->id > emp[j + 1]->id)
				{
					Employee* temp = emp[j];
					emp[j] = emp[j + 1];
					emp[j + 1] = temp;
				}
			}
		}
	}

	Employee* binarySearch(int id)
	{
		sortEmployeebyID();

		int low = 0, high = currentSize;
		int mid = (low + high) / 2;
		while (low <= high)
		{
			if (emp[mid]->id == id)
			{
				return emp[mid];
			}
			else if (emp[mid]->id < id)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return nullptr;
	}

	void display()
	{
		for (int i = 0; i < currentSize; i++)
		{
			emp[i]->display();
		}
	}

	~EmployeeManagement()
	{
		for (int i = 0; i < currentSize; i++)
		{
			delete emp[i];
		}
	}
};
int main()
{
	EmployeeManagement ems;
	
	ems.addEmployee("Anees Ahmad", 0776, 100000);
	ems.addEmployee("Rao Abdullah", 0255, 90000);
	ems.addEmployee("Hammad Ahmad", 0412, 95000);

	cout << "Displaying Details: " << endl;
	ems.display();

	cout << endl;

	ems.sortingEmployee();
	ems.display();

	ems.binarySearch(0776);




	system("pause");
	return 0;
}

