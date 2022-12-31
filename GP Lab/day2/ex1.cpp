#include<iostream>
using namespace std;
void foo(int a)
{
    cout << "int" << endl;
}
void foo(double a)
{
    cout << "double" << endl;
}
void foo(char c)
{
    cout << "double" << endl;
}
int main()
{
    int a = 1;
    double b = 2.3;
    char c = 'f';
    foo(c);
    return 0;
}