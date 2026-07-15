#include <stdio.h>

int my_strlen (const char *str)
{
	int count =0;
	
	while(str[count] != '\0')
	{
		count++;
	}

	return count;
}

int main()
{
	char str[100];
	printf("Enter the string: ");
	scanf("%99s", str);

	printf("The length of %s is : %d\n", str, my_strlen(str));
       
	return 0;
}	
