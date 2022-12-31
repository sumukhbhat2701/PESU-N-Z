#include <iostream>
using namespace std;
#include "myvector.h"

class Add
{
	public:
	int operator()(int x, int y) { return x + y; }
};
// ptr_t should support :
//	!= ==
//  * : deferencing operator : rvalue usage
//  ++ : pre and post
template<typename ptr_t>
void display(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		cout << *first << '\t'; 
		++first;
	}
	cout << endl;
}
template<typename T, typename  ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op)
{
#if 1
	while(first != last)
	{
		init = op(init, *first); 
		++first;
	}
#endif
	return init;
}
int main()
{
	myBST v;
	display(v.begin(), v.end());	
	// cout << acc3(v.begin(), v.end(), 0, Add()) << "\n";
}
