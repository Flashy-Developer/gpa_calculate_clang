#include	"../includes/ohmylib.h"

void	reset_data(t_student_data *data)
{
	bzero(data->student_id, 11);
	for (size_t i = 0; i < 10; i++)
	{
		bzero(data->subject[i], 31);
		data->grade[i] = 0;
		data->credit[i] = 0;
	}
}

void	add_data()
{
	t_student_data	data;
	char			answer;		/*	answer to continue	*/
	char			show_id[33]; bzero(show_id, 33);
	size_t			i;

	clear();
	reset_data(&data);
	print_header("Add Data");
	print_color("\nPlease Enter Student ID that you want to add data.\n\n", 43);

	answer = 'y';
	while (!check_student_id(data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Add Data Student ID : %s", data.student_id);
	for(i = 0; i < 10 && answer == 'y'; i++)
	{
		clear();
		print_header(show_id);
		puts("");
		while (!check_subject_name(data.subject[i]))
			print_color("Error, please Enter Subject name! (Maximum 30 Alphabet)\n", 220);
		while (!check_subject_grade(&data.grade[i]))
			print_color("Error, please Enter Grade(float) only! (0.00 to 4.00)\n",220);
		while (!check_subject_credit(&data.credit[i]))
			print_color("Error, please Enter Credit(float) only! (0.00 to 10.00)\n",220);
		do
		{
			clear();
			print_header(show_id);
			puts("");
			show_grade(&data);
			printf("\nWould you like to add more subject (Y/N) ? or Abort(A):\n");
			answer = tolower(getchar());
		}
		while (answer != 'n' && answer != 'y' && answer != 'a' && i + 1 < 10);
	}
	clear();
	if (answer == 'n' || i == 10)
	{
		print_header(show_id);
		puts("");
		show_grade(&data);
		remove_data(data.student_id);
		write_file(FILENAME, data);
		print_color("\nAdd Data: Add Grade Complete!\n\n", 35);
	}
}

void	calculate_grade(t_avg_data *dest, t_student_data src)
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
	char			show_id[38]; bzero(show_id, 38);

	clear();
	print_header("Calculate GPA");
	print_color("\nPlease Enter Student ID that you want to calculate.\n\n", 43);
	reset_data(&data);
	while (!check_student_id(data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Calculate GPA Student ID : %s", data.student_id);
	if (find_data(FILENAME, data.student_id, &data))
	{
		clear();
		print_header(show_id);
		puts("");
		show_grade(&data);
		calculate_grade(&data_avg, data);
		puts("");
		printf("Average Grade\t= %.2f\n", data_avg.grade);
		printf("Total credit\t= %.2f\n", data_avg.credit);
		puts("");
		return (1);
	}
	else
	{
		print_color("\nCalculate GPA: ID Not Found!!, Please Add Data before!\n\n", 198);
		return (0);
	}
}

int	remove_data(char *id)
{

	t_student_data	temp;
	int				status = 0;
	FILE			*new_file, *old_file;
	char 			buff_file[] = "buff.txt";
	char			buff[sizeof(t_student_data)];

	if (!*id) /* *id == id[0] */
	{
		clear();
		print_header("Remove Data");
		print_color("\nPlease Enter Student ID that you want to Delete data.\n\n", 43);

		id = (char *) malloc (sizeof(char) * 11);
		if (!id)
			return (0);
		while (!check_student_id(id))
			print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	}
	else
		status = 1;
	if (find_data(FILENAME, id, &temp))
	{
		remove(buff_file);
		rename(FILENAME, buff_file);
		old_file = fopen(buff_file, "r");
		new_file = fopen(FILENAME, "w+");
		if (!old_file || !new_file)
		{
			fclose(old_file);
			fclose(new_file);
			return (0);
		}
		while (!feof(old_file))
		{
			fscanf(old_file, "%s\n", buff);
			if (strncmp(id, buff, 10))
				fprintf(new_file, "%s\n", buff);
		}
		fclose(old_file);
		fclose(new_file);
		remove(buff_file);
		if (!status)
			print_color("\nRemove Data: Remove Old Data Complete!\n\n", 43);
	}
	else
		if (!status)
			print_color("\nRemove Data: Old Data not found, You may not delete.\n\n", 191);
	return (1);
}
