#ifndef  OHMYLIB_H
#define  OHMYLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_user_data
{
   char  email[50];
   char  user_id[60];
   char  university_id[5];
   char  major_id[44];
   int   statement;
}  t_user_data;

int   find_index(char c, char *str);
int   check_data(char *str, char c, int num);
int   init_data(char *str, t_user_data *data);
int   load_data(char *email, char *filename, t_user_data *data);
char  *keygen();
char  *encode(char *word, char *key);
void  reset_data(t_user_data *data);

#endif