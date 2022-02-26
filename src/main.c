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
			/*	print color \x1b[38;5;{color code [octa]}m{text}\e[0m\n	*/
			printf("\x1b[38;5;198mError, please Enter number 1 to 4 only!\e[0m\n\n");
		}
		switch (choice)
		{
			case 1:
				clear();
				printf("\x1b[38;5;39m####################### ADD data #######################\e[0m\n\n");
				add_grade(&data);
				print_file(FILENAME, &data);
				break;

			case 2:
				clear();
				printf("\x1b[38;5;39m#################### CALCULATE data ####################\e[0m\n\n");
				if (!calculate())
					printf("\x1b[38;5;220mNot Found!!, Please Enter data or Try again!\e[0m\n");
				break;

			case 3:
				clear();
				printf("\x1b[38;5;39m###################### Remove data #####################\e[0m\n\n");
				remove_data();
				break;

			case 4:
				clear();
				printf("\x1b[38;5;84mExiting Program\e[0m\n");
				exit(0);

			default:
				break;
		}
	}
	return(0);
}
