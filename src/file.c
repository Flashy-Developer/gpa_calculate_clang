#include    "../includes/ohmylib.h"

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

int load_data(char *str, t_user_data *data)
{
    char    *read_data;
    char    *rest = str;

    if (!check_data(str, ',', 4))
        return (2);
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

int find_data(char *email, char *filename, t_user_data *data)
{
    char    buff_read[sizeof(t_user_data)];
    FILE    *file;

    file = fopen(filename, "r");
    if (!file)
        return (0);
    while (!feof(file))
    {
        fscanf(file, "%s", buff_read);
        if (!strncmp(email, buff_read, strlen(email)))
            return(load_data(buff_read, data));
    }
    fclose(file);
    return (0);
}

int    remove_broken_data(char *filename)
{
    char    buff_read[sizeof(t_user_data)];
    char    file_buff[] = "buff_read.txt";
    FILE    *file_read;
    FILE    *file_write;

    rename(filename, file_buff);
    file_read = fopen(file_buff, "r");
    file_write = fopen(filename, "w+");
    if (!file_read)
    {
        fclose(file_read);
        fclose(file_write);
        return (0);
    }
    while (!feof(file_read))
    {
        fscanf(file_read, "%s\n", buff_read);
        printf("%s$\n", buff_read);
        if (check_data(buff_read, ',', 4))
            fprintf(file_write, "%s\n", buff_read);
    }
    fclose(file_read);
    fclose(file_write);
    if(remove(file_buff))
        return (1);
    else
        return (0);
}