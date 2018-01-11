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
             FILE *fp11;
             fp11=fopen("info.txt","w");
             if(fp11==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fclose(fp11);

             FILE *fp12;
             fp12=fopen("REM GENRE.txt","w");
             if(fp12==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fclose(fp12);

             FILE *fp13;
             fp13=fopen("REM DATE.txt","w");
             if(fp13==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fclose(fp13);

             FILE *fp14;
             fp14=fopen("TITLE.txt","w");
             if(fp14==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fclose(fp14);

             FILE *fp15;
             fp15=fopen("PERFORMER of TRACK.txt","w");
             if(fp15==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fclose(fp15);

         }
    return 0;
}
