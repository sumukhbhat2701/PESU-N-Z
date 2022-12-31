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
myBST::myBST()
: root_(nullptr)
{
	// init : some initialization for testing
	int arr[] = {10, 5, 50, 2, 60, 70, 15};
	for(int i = 0; i<7; ++i)
	{
		insert(arr[i]);
	}
}


void myBST::DestroyRecursive(node_t* node)
{
    if(node)
    {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}

myBST::~myBST()
{
    DestroyRecursive(root_);
}





