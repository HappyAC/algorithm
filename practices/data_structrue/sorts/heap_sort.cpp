#include<cstdio>
#define DATA_TYPE int

/**
 * @brief swap a and b
 * (a,b) => (b,a)
 * */
void swap(DATA_TYPE &a,DATA_TYPE &b){
    DATA_TYPE tmp = b;
    b=a;
    a=tmp;
}

/**
 * compare a and b
 * */
bool cmp(DATA_TYPE a,DATA_TYPE b,bool isAsc){
    return isAsc?a<b:a>b;
}
/**
 * adjust heap node by ascending or descending
 * this heap array should start with index 0
 * */
void adjustHeapNode(DATA_TYPE arr[],int i,int len,bool isAsc){
    int k=i;
    // LeftChild : 2k+1
    // RightChild: 2k+2
    while(k*2+1<len){
        int selectChildIndex = 2*k+1;
        if(selectChildIndex+1<len&&cmp(arr[selectChildIndex],arr[selectChildIndex+1],isAsc)){
            selectChildIndex++;
        }
        if(cmp(arr[k],arr[selectChildIndex],isAsc)){
            swap(arr[k],arr[selectChildIndex]);
            k=selectChildIndex;
            continue;
        }
        break;
    }
    
}

/**
 * heap sort
 * */
void heapsort(DATA_TYPE arr[],int len,bool isAsc){
    // build max heap    
    for(int i = (len-1)/2; i >=0; i--)
    {
        adjustHeapNode(arr,i,len,isAsc);
    }
    // swap and sort
    for(int i = len-1; i >=1;i--)
    {
        swap(arr[0],arr[i]);
        len--;
        adjustHeapNode(arr,0,len,isAsc);
    }
}
void heapSort(DATA_TYPE arr[],int len){
    heapsort(arr,len,true);
}

void heapSortDesc(DATA_TYPE arr[],int len){
    heapsort(arr,len,false);
}

int main(int argc, char const *argv[])
{
    DATA_TYPE arr[]={7,2,9,5,4,39,45,1,7,6,98,2,6,2,1,44,8};
    heapSortDesc(arr,17);
    for(int i = 0; i < 17; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
