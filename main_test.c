//#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


int	ft_printf(const char *str, ...);

int main()
{
	//char* test = "asd";
	char testchar = 'X';
	int a = ft_printf("lol %c rekt\n", testchar);
	int a2 = printf("lol %c rekt\n", testchar);
	int a3 = printf("my int is %i and C's int is %i\n \n", a, a2); //need newline \n so printf order is normal and not weird
	//int b = ft_printf("testing printf\n");
	char *str = "bananas";
	//int c = ft_printf("this is a string: %s (that was a string)\n", str);
	//write(1, "main finished\n", 15);
	//ft_printf("%s", test);
	int int1 = 1234;
	int int2 = -4321;
	int d = ft_printf("this is an int %i and another %d%%\n", int1, int2);
	int d2 = printf("this is an int %i and another %d%%\n", int1, int2);
	int d3 = printf("my int is %i and C's int is %i\n \n", d, d2);

	char * mystring = "i am string";
	int e = ft_printf("%s is at %p \n", mystring, mystring);
	int e2 = printf("%s is at %p \n", mystring, mystring);
	int e3 = printf("my int is %i and C's int is %i\n \n", e, e2);

	int nulos = printf(" NULL %s NULL \n", NULL);
	int mynulos = ft_printf(" NULL %s NULL \n", NULL);
	printf("my int is %i and C's int is %i\n \n", mynulos, nulos);
	
	int Cpointers = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	int mypointers = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("my int is %i and C's int is %i\n \n", mypointers, Cpointers);

	int Cp2 = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	int myp2 = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("my int is %i and C's int is %i\n \n", myp2, Cp2);

	int cp3 = printf(" %p %p \n", 0, 0);
	int myp3 = ft_printf(" %p %p \n", 0, 0);
	printf("my int is %i and C's int is %i\n \n", myp3, cp3);
}