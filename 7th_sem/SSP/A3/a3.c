#include<stdio.h>
#define mod 1000000
int main()
{
	long long int f = 1;
	long long int s = 0;
	int arr[mod];
	for(long long int n = 0; n < mod; ++n)
	{
		// printf("%lldth fibonicci number = %lld\n", n+1, f%mod);
		// arr[n] = (arr[n-1]%mod + arr[n-2]%mod)%mod;
		f = (f%mod + s%mod)%mod;
		s = f;
	}
	return 0;
}
