#include	"../includes/ohmylib.h"

int main(void)
{
	t_student_data	data;
	reset_data(&data);
	add_grade(&data);
	print_file(&data);
	printf("stop the program\n");
	return(0);
}
