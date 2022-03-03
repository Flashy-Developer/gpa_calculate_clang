/**************************************************************/
/*                                                            */
/*    █▀▀ █▀█ ▄▀█  █▀▀ ▄▀█ █   █▀▀ █ █ █   ▄▀█ ▀█▀ █▀█ █▀█    */
/*    █▄█ █▀▀ █▀█  █▄▄ █▀█ █▄▄ █▄▄ █▄█ █▄▄ █▀█  █  █▄█ █▀▄    */
/*                                                            */
/**************************************************************/

#ifndef	OHMYLIB_H	/* check if not define ohmylib.h */
#define	OHMYLIB_H	/* define ohmylib.h */
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>

#ifdef _WIN32
# define clear()	system("cls")
#else
# define clear()	system("clear")
#endif

#define	FILENAME	"data.txt"

typedef struct	s_student_data
{
	char	student_id[11];
	char	subject[11][31];
	float	grade[11];
	float	credit[11];
}	t_student_data;

typedef struct	s_avg_data
{
	char	student_id[11];
	float	grade;
	float	credit;
}	t_avg_data;

int		calculate(void);
int		select_menu(void);
int		select_add_menu(void);
int		remove_data(char id[11]);
int		check_student_id(char *dest);
int		check_subject_grade(float *dest);
int		check_subject_credit(float *dest);
int		find_data(char *filename, char *user_id);
int		is_dup(char *subject_name, t_student_data data);
int		check_subject_name(char *dest, t_student_data data);
int		load_data(char *filename, char *user_id, t_student_data *data);
void	add_data();
void	print_welcome();
void	print_menu(void);
void	print_header(char *str);
void	show_grade(t_student_data *data);
void	reset_data(t_student_data *data);
void	print_color(char *str, unsigned char color);
void	write_file(char *filename, t_student_data stu_data);
void	calculate_grade(t_avg_data *dest, t_student_data src);

#endif
