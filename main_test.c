#include "ft_printf.h"

int main()
{
	//char* test = "asd";
	char testchar = 'X';
	int a = ft_printf("lol %c rekt\n", testchar);
	int b = ft_printf("testing printf\n");
	write(1, "main finished\n", 15);
	//ft_printf("%s", test);
	return 0;
}