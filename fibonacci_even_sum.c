#include <stdio.h>

int brute(int n)
{
	int a=1, b=1, c;
	int sum=0;
	
	for(;a<=n;)
	{
		if(a%2 == 0)
			sum+=a;

		c=a+b;
		a=b;
		b=c;
	}
	return sum;
}

int optimized(int n)
{
	int prev = 0;
	int curr = 2;
	int sum = 0;
	int next; 

	while(curr <= n)
	{
		sum += curr;

		next = 4*curr + prev;
		prev = curr;
		curr = next;
	}
	return sum;
}

int main()
{
	int n;
	
	printf("Enter n: ");
	scanf("%d", &n);

	printf("Brute force: %d\n", brute(n));
	printf("Optimized Sum: %d\n", optimized(n));

	return 0;
}
