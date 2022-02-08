#include    <stdio.h>
#include    <stdlib.h>

char    *keygen();
char    *encode(char *username, char *usernum);

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

int   main(void)
{
   char  name[] = "Pongsakorn TIPPAYASOMDECH";
   char  num[] = "!Pea222613284907102545!";
   char  *key;

   printf("hash = %s\n", encode(name, num));
   for (int i = 0; i < 5; i++)
   {
      key = keygen();
      printf("key = %s\n", key);
   }
   return (0);
}