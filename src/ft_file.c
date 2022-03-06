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

int	find_data(char *filename, char *user_id)
{
	char	buff[sizeof(t_student_data)];
	FILE	*file;

	file = fopen(filename, "r");
	if (!file)
		return (0);
	while (!feof(file))
	{
		fscanf(file, "%s\n", buff);
		if (!strncmp(buff, user_id, 10))
		{
			fclose(file);
			return (1);
		}
	}
	fclose(file);
	return (0);
}

int	load_data(char *filename, char *user_id, t_student_data *data)
{
	FILE	*file;
	char	*token;
	char	*ptrstr;
	char	buff[sizeof(t_student_data)];

	file = fopen(filename, "r");
	if (!file)
		return (0);
	while (!feof(file))
	{
		bzero(buff, sizeof(t_student_data));
		fscanf(file, "%s\n", buff);
		if (!strncmp(buff, user_id, 10))
			break;
	}
	fclose(file);
	if (strncmp(buff, user_id, 10))
		return (0);
	else
	{
		reset_data(data);
		ptrstr = buff;
		token = strtok_r(ptrstr, ",", &ptrstr);
		strcpy(data->student_id, token);
		for (size_t i = 0; token && i < 10; i++)
		{
			token = strtok_r(ptrstr, ",", &ptrstr);
			if (!strcmp(token, "-"))
				break ;
			strcpy(data->subject[i], token);
			token = strtok_r(ptrstr, ",", &ptrstr);
			data->grade[i] = atof(token);
			token = strtok_r(ptrstr, ",", &ptrstr);
			data->credit[i] = atof(token);
		}
		return (1);
	}
}
