#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <sstream>

using namespace std;
namespace U3{
	class Statistics
	{
	private:
		array<int,1000000> salary;
		long int salaryCount;
	public:

		Statistics(void)
		{
			this->clear();
			this->salaryCount = 0;
		}

		~Statistics(void)
		{
		}

		void readSalary(string fileName)
		{
			ifstream myFile;
			string money;
			stringstream myMoneyStream;

			long long moneyInt = 0;

			myFile.open(fileName);
			while(!myFile.eof())
			{
				myFile >> money;
				myMoneyStream.str(money);
				myMoneyStream >> moneyInt;
				myMoneyStream.clear();
				if(moneyInt > 20000 && moneyInt < 1000000)
				{
					if(salary[moneyInt] == 0)
						salary[moneyInt] = 1;
					else if(salary[moneyInt] >= 1)
						salary[moneyInt] += 1;
					salaryCount ++;
					
				}
			}
			myFile.close();
		}

		int calculate_median()
		{
			int middleSalary = this->salaryCount / 2;
			int currentSalaryCount = 0;
			for(int i = 0; i < salary.size(); i++)
			{
				if(salary[i] != 0)
				{
					currentSalaryCount += salary[i];
					if(currentSalaryCount == middleSalary)
						return i;
					else if((currentSalaryCount -1) == middleSalary)
						return i;
					else if((currentSalaryCount +1) == middleSalary)
						return i;
				}
			}
		}

		int calculate_mean()
		{
			long long int totalSal = 0;
			for(int i = 0; i < salary.size(); i++)
			{
				if(salary[i] != 0)
				{
					totalSal += i;
				}
			}

			return totalSal / this->salaryCount;
		}

		void clear()
		{
			for(int i = 0; i < salary.size(); i++)
				salary[i] = 0;
		}
	};
}
