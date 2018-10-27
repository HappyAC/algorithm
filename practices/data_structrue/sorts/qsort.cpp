#include<cstdio>

int partition(int arr[],int start,int end){
    int p = arr[start];
    
    while(start<end){
        while(start<end&&arr[end--]>=p);
        arr[start]=arr[end];
        while(start<end&&arr[start++]<=p);
        arr[end]=arr[start];
    }
   arr[start]=p; 
   printf("%d",start);
   return start;
}

void qsort(int arr[],int start,int end){
    int p =partition(arr,start,end);
    qsort(arr,start,p-1);
    qsort(arr,p+1,end);
}

int main(int argc, char const *argv[])
{
    int a[]={8,1,8,6,4,7,2,3,4};
    qsort(a,0,8);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}
