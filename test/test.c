#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

typedef struct s_user_data
{
   char  email[50];
   char  user_id[48];
   char  university_id[5];
   char  major_id[11][4];
}  t_user_data;

typedef struct s_user_payment
{
   char  user_id[48];
   int   statement;
}  t_user_payment;

unsigned int    count_line(FILE *file)
{
    unsigned int    line;
    char            c;

    line = 1;
    while (1)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        else if (c == '\n')
            line += 1;
    }
    return (line);
}

int     load_data(char *email, char *filename)
{
    int             line;
    FILE            *file;
    t_user_data     buff;

    file = fopen(filename, "r");
    if (!file)
        return (0);
    line = count_line(file);
    fclose(file);

    file = fopen(filename, "r");
    for (int i = 0; i < line; i++)
    {
        fscanf(file, "%s , %s , %s", buff.email, buff.user_id, buff.university_id);
        if (!strcmp(email, buff.email))
        {
            printf("email = %s\n", buff.email);
            printf("user = %s\n", buff.user_id);
            printf("university = %s\n", buff.university_id);
            return (1);
        }
    }
    fclose(file);
    return (0);
}

int     main(void)
{
    printf("%d", load_data("peakungg@gmail.com", "text.txt"));
    return (0);
}