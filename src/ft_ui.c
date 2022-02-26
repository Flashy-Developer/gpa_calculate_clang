#include	"../includes/ohmylib.h"


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

	clear();
	for(size_t i = 0; i < 10 && *data->subject[i]; i++)
	{
		printf("\n------------- SUBJECT %ld -------------\n", i + 1);
		printf("Subject Name :\t\t%s\n", data->subject[i]);
		printf("Subject Grade :\t\t%.2f\n", data->grade[i]);
		printf("Subject Credit :\t%.2f\n", data->credit[i]);
	}
	printf("\n------------------------------------\n");
}

void	print_menu(void)
{
	printf("\x1b[38;5;81m-------- Select the Process --------\e[0m\n");
	printf("\n");
	printf("\t1: add data\n");
	printf("\t2: calculate data\n");
	printf("\t3: remove data\n");
	printf("\t4: exit\n");
	printf("\n------------------------------------\n");
	printf("\n");
}

int	select_menu(void)
{
	int	c;

	c = 0;
	print_menu();
	printf("Enter Choice : ");
	scanf("%d", &c);
	if (1 <= c && c <= 4)
		return (c);
	else
		return (0);
}
