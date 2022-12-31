#include <iostream>
using namespace std;
template<typename T>
struct X
{
	using F = int;
};

struct F;

template<uint32_t a, uint32_t b>
struct LCM
{
	static constexpr uint32_t val = (a == b) ?  (a) : ((a > b) ? (LCM<a-b,b>::val) : (LCM<a,b-a>::val));
};
template<typename T, typename F>
void f(T x, F y)
{
}

template<>
void f<int>(int x, int y)
{

}

void j(int&)
{
	std::cout << "&";
}

void j(const int&)
{
}

int h(int x)
{
	return x;
}


class A
{
	public: int a;
	A(int a_) : a(a_) {}
	virtual void f() { std::cout << "hello"; };
};

class B: public A
{
	public: int a;
	B(int a_) : a(a_), A(10) {}
	void f() {A::f(); std::cout << "world" ;};
};

void f(int&) {}

void f(const int&) {}

template <uint32_t I, uint32_t Value>
struct SqrtImpl {
  using T = typename conditional<((I * I) < Value), SqrtImpl<I + 1, Value>, integral_constant<uint32_t, I> >::type;
  static constexpr uint32_t value = T::value;
};




int main()
{
  
	
	
	std::cout << LCM<5,15>::val;
 
}

#if 0
#include <cstdio>

int main()
{
  const int arr[10] = {2, 4, 6, 8, 0, 0, 0, 0, 0, 0};
  int g;
    
  class __lambda_7_14
  {
    public: 
    inline /*constexpr */ void operator()() const
    {
    }
    
    private: 
    const int arr[10];
    
    public:
    __lambda_7_14(const int const (&_arr)[10])
    : arr{_arr}
    {}
    
  };
  
  __lambda_7_14 x = __lambda_7_14{{arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]}};
  x.operator()();
  return 0;
}


#endif
