#include	"../includes/ohmylib.h"

int main(void)
{
	t_student_data	data;
	reset_data(&data);
	add_grade(&data);
	print_file("add_grade.txt", &data);
	printf("\x1b[38;5;43m\nstop the program\n\e[0m");
	return(0);
}
