#include <stdio.h>
#define MAXSIZE 100
int top;
// char stack[82]={};
void initstack(){top=-1;}
int isempty(){return top==-1;}
int isfull(){return top==(MAXSIZE-1);}
char pop(char stack[]){if(!isempty()){return stack[top--];}return 'N';}
void push(char stack[],char item){if(!isfull()){stack[++top]=item;}}

int main(){

    char c;int cnt=0;
    char things[82]={};char stack[82]={};
    while((c=getchar())!=EOF ){things[cnt]=c;cnt++;}
    things[cnt]='\0';
    // printf("%s",things);
    initstack();

    for (int i=0;i<cnt;i++){
        if(things[i]>='0' && things[i]<='9'){printf("%c",things[i]);}
        else if(things[i]=='('){push(stack,things[i]);}
        else if(things[i]=='*' || things[i]=='/'){
            char token=pop(stack);
            if(token=='N'){push(stack,things[i]);continue;}
            while(token =='*' || token=='/'){
                printf("%c",token);
                token=pop(stack);
            }
            if(token!='N'){top++;}
            push(stack,things[i]);
        }
        else if(things[i]=='+' || things[i]=='-'){
            char token=pop(stack);
            while(token!='N'){
                if(token == '('){top++;break;}
                while(token!='N' && token!='('){printf("%c",token);token=pop(stack);}
            }

            push(stack,things[i]);
        }
        else if (things[i]==')'){
            char token=pop(stack);
            while(token!='(' && token!='N'){printf("%c",token);token=pop(stack);}
        }

        // printf("  stack%d:",i);
        // for(int j=0;j<=top;j++){
        //     printf("%c",stack[j]);
        // }
        // printf("\n");
    }

    while(!isempty()){char token=pop(stack);printf("%c",token);}

    return 0;
}