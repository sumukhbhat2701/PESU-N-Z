#include <iostream>
#include <vector>

// PES1UG19CS519 - Sumukh Raju Bhat
using namespace std;

template<typename T>
class IteratorRange
{
	T begin_;
	T end_;
	public:
		IteratorRange(T begin, T end)
		: begin_(begin), end_(end) { }

	template<typename V, typename U>
	friend class Filter;
};

template<typename T, typename U>
class Filter
{
	IteratorRange<T> I;
	bool (*callable_)(U);
	public:
		Filter(IteratorRange<T> i, bool (*callable)(U))
		: I(i), callable_(callable) {}
		T operator++()
		{
			while(I.begin_ != I.end_ && !callable_(*(I.begin_)))
			{
				I.begin_++;
			}
			T temp(I.begin_);
			if(I.begin_ != I.end_)
				I.begin_++;
			return temp;
		}
		T operator++(int x)
		{
			T temp(I.begin_);
			++*this;
			return temp;
		}
};

bool is_even(int x)
{
	return (x%2 == 0)?true:false;
}

int main()
{
	int a[] = {1, 21, 3, 41, 5, 61, 7, 81, 9, 10, 100, 60};
	IteratorRange<int*> i(a, a+10);
	Filter<int*, int> f(i, is_even);
	int* it = ++f;
	if(it != a+10)
	{
		cout << *it << endl;
	}

	vector<int> v{1, 21, 3, 41, 50, 61, 7, 81, 9, 10, 100, 60};
	IteratorRange<vector<int>::iterator> i1(v.begin(), v.end());
	Filter<vector<int>::iterator, int> f1(i1, is_even);
	vector<int>::iterator it1 = ++f1;
	while(it1 != v.end())
	{
		cout << *it1 << endl;
		it1 = ++f1;
	}
	
	
	return 0;
}
