#include	"../includes/ohmylib.h"

int	main(void)
{
	t_student_data	data;
	t_avg_data		data_avg;
	reset_data(&data);
	if (read_file("add_grade.txt", "6430200789", &data))
	{
		show_grade(&data);
		calculate_grade(&data_avg, data);
		printf("%.2f\n",data_avg.grade);
		printf("%.2f\n",data_avg.credit);

	}
	else
		puts("NOTFOUND!!");
	return (0);
}
