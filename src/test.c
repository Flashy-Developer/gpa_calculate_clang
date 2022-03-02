#include	"../includes/ohmylib.h"		/* include library */

int check1()
{
	puts("check1");
	return (1);
}
int check2()
{
	puts("check2");
	return (2);
}

int main(void)
{
	if (check1() && check2())
		puts("check finish");
	return (0);
}
