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

void	add_grade()
{
	t_student_data stu_data;
	char	answer;		/*	answer to continue	*/
	char	show_id[35]; bzero(show_id, 35);

	clear();
	reset_data(&stu_data);
	print_header("Add Grade");
	print_color("\nPlease Enter Student ID that you want to add data.\n", 43);
	print_color("*if you have added Grade with same ID, You MUST Delete Grade before!\n\n", 191);

	answer = 'y';
	while (!check_student_id(stu_data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Add Grade Student ID : %s", stu_data.student_id);

	for(size_t i = 0; i < 10 && answer == 'y'; i++)
	{
		clear();
		print_header(show_id);
		puts("");
		while (!check_subject_name(stu_data.subject[i]))
			print_color("Error, please Enter Subject name! (Maximum 30 Alphabet)\n", 220);
		while (!check_subject_grade(&stu_data.grade[i]))
			print_color("Error, please Enter Grade(float) only! (0.00 to 4.00)\n",220);
		while (!check_subject_credit(&stu_data.credit[i]))
			print_color("Error, please Enter Credit(float) only! (0.00 to 10.00)\n",220);
		do
		{
			clear();
			print_header(show_id);
			puts("");
			show_grade(&stu_data);
			printf("\nWould you like to add more subject (Y/N) ?:\n");
			answer = tolower(getchar());
		}
		while (answer != 'n' && answer != 'y' && i + 1 < 10);
	}
	clear();
	print_header(show_id);
	puts("");
	show_grade(&stu_data);
	write_file(FILENAME, stu_data);
	print_color("\nAdd Grade Complete!\n\n", 35);
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
	char			show_id[40];

	clear();
	print_header("Calculate Grade");
	print_color("\nPlease Enter Student ID that you want to calculate.\n\n", 43);
	reset_data(&data);
	while (!check_student_id(data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Calculate Grade Student ID : %s", data.student_id);
	if (find_data(FILENAME, data.student_id, &data))
	{
		clear();
		print_header(show_id);
		puts("");
		show_grade(&data);
		calculate_grade(&data_avg, data);
		printf("\n");
		printf("Average Grade\t= %.2f\n",data_avg.grade);
		printf("Total credit\t= %.2f\n",data_avg.credit);
		printf("\n");
		return (1);
	}
	else
	{
		print_color("\nID Not Found!!, Please Add Grade before!\n\n", 198);
		return (0);
	}
}

int	remove_data()
{
	t_student_data	temp;
	FILE			*new_file, *old_file;
	char 			buff_file[] = "buff.txt";
	char			buff[sizeof(t_student_data) + 10 + 1];	// size of struct t_student_data + size of float(char) x 2 + end byte
	char			id[11]; bzero(id, 11);

	clear();
	print_header("Remove Grade");
	print_color("\nPlease Enter Student ID that you want to Delete data.\n\n", 43);

	while (!check_student_id(id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	if (find_data(FILENAME, id, &temp))
	{
		rename(FILENAME, buff_file);
		old_file = fopen(buff_file, "r");
		new_file = fopen(FILENAME, "w+");
		if (!old_file || !new_file)
		{
			fclose(old_file);
			return (0);
		}
		while (!feof(old_file))
		{
			fscanf(old_file, "%s\n", buff);
			if (strncmp(id, buff, 10))	// if string id and buff is equal it will return 0 (False)
				fprintf(new_file, "%s\n", buff);
		}
		fclose(old_file);
		fclose(new_file);
		remove(buff_file);
		print_color("\nRemove Data Complete!\n\n", 43);
	}
	else
		print_color("\nData not found, You may not delete.\n\n", 191);
	return (1);
}
