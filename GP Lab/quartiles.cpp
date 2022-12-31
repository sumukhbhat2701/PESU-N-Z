#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

// PES1UG19CS519 - Sumukh Raju Bhat

template<typename T>
void findQuartileRandomIterator(T begin, T end)
{
	T slow = begin;
	T fast2x = begin;
	T fast4x = begin;
	T fast3x = begin;
	while(fast4x != end)
	{
		++slow;
		fast2x = fast2x + 2;
		fast3x = fast3x + 3;
		fast4x = fast4x + 4;
	}
	
	cout << "Using Random Iterator:\n";
	cout << "First Quartile: " << *begin << " -> " << *(slow - 1) << endl;
	cout << "Second Quartile: " << *slow << " -> " << *(fast2x - 1) << endl;
	cout << "Third Quartile: " << *fast2x << " -> " << *(fast3x - 1) << endl;
	cout << "Fourth Quartile: " << *fast3x << " -> " << *(fast4x - 1) << "\n\n";
}

template<typename T>
void findQuartileForwardIterator(T begin, T end)
{
	T slow = begin;
	T fast2x = begin;
	T fast4x = begin;
	T fast3x = begin;
	fast4x++;
	fast4x++;
	fast4x++;
	fast4x++;
	while(fast4x != end)
	{
		++slow;
		++fast2x;
		++fast2x;
		++fast4x;
		++fast4x;
		++fast4x;
		++fast4x;
		++fast3x;
		++fast3x;
		++fast3x;
	}
	
	T temp = fast3x;
	T last;
	while(temp!=end)
	{
		last = temp;
		++temp;
	}
	++fast3x;
	
	
	cout << "Using Forward Iterator:\n";
	cout << "First Quartile: " << *begin << " -> " << *(slow++) << endl;
	cout << "Second Quartile: " << *slow << " -> " << *(++fast2x) << endl;
	cout << "Third Quartile: " << *(++fast2x) << " -> " << *(++fast3x) << endl;
	cout << "Fourth Quartile: " << *(++fast3x) << " -> " << *last << "\n\n";

}

template<typename T>
void findQuartileBidirectionalIterator(T begin, T end)
{
	T slow = begin;
	T fast2x = begin;
	T fast4x = begin;
	T fast3x = begin;
	while(fast4x != end)
	{
		++slow;
		++fast2x;
		++fast2x;
		++fast3x;
		++fast3x;
		++fast3x;
		++fast4x;
		++fast4x;
		++fast4x;
		++fast4x;
	}
	
	T copy1 = slow;
	copy1--;
	T copy2 = fast2x;
	copy2--;
	T copy3 = fast3x;
	copy3--;
	T copy4 = fast4x;
	copy4--;
	
	cout << "Using Bidirectional Iterator:\n";
	cout << "First Quartile: " << *begin << " -> " << *copy1 << endl;
	cout << "Second Quartile: " << *slow << " -> " << *copy2 << endl;
	cout << "Third Quartile: " << *fast2x << " -> " << *copy3 << endl;
	cout << "Fourth Quartile: " << *fast3x << " -> " << *copy4 << "\n\n";
}

int main()
{
	vector<int> v;
	list<int> l;
	forward_list<int> fl;
	
	for(int i = 0; i<100; i++)
	{
		v.push_back(i+1);
		l.push_back(i+1);
		fl.push_front(100 - i);
	}
	
	cout << "- Vector: \n" << endl; 
	findQuartileForwardIterator(v.begin(), v.end());
	findQuartileBidirectionalIterator(v.begin(), v.end());
	findQuartileRandomIterator(v.begin(), v.end());
	
	cout << "- List: \n" << endl;
	findQuartileForwardIterator(l.begin(), l.end());
	findQuartileBidirectionalIterator(l.begin(), l.end());
	cout << "List cannot have a Bidirectional iterator\n\n";
	// findQuartileRandomIterator(l.begin(), l.end());
	
	cout << "- Forward List: \n" << endl;
	findQuartileForwardIterator(fl.begin(), fl.end());
	cout << "Forward list cannot have a bidirectional or a Random iterator\n\n";
	// findQuartileBidirectionalIterator(fl.begin(), fl.end());
	// findQuartileRandomIterator(fl.begin(), fl.end());
	
	
	
	return 0;
}
