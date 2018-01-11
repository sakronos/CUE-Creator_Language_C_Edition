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

    FILE *fp2;
             if((fp2=fopen("info.txt","r"))==NULL)     //先改为读入此文件，再将其中的句子写入新文件
             {
                 printf("cannot open file \n");
                 exit(0);
             }

             fclose(fp2);
    while ( nRet >= 0 )
    {
        char n1[50];
        strcpy(n1,data.name);
        strcat(n1,".cue");
        FILE *fp;
             if((fp=fopen(n1,"w"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("FILE \"",fp);
             fputs(data.name,fp);
             fputs("\" WAVE\n",fp);
             fputs("  TRACK 01 AUDIO\n",fp);
             fputs("    TITLE \"",fp);
        fclose(fp);
        //printf("%s\n", data.name );
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
