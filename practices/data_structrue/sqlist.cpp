#include<cstdio>
#define print_list(list,len) printList(list,len,#list)
// 翻转顺序表（8）
void reverseList(int list[],int start,int end){
    int mid = (start+end)/2;
    int tmp;
    for(int i = 0;i<=mid-start;i++){
        tmp = list[start+i];
        list[start+i]=list[end-i];
        list[end-i]=tmp;
    }
}
// 打印顺序表
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

// 左移（10）
void shiftListLeft(int list[],int n,int offset){
    // 1 2 3 4 5
    // 5 4 3 2 1
    // 3 4 5 1 2
    offset=offset%n;
    reverseList(list,0,n-1);
    reverseList(list,0,n-offset-1);
    reverseList(list,n-offset,n-1);
}
// 右移
void shiftListRight(int list[],int n,int offset){
    shiftListLeft(list,n,n-offset);
}
// 寻找主元素（12）
int findMajority(int list[],int n){
    if(n==0) return -1;
    int cnt=1,c=list[0];
    
    for(int i = 1; i < n; i++)
    {
        if(list[i]==c){
            cnt++;
        }else{
            if(cnt>1){
                cnt--;                
            }else{
                cnt=1;
                c=list[i];
            }
        }
        printf("c: %d\n",c);
        
        if (cnt<=0) return -1;
        cnt=0;
        for(int i=0;i<n;i++){   
            // cnt=(list[i]==c)?cnt+1:cnt;  
            if (list[i]==c) {
                cnt++;
            }           
        }
        if(cnt>n/2) return c;
        return -1;
    }
    
}

int main(int n,char **args){
    int a[]={1,2,3,4,5};
    printList(a,5,"list:");
    reverseList(a,0,4);
    printList(a,5,"reversed:");
    shiftListLeft(a,5,4);
    printList(a,5,"move left:");
    shiftListRight(a,5,4);
    printList(a,5,"move right:");
    int b[]={0,5,5,3,5,7,5,5};
    int c[]={0,5,5,3,5,1,5,7};
    // printList(b,8,"b:");
    // printList(c,8,"c:");
    print_list(b,8);
    print_list(c,8);

    printf("marjority of b: %d\n",findMajority(b,8));
    printf("marjority of c: %d\n",findMajority(c,8));
}