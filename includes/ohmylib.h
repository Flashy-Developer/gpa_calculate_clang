/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohmylib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:46:01 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/25 17:46:01 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OHMYLIB_H	/* check if not define ohmylib.h */
#define	OHMYLIB_H	/* define ohmylib.h */
# define clear() system("clear")
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>

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

int		check_student_id(char *dest);
int		check_subject_grade(float *dest);
int		check_subject_credit(float *dest);
int		check_str(char *dest, size_t size);
int		calculate_grade(t_avg_data *dest, t_student_data src);
int		load_data(char *raw_data, char *user_id, t_student_data *data);
int		read_file(char *filename, char *user_id, t_student_data *data);
void	show_grade(t_student_data *data);
void	reset_data(t_student_data *data);
void	add_grade(t_student_data *stu_data);
void	print_file(char *filename, t_student_data *stu_data);

#endif
