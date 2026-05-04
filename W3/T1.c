#include <stdio.h>
#define MAXRAB 10001
#define ll long long
typedef struct rabbit {int foodcnt;int starttime;} rab;
int front,rear,count;

void initqueue(){front=1;rear=MAXRAB;count=0;}
int isempty(){return count==0;}
int isfull(){return count==MAXRAB;}
void enqueue(int queue[],int item){if(!isfull()){rear=(rear+1)%MAXRAB;queue[rear]=item;count++;}}
int dequeue(int queue[]){int e=0;if(!isempty()){e=queue[front];front=(front+1)%MAXRAB;count--;}return e;}

void bubblesort(rab info[],int num){
    for(int i=1;i<=num-1;i++){short ifswap = 0;
        for(int j=1;j<=num-i;j++){if(info[j].starttime > info[j+1].starttime){
                rab temp = info[j];info[j] = info[j+1];info[j+1] = temp;ifswap = 1;}}
        if(!ifswap){break;}}}

int main(){

    rab rabtable[MAXRAB]={};
    int queue[MAXRAB]={};
    ll totalfood=0;ll eatenfood=0;int nowrab=1;
    ll step=0;ll totalwaittime=0;
    initqueue();

    int rabbitsum;
    scanf("%d",&rabbitsum);
    for (int i=1;i<=rabbitsum;i++){scanf("%d",&rabtable[i].starttime);}
    for (int i=1;i<=rabbitsum;i++){scanf("%d",&rabtable[i].foodcnt);totalfood+=rabtable[i].foodcnt;}
    // bubblesort(rabtable,rabbitsum);

    while(eatenfood<totalfood){
        for(int i=nowrab;i<=rabbitsum;i++){if(rabtable[i].starttime == step && rabtable[i].foodcnt!=0){enqueue(queue,i);nowrab=i+1;}}
        if(isempty()){step++;continue;}
        totalwaittime+=count;
        int idx=queue[front];rabtable[idx].foodcnt--;eatenfood++;
        if(rabtable[idx].foodcnt==0){dequeue(queue);}
        else if(rabtable[idx].foodcnt>0){int temp = dequeue(queue);enqueue(queue, temp);}
        step++;
    }

    printf("%lld",totalwaittime);

    return 0;
}