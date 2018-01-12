#include <io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printDir( const char* path )
{
    struct _finddata_t data;
    long hnd = _findfirst( path, &data );    // 查找文件名与正则表达式chRE的匹配第一个文件
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
             printf("%s\n",datee);
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
        FILE *fp;
             if((fp=fopen(n1,"w"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("REM GENRE ",fp);
             fputs(genre,fp);
             fputs("\n",fp);
             fputs("REM DATE ",fp);

             fputs(datee,fp);
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
    _findclose( hnd );     // 关闭当前句柄
}
/*void main()
{
    printDir("d:/C/T/*.*");
}

int main(int argc,char *argv[])
{
    printf(argv[0]);
    printDir("d:/C/T/*.*");
    return 0;
}*/

int main(int argc,char *argv[])
{
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
    system("pause");
    return 0;
}
