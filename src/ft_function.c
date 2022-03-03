#include	"../includes/ohmylib.h"

void	add_data()
{
	t_student_data	data;
	char			show_id[33]; bzero(show_id, 33);
	int				answer = 1;	/*	answer to continue	*/
	size_t			i;

	clear();
	reset_data(&data);
	print_header("Add Data");
	print_color("\nPlease Enter Student ID that you want to add data.\n\n", 43);

	while (!check_student_id(data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Add Data Student ID : %s", data.student_id);
	for(i = 0; i < 10 && answer == 1; i++)
	{
		clear();
		print_header(show_id);
		puts("");
		while (!check_subject_name(data.subject[i], data))
			print_color("Error, please Enter Subject name!\n(Maximum 30 Alphabet and not Duplicate)\n", 220);
		while (!check_subject_grade(&data.grade[i]))
			print_color("Error, please Enter Grade(float) only! (0.00 to 4.00)\n",220);
		while (!check_subject_credit(&data.credit[i]))
			print_color("Error, please Enter Credit(float) only! (0.00 to 10.00)\n",220);
		clear();
		print_header(show_id);
		puts("");
		show_grade(&data);
		puts("");
		while (!(answer = select_add_menu()))
			print_color("\nError, please Enter Y or N or A only!\n",220);
	}
	clear();
	if (answer == 2 || i == 10)
	{
		print_header(show_id);
		puts("");
		show_grade(&data);
		remove_data(data.student_id);
		write_file(FILENAME, data);
		print_color("\nAdd Data: Add Grade Complete!\n\n", 35);
	}
	else if (answer == 3)
	{
		print_header(show_id);
		puts("");
		print_color("\nAdd Data: Abort!\n\n", 35);
	}
}

int	calculate(void)
{
	t_student_data	data;
	t_avg_data		data_avg;
	char			show_id[38]; bzero(show_id, 38);

	clear();
	reset_data(&data);
	print_header("Calculate GPA");
	print_color("\nPlease Enter Student ID that you want to calculate.\n\n", 43);
	while (!check_student_id(data.student_id))
		print_color("Error, please Enter Student ID! (10 digit)\n", 220);
	sprintf(show_id, "Calculate GPA Student ID : %s", data.student_id);
	if (find_data(FILENAME, data.student_id) && load_data(FILENAME, data.student_id, &data))
	{
		clear();
		print_header(show_id);
		puts("");
		show_grade(&data);
		assign_grade(&data_avg, data);
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
	if (find_data(FILENAME, id))
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
