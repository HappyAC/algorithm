#include<cstdio>

void reverseList(int list[],int start,int end){
    int mid = (start+end)/2;
    int tmp;
    for(int i = 0;i<=mid-start;i++){
        tmp = list[start+i];
        list[start+i]=list[end-i];
        list[end-i]=tmp;
    }
}

void printList(int list[],int n,char *tips){
    if(tips!=NULL) printf("%s ",tips);
    for(int i=0;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

void printList(int list[],int n){
    printList(list,n,NULL);
}

void moveListLeft(int list[],int n,int offset){
    // 1 2 3 4 5
    // 5 4 3 2 1
    // 3 4 5 1 2
    offset=offset%n;
    reverseList(list,0,n-1);
    reverseList(list,0,n-offset-1);
    reverseList(list,n-offset,n-1);
}
void moveListRight(int list[],int n,int offset){
    moveListLeft(list,n,n-offset);
}
int main(int n,char **args){
    int a[]={1,2,3,4,5};
    printList(a,5,"list:");
    reverseList(a,0,4);
    printList(a,5,"reversed:");
    moveListLeft(a,5,4);
    printList(a,5,"move left:");
    moveListRight(a,5,4);
    printList(a,5,"move right:");
}