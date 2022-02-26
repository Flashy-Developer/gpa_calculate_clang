#include	"../includes/ohmylib.h"

void print_file(char *filename, t_student_data *stu_data)
{
	FILE *fp_add_grade;
	fp_add_grade=fopen(filename,"a+");
	fprintf(fp_add_grade,"%s",stu_data->student_id);
	fprintf(fp_add_grade,",");
	for(size_t i = 0; i < 10; i++)
	{
		if(*stu_data->subject[i])
		{
			fprintf(fp_add_grade,"%s",stu_data->subject[i]);
			fprintf(fp_add_grade,",");
			fprintf(fp_add_grade,"%.2f",stu_data->grade[i]);
			fprintf(fp_add_grade,",");
			fprintf(fp_add_grade,"%.2f",stu_data->credit[i]);
		}
		else
			fprintf(fp_add_grade,"-,-,-");
		if (i < 9)
			fprintf(fp_add_grade,",");
	}
	fprintf(fp_add_grade,"\n");
    fclose(fp_add_grade);
}

int	load_data(char *raw_data, char *user_id, t_student_data *data)
{
	char	*ptr_str;
	char	*token;

	ptr_str = raw_data;
	token = strtok_r(ptr_str, ",", &ptr_str);
	if (!strcmp(user_id, token))
	{
		strcpy(data->student_id, token);
		for (size_t i = 0; token && i < 10; i++)
		{
			token = strtok_r(ptr_str, ",", &ptr_str);
			if (*token == '-')
				break ;
			strcpy(data->subject[i], token);
			token = strtok_r(ptr_str, ",", &ptr_str);
			data->grade[i] = atof(token);
			token = strtok_r(ptr_str, ",", &ptr_str);
			data->credit[i] = atof(token);
		}
		return (1);
	}
	return (0);
}

int	read_file(char *filename, char *user_id, t_student_data *data)
{
	char	buff[sizeof(t_student_data) + 10 + 1];	// size of struct t_student_data + size of float(char) x 2 + end byte
	int		found;
	FILE	*file;

	found = 0;
	file = fopen(filename, "r");
	if (!file)
		return (0);
	while (!feof(file) && !found)
	{
		fscanf(file, "%s\n", buff);
		found = load_data(buff, user_id, data);
	}
	fclose(file);
	return (found);
}

void	remove_data()
{
	FILE	*new_file, *old_file;
	char 	buff_file[] = "buff.txt";
	char	buff[sizeof(t_student_data) + 10 + 1];	// size of struct t_student_data + size of float(char) x 2 + end byte
	char	id[11];

	while (!check_student_id(id))
		printf("\x1b[38;5;220mError, please Enter Student ID!\e[0m\n");

	rename(FILENAME, buff_file);
	old_file = fopen(buff_file, "r");
	new_file = fopen(FILENAME, "w+");
	while (!feof(old_file))
	{
		fscanf(old_file, "%s\n", buff);
		if (strncmp(id, buff, 10))	// if string id and buff is equal it will return 0 (False)
			fprintf(new_file, "%s\n", buff);
	}
	fclose(old_file);
	fclose(new_file);
	remove(buff_file);
}
