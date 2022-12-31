#ifndef MYVECTOR_H
#define MYVECTOR_H
// inner class :
//	a) hide the class
//		implementation class
//	b) implementation of the inner class is associated with that of the outer class
class Node
{
	Node(int val_) : val(val_), left(nullptr), right(nullptr) {} 
	int val;
	Node* left;
	Node* right;
	friend class myBST;
};
typedef Node node_t;
class myBST
{
	public:
	explicit myBST();
	~myBST();
	myBST(const myBST&) = delete;
	myBST& operator=(const myBST&) = delete;

	void insert(int key){
        node_t* node = new node_t(key);
        if(root_ == nullptr) {
            root_ = node;
            return;
        }
        node_t* prev = nullptr;
        node_t* temp = root_;
        while (temp!=nullptr)
		{
            if(temp->val > key)
			{
                prev = temp;
                temp = temp->left;
            }
            else
			{
                prev = temp;
                temp = temp->right;
            }
        }
        if(prev->val > key)
            prev->left = node;
        else 
			prev->right = node;
    }

	
	void DestroyRecursive(node_t* node);
	class myiterator
	{
		public:
		explicit myiterator(node_t* ptr = nullptr) : ptr_(ptr) { } 
		int operator*() const { return ptr_->val; }
		bool operator==(const myiterator& rhs) const
		{
			return ptr_ == rhs.ptr_;
		}


		bool operator!=(const myiterator& rhs) const
		{
			return !(*this == rhs);
		}
		myiterator& operator++() 
		{
			ptr_ = ptr_->getInorderSucc(ptr_);
			return *this;
		}
		myiterator operator++(int) 
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
		node_t* temp = root_;

		while(temp->left!=nullptr)
			temp = temp->left;
		return myiterator(temp);
	}
	myiterator end()
	{
		return myiterator(nullptr);
	}
	private:
	node_t* root_;	
};
#endif

