#include	"../includes/ohmylib.h"

void	print_color(char *str, unsigned char color)
{
	printf("\x1b[38;5;%dm%s\e[0m", color, str);
}

void	print_header(char *str)
{
	char	text[66];
	int		color_arr[6] = {69, 105 ,141, 177 ,213};

	bzero(text, 66);
	text[64] = '\n';
	memset(text, '*', 64);
	print_color(text, color_arr[0]);

	bzero(text, 63);
	memset(text, ' ', 64);
	text[0] = '*';
	text[63] = '*';
	print_color(text, color_arr[1]);

	strncpy(text + (64 - strlen(str)) / 2, str, strlen(str));
	print_color(text, color_arr[2]);

	memset(text, ' ', 63);
	text[0] = '*';
	text[63] = '*';
	print_color(text, color_arr[3]);

	memset(text, '*', 63);
	print_color(text, color_arr[4]);
}

int	check_student_id(char *dest)
{
	char	id[31];

	printf("Enter Student ID : ");
	scanf("%s", id);
	if (strlen(id) != 10)
		return (0);
	for (size_t i = 0; i < 10; i++)
		if (!isdigit(id[i]))
			return (0);
	strcpy(dest, id);
	return (1);
}

int	check_subject_name(char *dest)
{
	char	buffer[51];

	bzero(buffer, 51);
	printf("Enter Subject Name :\t");
	scanf("%s", buffer);
	if (strlen(buffer) > 30)
		return (0);
	else
	{
		strcpy(dest, buffer);
		return (1);
	}
}

int	check_subject_grade(float *dest)
{
	char	src[21];

	printf("Enter Subject Grade :\t");
	scanf("%s", src);
	for (size_t i = 0; i < 21 && src[i]; i++)
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

	printf("Enter Subject Credit :\t");
	scanf("%s", src);
	for (size_t i = 0; i < 21 && src[i]; i++)
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

void	print_menu(void)
{
	print_color("---------------------- Select the Process ----------------------\n", 81);
	printf("\n");
	printf("\t1: Add Data\n");
	printf("\t2: Calculate GPA\n");
	printf("\t3: Remove Data\n");
	printf("\t4: exit\n");
	print_color("\n----------------------------------------------------------------\n", 81);
	printf("\n");
}

int	select_menu(void)
{
	char	str[31];
	int		c;

	c = 0;
	bzero(str, 31);
	print_menu();
	printf("Enter Choice : ");
	scanf("%s", str);
	for (size_t i = 0; i < 31 && str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	c = atoi(str);
	if (1 <= c && c <= 4)
		return (c);
	return(0);
}

void	show_grade(t_student_data *data)
{
	for(size_t i = 0; i < 10 && *data->subject[i]; i++)
	{
		printf("-------------------------- SUBJECT %d ---------------------------\n", (int) i + 1);
		printf("Subject Name :\t\t%s\n", data->subject[i]);
		printf("Subject Grade :\t\t%.2f\n", data->grade[i]);
		printf("Subject Credit :\t%.2f\n\n", data->credit[i]);
	}
	printf("----------------------------------------------------------------\n");
}

#ifndef _WIN32
void	print_welcome()
{
	char LOADING[] = "\n\n\
                █   █▀█ ▄▀█ █▀▄ █ █▄ █ █▀▀\n\
                █▄▄ █▄█ █▀█ █▄▀ █ █ ▀█ █▄█ ▄ ▄ ▄\n\n\n";
	char GPA_CALCULATOR[] = "\n\n\
      █▀▀ █▀█ ▄▀█  █▀▀ ▄▀█ █   █▀▀ █ █ █   ▄▀█ ▀█▀ █▀█ █▀█\n\
      █▄█ █▀▀ █▀█  █▄▄ █▀█ █▄▄ █▄▄ █▄█ █▄▄ █▀█  █  █▄█ █▀▄\n\n\n";

	clear();
	print_color(LOADING, 214);
	system("sleep 0.6");
	clear();
	print_color(GPA_CALCULATOR, 162);
}

#else
void print_welcome()
{
	print_header("GPA CALCULATOR");
}
#endif
