#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Node{
    struct BST_Node *left;
    struct BST_Node *right;
    int num;
    int cnt;}* node;

node insert(node root,int val){
    if(!root){
        root = (node) malloc(sizeof(struct BST_Node));
        root->num = val;
        root->left = NULL;
        root->right = NULL;
        root->cnt = 1;
        return root;
    }
    if(val > root->num ){root->right = insert(root->right,val);}
    else if(val < root->num ){root->left = insert(root->left, val);}
    else if(val == root->num){root->cnt++;}
    return root;
}

node create(node root,int table[],int total){
    for(int i=0;i<total;i++){root = insert(root, table[i]);}
    return root;
}

void zxbl(node root){
    if(root==NULL){return;}
    zxbl(root->left);
    printf("%d %d\n",root->num,root->cnt);
    zxbl(root->right);
}

int main(){
    int totalcnt;
    int numtable[10000]={};
    node ttroot=NULL;
    // int a[7]={23,23,4,44,32,17,20};
    scanf("%d",&totalcnt);
    for(int i=0;i<totalcnt;i++){scanf("%d",&numtable[i]);}
    ttroot = create(ttroot, numtable, totalcnt);
    zxbl(ttroot);
    return 0;
}
