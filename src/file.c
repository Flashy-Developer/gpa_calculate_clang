#include    "../includes/ohmylib.h"
#define     buff_size 160

unsigned int    count_line(char *filename)
{
    unsigned int    line;
    char            c;
    FILE            *file;

    file = fopen(filename, "r");
    if (!file)
        return (0);
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
    fclose(file);
}

int check_data(char *str, char c, int word_count)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    printf("count = %d\n", count);
    if (count == word_count)
        return (1);
    else
        return (0);
}

int init_data(char *str, t_user_data *data)
{
    char    *read_data;
    char    *rest = str;

    if (!check_data(str, ',', 4))
        return (0);
    read_data = strtok_s(rest, ",", &rest);
    strcpy(data->email, read_data);
    read_data = strtok_s(rest, ",", &rest);
    strcpy(data->user_id, read_data);
    read_data = strtok_s(rest, ",", &rest);
    strcpy(data->university_id, read_data);
    read_data = strtok_s(rest, ",", &rest);
    strcpy(data->major_id, read_data);
    read_data = strtok_s(rest, ",", &rest);
    data->statement = atoi(read_data);
    return (1);
}

int     load_data(char *email, char *filename, t_user_data *data)
{
    int     line;
    char    buff_read[buff_size];
    FILE    *file;

    line = count_line(filename);
    file = fopen(filename, "r");
    if (!file || !line)
        return (0);
    for (int i = 0; i < line; i++)
    {
        fgets(buff_read, buff_size - 1, file);
        if (!strncmp(email, buff_read, strlen(email)))
        {
            if(init_data(buff_read, data))
                return(1);
        }
    }
    fclose(file);
    return (0);
}