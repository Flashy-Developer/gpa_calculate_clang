#include	"../includes/ohmylib.h"

void	reset_data(t_student_data *data)
{
	memset(data->student_id, 0, 11);
	for (size_t i = 0; i < 10; i++)
	{
		memset(data->subject[i], 0, 31);
		data->grade[i] = 0;
		data->credit[i] = 0;
	}
}

void	add_grade(t_student_data *stu_data)
{
	char	answer;		/*	answer to continue	*/

	answer = 0;
	while (!check_student_id(stu_data->student_id))
		printf("\x1b[38;5;220mError, please Enter Student ID!\e[0m\n");
	printf("Student ID : %s\n", stu_data->student_id);

	for(size_t i = 0; i < 10; i++)
	{
		while (!check_str(stu_data->subject[i], 30))
			printf("\x1b[38;5;220mError, please Enter Subject name!\e[0m\n");
		printf("Subject %ld : %s\n", i+1,stu_data->subject[i]);
		while (!check_subject_grade(&stu_data->grade[i]))
			printf("\x1b[38;5;220mError, please Enter float only!\e[0m\n");
		while (!check_subject_credit(&stu_data->credit[i]))
			printf("\x1b[38;5;220mError, please Enter float only!\e[0m\n");
		clear();
		do
		{
			show_grade(stu_data);
			printf("\nWould you like to add more subject (Y/N) ?:\n");
			answer = tolower(getchar());
			clear();
		}
		while (tolower(answer) != 'n' && tolower(answer) != 'y');
		if (answer == 'n')
			break;
	}
	show_grade(stu_data);
}

void calculate_grade(t_avg_data *dest, t_student_data src)
{
	size_t	i;
	float	total;
	float	credit;

	credit = 0;
	total = 0;
	i = 0;
	while (i < 10 && src.subject[i][0] != 0)
	{
		total += (src.grade[i] * src.credit[i]);
		credit += src.credit[i];
		i++;
	}
	strcpy(dest->student_id, src.student_id);
	dest->grade = total / credit;
	dest->credit = credit;
}

int	calculate(void)
{
	t_student_data	data;
	t_avg_data		data_avg;

	reset_data(&data);
	while (!check_student_id(data.student_id))
		printf("\x1b[38;5;220mError, please Enter Student ID!\e[0m\n");
	if (read_file(FILENAME, data.student_id, &data))
	{
		show_grade(&data);
		calculate_grade(&data_avg, data);
		printf("\n");
		printf("Average Grade\t= %.2f\n",data_avg.grade);
		printf("Total credit\t= %.2f\n",data_avg.credit);
		printf("\n");
		return (1);
	}
	else
		return (0);
}
