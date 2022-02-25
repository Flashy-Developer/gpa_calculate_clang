#include	"../includes/ohmylib.h"

int	main(void)
{
	t_student_data	data;
	reset_data(&data);
	if (read_file("add_grade.txt", "6430200850", &data))
		show_grade(&data);
	else
		puts("NOTFOUND!!");
	return (0);
}
