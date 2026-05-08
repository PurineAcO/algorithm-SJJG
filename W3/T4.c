#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int parent;
} *node;

int find_index(node nodes, int count, int id) {
    for (int i = 0; i <= count; i++) {if (nodes[i].id == id) return i;}
    return -1;
}

node initlist(int total){
    node list = (node) malloc((total+2)*sizeof(struct Node));
    list[0].id=1;
    list[0].parent=0;
    return list;
}

node addlist(node list,int cnt,int id){
    list[cnt].id=id;
    list[cnt].parent=0;
    return list;
}

int main() {

    int total;int cnt=1;
    scanf("%d", &total);

    node list = initlist(total);

    for (int i = 0; i < total; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(find_index(list, cnt, x) == -1) {list = addlist(list,cnt,x);cnt++;}
        if(find_index(list, cnt, y) == -1) {list = addlist(list,cnt,y);cnt++;}
        list[find_index(list,cnt,y)].parent=x;
    }

    int s, t,cur;
    scanf("%d %d", &s, &t);

    int path_s[1000], ps = 0;cur=s;
    while (cur != 0) {path_s[ps++] = cur;cur = list[find_index(list,total,cur)].parent;}

    int path_t[1000], pt = 0;cur = t;
    while (cur != 0) {path_t[pt++] = cur;cur = list[find_index(list,total,cur)].parent;}

    int i = ps - 1, j = pt - 1;
    while (i >= 0 && j >= 0 && path_s[i] == path_t[j]){i--;j--;}
    int lca = path_s[i+1];

    int dist_s = 0;cur = s;
    while (cur != lca) {dist_s++;cur = list[find_index(list,total,cur)].parent;}

    int dist_t = 0;cur = t;
    while (cur != lca) {dist_t++;cur = list[find_index(list,total,cur)].parent;}

    printf("%d\n", dist_s + dist_t);
    free(list);
    return 0;
}