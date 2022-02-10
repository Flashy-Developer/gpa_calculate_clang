#include    "../includes/ohmylib.h"

char    *keygen()
{
    char    *key;
    char    base_key[] = "I8G467HQ9LFz0%wRT#dyY_ZShP@x!lij5D$^3UVWE&*1uvMrJXabCefnmopqgKO2AtNkcBs";

    key = (char *) malloc (sizeof(char) * 31);
    if (!key)
        return (0);
    for (int r = 0; r < 30; r++)
    {
        for (int i = 0; i < 30; i++)
            key[i] = base_key[rand() % strlen(base_key)];
    }
    key[30] = 0;
    return (key);
}

int     find_index(char c, char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
        return ((int) i);
    }
    return (-1);
}

char    *encode(char *word, char *key)
{
    //base    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$^&*%"
    char    base[] = "7H46&*153U_RbCefO2AlZShPwT#%kctNijWEIMrJXaQ9ymo@xLFzd!pK8GVuvBsYD$^0nqg";
    char    base_con[] = "I89!@x5LFGw67HQRY_ZSMrstNopqETuvAUVWyz0%P12BCefD$^3nhd4JXabcmgKO#&*lijk";
    char    *hash;
    int     i;

    hash = (char *) malloc (sizeof(char) * (strlen(word) + 1));
    if (!hash)
        return(0);

    for (i = 0; i < (int) strlen(word); i++)
    {
        int     code;
        code = i + find_index(word[i % strlen(word)], base) + find_index(key[i % strlen(key)], base);
        hash[i] = base_con[code % strlen(key)];
    }
    hash[i] = 0;
    return (hash);
}