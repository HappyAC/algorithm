// 2018-03-23 thewinds 
// [题目] PAT A-1007
// 求最大子序列的和
// [考点] 处理子序列问题
// [心得]
// 这题折腾了好久才过,首先这是一个经典的题目,
// 解决方案从O(N*N*N)到 O(N)都有,所以选择死磕O(N)的算法,
// 可以知道如果想要得到最大的子序列,该子序列要有能继续增大的潜力,
// 也就是说这个子序列加上之后的一段序列(或者一个数)可以继续增大,
// 所以该子序列的和应该是大于0的。
// 因此可以从前到后遍历一次,如果到某一个位置的和小于等于0,就将和清零从下一个位置
// 进行尝试。如果大于0就与最大和进行比较,更新最大和和起始位置，要注意的是当发现最大
// 和的时候末尾位置是隐含保留的,而其实位置丢失了,因此要将起始位置保存下来。
// 😃 继续努力

#include<cstdio>

using namespace std;

#define ARRAY_CAP 10001

int nums[ARRAY_CAP];
int numsLen;

void findMaxSubSequence(){
    int startNum=0,endNum=0,startIndex=0;
    int sumHere=0,maxSum=0;

    for (int i=0;i<numsLen;i++){
        int numHere = nums[i];

        if (sumHere+numHere>0){
            if(sumHere==0){
                startIndex=i;
            }
            sumHere+=numHere;
            if (sumHere>maxSum){
                maxSum=sumHere;
                endNum=numHere;
                startNum=nums[startIndex];
            }
        }else{
            sumHere=0;
        }
    }

    printf("%d %d %d",maxSum,startNum,endNum);
}

int main(){
    bool allNeg=true;
    scanf("%d",&numsLen);
    for(int i=0;i<numsLen;i++) {
        scanf("%d",&nums[i]);
        if(nums[i]>=0){
            allNeg=false;
        }
    }
    if(allNeg){
        printf("%d %d %d",0,nums[0],nums[numsLen-1]);        
    }else{
       findMaxSubSequence();
    }
    return 0;
}