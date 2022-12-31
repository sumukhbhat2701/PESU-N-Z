#include<iostream>
#include<concepts>
using namespace std;





/*
void f(int& x)
{
	cout << "&x" << endl;
}

void f(int&& x)
{
	cout << "&& x" << endl;
}

*/

void f(int& x)
{
	cout << "const& x" << endl;
}

void f(const int x)
{
}

int& g(int& x)
{
	cout << x;
	return x;
	
}

template<typename T>
void l(T a[], T n)  // converted to void l(T* a, T n)
{
	for(int i = 0; i<n; ++i)
		cout << a[i];
}

template<int N>
struct fact
{
	constexpr static int res = N*fact<N-1>::res;
};

template<>
struct fact<0>
{
	constexpr static int res = 1;
};

int r(...)
{
	return 0;
}

template<typename G>
void l(...)
{
	cout << "G";
}

template<typename T>
void l(T x)
{
	cout << "T: " << x;
}



int main()
{
	/*f(2);
	int x = 3;
	//f(x);
	g(x) = 5;
	cout << x; */
	
	int a = 5;
	char* p = (char*)&a;
	
	//cout << sizeof(r());
	r(2,3.4,5,6,5,6,9);
	//cout << fact<5>::res;
	l(2);
	
	function<int(int, int)> f = [](int x, int y){ return x; };
	cout << f(2,3);

	
	
	
}
