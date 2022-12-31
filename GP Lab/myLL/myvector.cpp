#include <iostream>
using namespace std;
#include "myvector.h"
/*
class myvector
{
	public:
	myvector(int n);
	private:
	int *p_;
	int n_;
};
*/
myList::myList()
: head_(nullptr), tail_(nullptr)
{
	// init : some initialization for testing
	for(int i = 0; i < 5; ++i)
	{
		node_t* new_ = new node_t;
		new_->val = i*i;
		new_->next = nullptr;
		if(head_ == nullptr)
		{
			head_ = new_;
			tail_ = new_;
		}
		else
		{
			tail_->next = new_;
			tail_ = tail_->next;
		}
	}
	node_t* new_ = new node_t;
	new_->val = -1;
	new_->next = nullptr;
	tail_->next = new_;
	tail_ = tail_->next;
	
}
myList::~myList()
{
	node_t* temp = head_;
	while(temp!=NULL)
	{
		node_t* t = temp->next;
		delete temp;
		temp = t;
	}
}





