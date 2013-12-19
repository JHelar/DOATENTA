#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "unordered_list.h"
#include "Hashtable.h"


using namespace std;
namespace U3{
	class NilsCount
	{
	private:
		map<string,int> words;
		U4::unordered_list wordsUL;
	public:

		NilsCount(void)
		{
		}

		~NilsCount(void)
		{
		}

		void readBook(string fileName)
		{
			ifstream myFile;
			istringstream iss;
			string dummy;
			vector<string> wordVect;
			char trim[] = "(),.:; *";

			myFile.open(fileName);
			while(!myFile.eof())
			{
				getline(myFile,dummy,'\n');

				if(dummy != "")
				{
					iss.str(dummy);
					copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string>>(wordVect));
					iss.clear();
					dummy.clear();
					for(int i = 0; i < wordVect.size(); i++)
					{
						for(unsigned int j = 0; j < strlen(trim); j++)
						{
							wordVect[i].erase(remove(wordVect[i].begin(),wordVect[i].end(),trim[j]),wordVect[i].end());
						}
						if(words[wordVect[i]] >= 0)
							words[wordVect[i]] += 1;
						else
							words[wordVect[i]] = 0;	
					}
					wordVect.clear();
				}
			}
			myFile.close();
		}

		void readBookWithList(string fileName)
		{
			ifstream myFile;
			istringstream iss;
			string dummy;
			vector<string> wordVect;
			char trim[] = "(),.:; *";

			myFile.open(fileName);
			while(!myFile.eof())
			{
				getline(myFile,dummy,'\n');

				if(dummy != "")
				{
					iss.str(dummy);
					copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter<vector<string>>(wordVect));
					iss.clear();
					dummy.clear();
					for(int i = 0; i < wordVect.size(); i++)
					{
						for(unsigned int j = 0; j < strlen(trim); j++)
						{
							wordVect[i].erase(remove(wordVect[i].begin(),wordVect[i].end(),trim[j]),wordVect[i].end());
						}
						if(wordsUL.find(wordVect[i]))
							wordsUL.increaseInfoIntToNode(wordVect[i]);
						else
							wordsUL.add(wordVect[i],1);
					}
					wordVect.clear();
				}
			}
			myFile.close();
		}

		void readBookWithHash(string fileName)
		{
			
		}

		string getFrequentWord()
		{
			int best = 0;
			string bestWord;

			typedef map<string,int>::iterator iter;
			for(iter iterator = words.begin(); iterator != words.end(); iterator++)
			{
				if(iterator->second > best)
				{
					best = iterator->second;
					bestWord = iterator->first;
				}
			}
			return bestWord;
		}

		string getFrequentWordFromList()
		{
			int best = 0;
			int bestCounter = 0;
			string bestWord;
			for(auto word = wordsUL.begin(); word != wordsUL.end(); word++)
			{
				if((*word).infoInt > best)
				{
					best = (*word).infoInt;
					bestWord = (*word).info;
				}
			}
			return bestWord;
		}


	};
}

