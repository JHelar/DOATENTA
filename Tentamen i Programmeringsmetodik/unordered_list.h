#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace U4{

	struct Node
	{
		string info;
		int infoInt;
		Node *next;

		Node(void)
		{
			this->next = nullptr;
			this->infoInt = 0;
		}

		Node(string info, int infoInt)
		{
			this->infoInt = infoInt;
			this->info = info;
			this->next = nullptr;
		}
	};
class unordered_list
{
	class Iterator
	{
	public:
		typedef Iterator self_type;
		typedef Node value_type;
		typedef Node& reference;
		typedef Node* pointer;
		typedef forward_iterator_tag iterator_category;
		typedef int difference_type;

		Iterator(pointer ptr)
		{
			this->ptr_ = ptr;
		}

		self_type operator++() 
		{
			self_type i = *this; 
			ptr_=ptr_->next; 
			return i;
		}

		self_type operator++(int junk)
		{
			ptr_=ptr_->next; 
			return *this;
		}

		reference operator*()
		{
			return *ptr_;
		}

		pointer operator->()
		{
			return ptr_;
		}

		bool operator==(const self_type& rhs)
		{
			return ptr_ == rhs.ptr_;
		}

		bool operator != (const self_type& rhs)
		{
			return ptr_ != rhs.ptr_;
		}

	private:
		pointer ptr_;
	};

private:
	Node *head;
	Node *freeHead;

	public:

		unordered_list(void)
		{
			head = freeHead = nullptr;
		}

		unordered_list(int size_free_list)
		{
			for(int i = 0; i < size_free_list; i++)
			{
				if(freeHead == nullptr)
					freeHead = new Node();
				else
				{
					Node *temp = new Node();
					temp->next = this->freeHead;
					this->freeHead = temp;
				}
			}
		}

		void swap(Node *one, Node *another)
		{
			string temp = one->info;
			int tempInt = one->infoInt;
			one->info = another->info;
			one->infoInt = another->infoInt;
			another->infoInt = tempInt;
			another->info = temp;
		}

		void sort()
		{
			for(Node *iter = head; iter != nullptr; iter = iter->next)
			{
				Node *min = iter;
				for(Node *iterB = iter; iterB != nullptr; iterB = iterB->next)
				{
					if(iterB->info < iter->info)
					{
						min = iterB;
					}
				}
				swap(iter,min);
			}
		}

		Node * getFreeNode()
		{
			if(freeHead != nullptr)
			{
				Node *n = freeHead->next;
				Node *returnNode = freeHead;
				delete freeHead;
				freeHead = n;
				return returnNode;
			}
			else
				return nullptr;
		}

		bool find(string info)
		{
			Node *n = head;
			while (n != nullptr)
			{
				if(n->info == info)
					return true;
				n = n->next;
			}
			return false;
		}

		Node * findNode(string info)
		{
			Node *n = head;
			while (n != nullptr)
			{
				if(n->info == info)
					return n;
				n = n->next;
			}
			return nullptr;
		}

		void increaseInfoIntToNode(string info)
		{
			Node *n = findNode(info);
			if(n != nullptr)
				n->infoInt += 1;
		}

		void add(string info, int infoInt)
		{
			if(freeHead == nullptr && head == nullptr)
			{
				head = new Node(info,infoInt);
				head->next = nullptr;
			}
			else
			{
				if(head == nullptr)
				{
					head = getFreeNode();
					if(head == nullptr)
					{
						head = new Node(info,infoInt);
						head->next = nullptr;
					}
					head->next = nullptr;
				}
				else
				{
					Node *n = getFreeNode();
					if(n == nullptr)
					{
						n = new Node(info,infoInt);
						n->next = head;
					}
					else
					{
						n->next = head;
					}
					head = n;
				}
			}
		}

		void delete_header_node()
		{
			if(head == nullptr)
				return;
			else
			{
				Node *n = freeHead;
				if(n == nullptr)
				{
					freeHead = head;
					delete head;
					head = nullptr;
				}
				else
				{
					while (n != nullptr)
					{
						n = n->next;
					}
					n = head;
					delete head;
					head = nullptr;
				}
			}
		}


		void clear()
		{
			if(head == nullptr)
				return;
			else
			{
				Node *n = head;
				while(n != nullptr)
				{
					if(freeHead == nullptr)
					{
						freeHead = n;
						head = nullptr;
					}
					else
					{
						Node *t = freeHead->next;
						if(t == nullptr)
							t = n;
					}
					n = n->next;
				}
			}
		}

		~unordered_list(void)
		{
			Node *n = new Node();
			Node *d = new Node();
			if(head != nullptr)
			{
				n = head;
				d = n;
				while(n != nullptr)
				{
					d = n;
					n = n->next;
					delete d;
				}
			}
			if(freeHead != nullptr)
			{
				n = freeHead;
				d = n;
				while(n != nullptr)
				{
					d = n;
					n = n->next;
					delete d;
				}
			}
		}

		void print()
		{
			Node *n = head;
			while (n != nullptr)
			{
				cout << n->info << n->infoInt << endl;
				n = n->next;
			}
		}

		Iterator begin()
		{
			return Iterator(head);
		}

		Iterator end()
		{
			return Iterator(nullptr);
		}
	};
}

