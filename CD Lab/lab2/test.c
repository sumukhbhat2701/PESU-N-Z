#include<stdio.h>
#include<string.h>
void f(char* s)
{
	strcpy(s, "printf");
}
int main()
{
	char s[] = "hello";
	f(s);
	return 0;
}
