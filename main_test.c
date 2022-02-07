#include "ft_printf.h"

int main()
{
	//char* test = "asd";
	char testchar = 'X';
	int a = ft_printf("lol %c rekt\n", testchar);
	int b = ft_printf("testing printf\n");
	char *str = "bananas";
	int c = ft_printf("this is a string: %s (that was a string)\n", str);
	write(1, "main finished\n", 15);
	//ft_printf("%s", test);
	int int1 = 1234;
	int int2 = -4321;
	int d = ft_printf("this is an int %i and another %d%%\n", int1, int2);
	return 0;
}