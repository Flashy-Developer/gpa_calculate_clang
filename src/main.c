/*************************************************************/
/*                                                           */
/*   █▀▀ █▀█ ▄▀█ █ █▀▀ ▄▀█ █░░ █▀▀ █░█ █░░ ▄▀█ ▀█▀ █▀█ █▀█   */
/*   █▄█ █▀▀ █▀█ ▄ █▄▄ █▀█ █▄▄ █▄▄ █▄█ █▄▄ █▀█ ░█░ █▄█ █▀▄   */
/*                                                           */
/*************************************************************/

#include	"../includes/ohmylib.h"

int main(void)
{
	t_student_data	data;
	int				choice;

	clear();
	print_welcome();
	while (1)
	{
		while (!(choice = select_menu()))
		{
			clear();
			print_color("\nError, please Enter number 1 to 4 only!\n\n", 198);
		}
		switch (choice)
		{
			case 1:
				reset_data(&data);
				add_grade(&data);
				write_file(FILENAME, &data);
				break;

			case 2:
				calculate();
				break;

			case 3:
				remove_data();
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
