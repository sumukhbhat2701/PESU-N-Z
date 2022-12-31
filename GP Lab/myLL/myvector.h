#ifndef MYVECTOR_H
#define MYVECTOR_H
// inner class :
//	a) hide the class
//		implementation class
//	b) implementation of the inner class is associated with that of the outer class
class Node
{
	int val;
	Node* next;
	friend class myList;
};
typedef Node node_t;
class myList
{
	public:
	explicit myList();
	~myList();
	// contextual keyword
	myList(const myList&) = delete;
	myList& operator=(const myList&) = delete;
	// class within a class
	// indicates a position
	// opaque object
	//	!= ==
	//  * : deferencing operator : rvalue usage
	//  ++ : pre and post
	class myiterator
	{
		public:
		explicit myiterator(node_t* ptr = nullptr) : ptr_(ptr) { } 
		int operator*() const { return ptr_->val; }
		bool operator==(const myiterator& rhs) const
		{
			return ptr_ == rhs.ptr_;
		}
		// canonical way of writing inequality
		// != should call ==
		bool operator!=(const myiterator& rhs) const
		{
			return !(*this == rhs);
		}
		myiterator& operator++() // pre incr
		{
			ptr_ = ptr_->next;
			return *this;
		}
		myiterator operator++(int) // post incr
		{
			myiterator temp(*this);
			++*this;
			return temp;
		}
		private:
		node_t* ptr_;
	};
	myiterator begin()
	{
		return myiterator(head_);
	}
	myiterator end()
	{
		return myiterator(tail_);
	}
	private:
	node_t* head_;
	node_t* tail_;
	
};
#endif

