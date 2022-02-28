#include	"../includes/ohmylib.h"

int main(void)
{
	t_student_data	data;
	int				choice;

	clear();
	reset_data(&data);
	while (1)
	{
		while (!(choice = select_menu()))
		{
			clear();
			print_color("Error, please Enter number 1 to 4 only!\n", 198);
		}
		switch (choice)
		{
			case 1:
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
