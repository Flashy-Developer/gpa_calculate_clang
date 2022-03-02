#include	"../includes/ohmylib.h"

void	write_file(char *filename, t_student_data stu_data)
{
	FILE *fp_add_grade;
	fp_add_grade = fopen(filename,"a+");
	fprintf(fp_add_grade, "%s", stu_data.student_id);
	fprintf(fp_add_grade, ",");
	for(size_t i = 0; i < 10; i++)
	{
		if(*stu_data.subject[i])
		{
			fprintf(fp_add_grade, "%s", stu_data.subject[i]);
			fprintf(fp_add_grade, ",");
			fprintf(fp_add_grade, "%.2f", stu_data.grade[i]);
			fprintf(fp_add_grade, ",");
			fprintf(fp_add_grade, "%.2f", stu_data.credit[i]);
		}
		else
			fprintf(fp_add_grade, "-,-,-");
		if (i < 9)
			fprintf(fp_add_grade, ",");
	}
	fprintf(fp_add_grade, "\n");
	fclose(fp_add_grade);
}

int	find_data(char *filename, char *user_id, t_student_data *data)
{
	char	buff[sizeof(t_student_data)];
	int		found;
	FILE	*file;

	found = 0;
	file = fopen(filename, "r");
	if (!file)
		return (0);
	while (!feof(file) && !found)
	{
		fscanf(file, "%s\n", buff);
		if (!*buff)
			return (found);
		else
			found = load_data(buff, user_id, data);
	}
	fclose(file);
	return (found);
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
	else
		return (0);
}
