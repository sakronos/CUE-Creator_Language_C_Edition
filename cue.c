#include <stdio.h>
#include <io.h>
#include <stdlib.h>
int main()
{
    if ( !access("info.txt",0) )
         {
             puts("EXISITS!");
             //

         }
    else
         {
             puts("DOESN'T EXISIT!");
             FILE *fp;
             fp=fopen("info.txt","w");
             if(fp==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("REM GENRE \n",fp);
             fputs("REM DATE \n",fp);
             fputs("TITLE \" \"\n",fp);
             fputs("PERFORMERofTRACK ",fp);
             fclose(fp);
         }
    return 0;
}
