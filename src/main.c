/**************************************************************/
/*                                                            */
/*    █▀▀ █▀█ ▄▀█  █▀▀ ▄▀█ █   █▀▀ █ █ █   ▄▀█ ▀█▀ █▀█ █▀█    */
/*    █▄█ █▀▀ █▀█  █▄▄ █▀█ █▄▄ █▄▄ █▄█ █▄▄ █▀█  █  █▄█ █▀▄    */
/*                                                            */
/**************************************************************/

#include	"../includes/ohmylib.h"		/* include library */

int main(void)
{
	int	choice;

	clear();
	print_welcome();
	while (1)
	{
		while (!(choice = select_menu()))
		{
			print_color("\nError, please Enter number 1 to 4 only!\n\n", 198);
		}
		switch (choice)
		{
			case 1:
				add_data();
				break;

			case 2:
				calculate();
				break;

			case 3:
				remove_data("");
				break;

			case 4:
				print_color("\nExit Program!\n\n", 43);
				exit(0);

			default:
				break;
		}
	}
	return(0);
}
