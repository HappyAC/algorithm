#include<cstdio>
#include<queue>

int *cloneArr;

void swap(int *a,int *b){
    // printf("%d,%d=>",*a,*b);
    int tmp = *a;
    *a=*b;
    *b=tmp;
//    printf("%d,%d\n",*a,*b);
}

bool diff(int *baseArr,int *newArr,int index){
    return baseArr[index]==newArr[index];
}

void clone(int arr[],int n){
    if(cloneArr){
        delete cloneArr;
    }
    cloneArr=new int[n];
    
    for(int i = 0; i < n; i++)
    {
        cloneArr[i]=arr[i];
    }
    
}

void printArr(int arr[],int n){
    
    for(int i = 0; i < n; i++)
    {
        if(!diff(cloneArr,arr,i)){
            printf("%d* ",arr[i]);
        }else{
            printf("%d  ",arr[i]);
        }
    }
    printf("\n");   
}
int partion(int s,int e,int arr[],int n){
    int mid = arr[s],i=s,j=e;
    // 5  8  4  6  3  7  9  2
    // 2* 8  4  6  3  7  9  2
    // 2  8  4  6  3  7  9  8*
    // 2  3* 4  6  3  7  9  8
    // 2  3  4  6  6* 7  9  8*
    while(i<j){    
        while(i<j&&arr[j]>=mid) j--;
            clone(arr,n);
            arr[i]=arr[j];
            printArr(arr,n);
        while(i<j&&arr[i]<=mid) i++;
            clone(arr,n);
            arr[j]=arr[i];
            printArr(arr,n);   
    }
    clone(arr,n);
    arr[i]=mid;
    printArr(arr,n); 
    return i;   
}
void qsort(int arr[],int s,int e,int n){
    if(s>=e) return;
    std::queue<int> ses;
    ses.push(s);
    ses.push(e);
    
    while(ses.size()>0){
        int start = ses.front();
        ses.pop();
        int end = ses.front();
        ses.pop();
        if(start>=end) continue;
        int k = partion(start,end,arr,n);
        ses.push(start);
        ses.push(k-1);
        ses.push(k+1);
        ses.push(end);
    }
}
int main(int argc, char const *argv[])
{
    int arr[]={5,6,8,9,4,3,5};
    qsort(arr,0,6,7);
    printArr(arr,7); 
    return 0;
}
