#include<stdio.h>
#define N 65535 // 这里 N!=301，陷阱
#define K 100
// 标记数组
int marks[N]={0};
// 存储输入的数字
int inputNums[K];

// 验证数字并标记他的验证序列
void checkNumAndMark(int num){
    marks[num]=marks[num]+1;
    while(num!=1){
        if(num%2==0){
            num/=2;
        }else{
            num=(num*3+1)/2;
        }
        // the key to solving this problem
        marks[num]=marks[num]+1;
        printf("%d ",num);
    }
}

// 验证该数字是否为输入的数字
bool isInputNum(int num,int inputNumsLen){
    for(int i = 0; i < inputNumsLen; i++)
    {
        if (inputNums[i]==num) {
            return true;
        }
    }
    return false;
}

// 显示结果
void showResult(int inputNumsLen){
    bool first = true;
    for(int i = N-1; i >=1; i--)
    {
        if(marks[i]==1&&isInputNum(i,inputNumsLen)){
            if (first) {
                printf("%d",i);
                first=false;
                continue;
            }
            printf(" %d",i);
        }
    }
    
}

int main()
{
    int count,n;
    scanf("%d",&count);
    for(int i = 0; i < count; i++)
    {
        scanf("%d",&n);
        inputNums[i]=n;
        //printf("%d=> ",n);
        checkNumAndMark(n);
        //printf("\n");
    }
    showResult(count);
    return 0;
}
