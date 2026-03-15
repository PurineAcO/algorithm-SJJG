#include <stdio.h>
#include <string.h>
#define max(a,b) a>b ?  a:b

int main(){

    int mhplace;
    scanf("%d",&mhplace);
    getchar();
    freopen("listin.txt", "r", stdin);
    char word[114514]={};char c;int cnt=0;
    while((c=getchar())!=EOF){word[cnt]=c;cnt++;}
    word[cnt]='\0';
    
    // printf("%d",mhplace);
    // printf("%s",word);

    int isword=0;int wordnum=0;int wordcnt=0;int hang=1;
    char worddic[114514][50]={};
    int mhmap[10000]={};
    int hhmap[10000]={};
    for(int i=0;i<strlen(word);i++){
        if(word[i]!=' ' && word[i]!='\t' && word[i]!=':' && word[i]!='\n'){isword=1;worddic[wordnum][wordcnt]=word[i];wordcnt++;}
        else {
            if(isword==1){wordnum++;wordcnt=0;isword=0;}
            if(word[i]==':'){mhmap[hang]=wordnum;}
            if(word[i]=='\n'){hhmap[hang]=wordnum;hang++;}
        }
    }

    // printf("---\n");
    // for(int j=0;j<wordnum;j++){printf("%s",worddic[j]);
    //     printf(" ");
    // }
    // printf("%d ",hang);
    // for(int i=1;i<=hang;i++){printf("%d ",mhmap[i]);}
    // for(int i=1;i<=hang;i++){printf("%d ",hhmap[i]);}

    freopen("listout.txt","w",stdout);

    int printcnt=0;int printhang=1;int thishangbeforemh=0;
    while(printcnt<=wordnum){
        printf("%s ",worddic[printcnt]);
        thishangbeforemh+=strlen(worddic[printcnt]);
        // printf("%d",thishangbeforemh);
        printcnt++;
        if (printcnt==mhmap[printhang]){
            for(int k=1;k<=mhplace-thishangbeforemh-(mhmap[printhang]-hhmap[max(printhang-1,0)]+1);k++){printf(" ");}
            printf(": ");}
        if (printcnt==hhmap[printhang]){printf("\n");printhang++;thishangbeforemh=0;}
    }


    return 0;
}
