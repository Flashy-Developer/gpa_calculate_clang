#include    "../includes/ohmylib.h"
#define     buff_size 160

void    reset_data(t_user_data *data)
{
    //  set all data to NULL
    strcpy(data->email, "\0");
    strcpy(data->user_id, "\0");
    strcpy(data->university_id, "\0");
    strcpy(data->major_id, "\0");
    data->statement = 0;
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
    char    buff_read[buff_size];
    FILE    *file;

    file = fopen(filename, "r");
    if (!file)
        return (0);
    while (!feof(file))
    {
        fscanf(file, "%s", buff_read);
        if (!strncmp(email, buff_read, strlen(email)))
        {
            init_data(buff_read, data);
            return(1);
        }
    }
    fclose(file);
    return (0);
}