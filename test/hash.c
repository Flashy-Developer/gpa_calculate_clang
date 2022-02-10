#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>

unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 9431;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

/*int main(void)
{
    const char  word[] = "ptippaya";

    printf("%d\n", hash(word));
    return (0);
}*/