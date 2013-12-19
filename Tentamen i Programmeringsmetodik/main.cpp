#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <stack>

#include "Statistics.h"
#include "NilsCount.h"
#include "Hashtable.h"
#include "HashNode.h"

using namespace std;
namespace U3{
	bool checkPalim(deque<char> WF, deque<char> WB)
	{
		if(WF.size() == 0 && WB.size() == 0)
			return true;
		else
		{
			if(WF.front() == WB.front())
			{
				WF.pop_front();
				WB.pop_front();
				return checkPalim(WF,WB);
			}
			else
				return false;
		}
	}

	bool palindrome(string s)
	{
		deque<char> wordForward;
		deque<char> wordBackward;
	
		for(int i = 0; i < s.size(); i++)
		{
			wordForward.push_back(s[i]);
		}
		for(int i = s.size() -1; i >= 0; i--)
		{
			wordBackward.push_back(s[i]);
		}
		return checkPalim(wordForward,wordBackward);
	}
}
int main(void)
{
	U3::Statistics stats;
	U3::NilsCount NC;
	U5::HashTable<string,int> HT;

	HT.initHash(7,2);

	HT.add(U5::HashNode<string,int>("A",1));

	HT.print();



	/*if(U3::palindrome("olasalo"))
		cout << "Given string is a palindome" << endl;

	stats.readSalary("salary.txt");
	cout << "Salary mean: " << stats.calculate_mean() << endl;
	cout << "Salary median: " << stats.calculate_median() << endl;
	cout << "Clearing salary";
	stats.clear();*/

	/*NC.readBook("nils_holgersson.txt");
	cout << "Most frequent word in the book: " << NC.getFrequentWord() << endl;*/

	/*NC.readBookWithList("nils_holgersson.txt");
	cout << "Most frequent word in the book using list " << NC.getFrequentWordFromList() << endl;*/


	cin.get();
	return 0;
}