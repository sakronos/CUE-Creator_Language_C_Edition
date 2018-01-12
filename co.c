#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
void printDir( const char* path )
{
    struct _finddata_t data;
    long hnd = _findfirst( path, &data );
    if ( hnd < 0 )
    {
        perror( path );
    }
    int  nRet = (hnd <0 ) ? -1 : 1;
    char genre[10];
    char datee[8];
    char title[50];
    char perf[30];

    FILE *fp2;
             if((fp2=fopen("REM GENRE.txt","r"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fgets(genre,16,fp2);
             fclose(fp2);

    FILE *fp3;
             if((fp3=fopen("REM DATE.txt","r"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fscanf(fp3,"%s",datee);
        /*
        */
             fclose(fp3);

    FILE *fp4;
             if((fp4=fopen("TITLE.txt","r"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fgets(title,512,fp4);
             fclose(fp4);

    FILE *fp5;
             if((fp5=fopen("PERFORMER of TRACK.txt","r"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fgets(perf,64,fp5);
             fclose(fp5);

    while ( nRet >= 0 )
    {
        char n1[50],n2[50],*p1;
        strcpy(n1,data.name);
        p1=n1;
        while(*p1)
            p1++;
        p1--;
        *p1--='\0';
        *p1--='\0';
        *p1--='\0';
        *p1='\0';
        strcpy(n2,n1);
        strcat(n1,".cue");
        FILE *fp6;
             if((fp6=fopen(n1,"w"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("REM DATE ",fp6);
             fputs(datee, fp6);
             fputs("\n",fp6);
             fclose(fp6);
        FILE *fp;
             if((fp=fopen(n1,"a"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("REM GENRE ",fp);
             fputs(genre,fp);
             fputs("\n",fp);
             fputs("TITLE \"",fp);
             fputs(title,fp);
             fputs("\"\n",fp);
             fputs("FILE \"",fp);
             fputs(data.name,fp);
             fputs("\" WAVE\n",fp);
             fputs("  TRACK 01 AUDIO\n",fp);
             fputs("    TITLE \"",fp);
             fputs(n2,fp);
             fputs("\"\n",fp);
             fputs("    PERFORMER \"",fp);
             fputs(perf,fp);
             fputs("\"\n",fp);
             fputs("    INDEX 01 00:00:00",fp);
        fclose(fp);
        //printf("%s\n", data.name );
        //printf("%s\n",n2);
        //printf("%s\n",date);
        /*
        */
        nRet = _findnext( hnd, &data );
    }
    _findclose( hnd );
}

int main(int argc,char *argv[])
{
    if ( !access("info.txt",0) )
         {
             puts("EXISITS!");
             char ch[300],ch0[10];
             strcpy(ch,argv[0]);
             char *p=ch;
             while(*p)
             p++;
             p--;
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p='\0';
    strcpy(ch0,"*.wav");
    strcat(ch,ch0);
            printDir(ch);
            if (remove("info.txt") == 0);
            else
            perror("remove");
            if (remove("REM GENRE.txt") == 0);
            else
            perror("remove");
            if (remove("REM DATE.txt") == 0);
            else
            perror("remove");
            if (remove("TITLE.txt") == 0);
            else
            perror("remove");
            if (remove("PERFORMER of TRACK.txt") == 0);
            else
            perror("remove");

         }
    else
         {
             puts("BUILD or ERROR");
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
