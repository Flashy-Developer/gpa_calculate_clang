#include    "../includes/ohmylib.h"

char    *keygen();
char    *encode(char *username, char *usernum);

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