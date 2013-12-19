#pragma once

#include <iostream>
#include "HashNode.h"


namespace U5
{
	template<class KEY,class INFO>
	class HashTable
	{
	private:
		int bucketSize;
		int primeNumber;
		HashNode<KEY,INFO> *head;
		HashNode<KEY,INFO> *tail;
		hash<KEY> h;

		long hash(KEY key)
		{
			return (h(key) % primeNumber);	
		}

	public:

		HashTable(void)
		{
			head = tail = nullptr;
		}

		HashTable(int primeNumber, int bucketSize, KEY key, INFO info)
		{
			this->primeNumber = primeNumber;
			this->bucketSize = bucketSize;

			for(int i = 0; i < (bucketSize * primeNumber); i++)
			{
				if(head == nullptr)
					head = tail = new HashNode<KEY,INFO>(key,info);
				else
				{
					HashNode<KEY,INFO> *n = new HashNode<KEY,INFO>(key,info);
					n->next = head;
					head = n;
				}
			}
		}

		void initHash(int primeNumber, int bucketSize)
		{
			for(int i = 0; i < (bucketSize * primeNumber); i++)
			{
				if(head == nullptr)
					head = tail = new HashNode<KEY,INFO>();
				else
				{
					HashNode<KEY,INFO> *n = new HashNode<KEY,INFO>();
					n->next = head;
					head = n;
				}
			}
		}

		long getIndx(KEY key)
		{
			return hash(key) * bucketSize;
		}

		void add(HashNode<KEY,INFO> data)
		{
			long indx = getIndx(data.key);
			HashNode<KEY,INFO> temp(KEY(),INFO());
			for(int i = 0; i < bucketSize; i++)
			{
				if((data.key != temp.key) && (temp.key == head[indx + i].key))
				{
					head[indx + 1] = data;
					return;
				}
			}
			return;
		}

		HashNode*  HashTable::operator [] (const int indx)
		{
			HashNode<KEY,INFO> *n = head;
			for(int i = 1; i < indx; i++)
			{
				if(n == nullptr)
					return nullptr;
				n = n->next;
			}
			return n;
		}

		HashNode<KEY,INFO> *search(KEY key)
		{
			long indx = getIndx(key);
			for(int i = 0; i < bucketSize; i++)
			{
				if(head[indx + i].key == key)
					return head[indx + i];
			}
			return nullptr;
		}

		void print()
		{
			for(int i = 0; i < primeNumber; i++)
			{
				for(int j = 0; j < bucketSize; j++)
				{
					oss << head[i * bucketSize + j].info << endl;
				}
			}
		}

		~HashTable(void)
		{
		}
	};
}

