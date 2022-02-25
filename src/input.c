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

int	check_student_id(char *dest)
{
	char	id[11];
	size_t	i;

	printf("Enter Student ID : ");
	scanf("%s", id);
	for (i = 0; i < 10; i++)
		if (!isdigit(id[i]))
			return (0);
	strcpy(dest, id);
	return (1);
}

int	check_subject_grade(float *dest)
{
	char	src[21];
	size_t	i;

	i = 0;
	printf("Enter Subject Grade : ");
	scanf("%s", src);
	for (i = 0; i < 21 && src[i]; i++)
		if (!(isdigit(src[i]) || src[i] == '.'))
			return (0);
	if (*src)
	{
		*dest = atof(src);
		if (0 <= *dest && *dest <= 4)
			return (1);
		else
			*dest = 0;
	}
	return (0);
}

int	check_subject_credit(float *dest)
{
	char	src[21];
	size_t	i;

	i = 0;
	printf("Enter Subject Credit : ");
	scanf("%s", src);
	for (i = 0; i < 21 && src[i]; i++)
		if (!(isdigit(src[i]) || src[i] == '.'))
			return (0);
	if (*src)
	{
		*dest = atof(src);
		if (0 <= *dest && *dest <= 10)
			return (1);
		else
			*dest = 0;
	}
	return (0);
}

int	check_str(char *dest, size_t size)
{
	char	*buffer;

	buffer = (char *) malloc (sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	printf("Enter Subject Name : ");
	scanf("%s", buffer);
	if (size < strlen(buffer))
	{
		free(buffer);
		return (0);
	}
	else
	{
		strcpy(dest, buffer);
		free(buffer);
		return (1);
	}
}

void	show_grade(t_student_data *data)
{
	for(size_t i = 0; i < 10 && *data->subject[i]; i++)
	{
		printf("Subject Name %ld : %s \n",i+1,data->subject[i]);
		printf("Subject %ld Grade : %.2f \n",i+1,data->grade[i]);
		printf("Subject %ld Credit : %.2f \n",i+1,data->credit[i]);
	}
}

void	add_grade(t_student_data *stu_data)
{
	char	answer;		/*	answer to continue	*/

	answer = 0;
	while (!check_student_id(stu_data->student_id))
		printf("Error Try again!\n");
	printf("Student ID : %s\n", stu_data->student_id);

	for(size_t i = 0; i < 10; i++)
	{
		while (!check_str(stu_data->subject[i], 30))
			printf("Error Try again!\n");
		printf("Subject %ld : %s\n", i+1,stu_data->subject[i]);
		while (!check_subject_grade(&stu_data->grade[i]))
			printf("Error Try again!\n");
		while (!check_subject_credit(&stu_data->credit[i]))
			printf("Error Try again!\n");
		clear();
		do
		{
			show_grade(stu_data);
			printf("Would you like to add more subject (Y/N) ?:\n");
			answer = tolower(getchar());
			clear();
		}
		while (tolower(answer) != 'n' && tolower(answer) != 'y');
		if (answer == 'n')
			break;
	}
	show_grade(stu_data);
}
