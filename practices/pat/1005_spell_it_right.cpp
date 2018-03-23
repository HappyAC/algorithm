#include<cstdio>
#include<cstring>
using namespace std;

#define N 110
// 2018-03-23 thewinds 
// [题目] PAT A-1005
// 统计家谱树中各个层级无后代的节点的数目
// [考点] 水题...
// [心得]
// -- 虽然是个水题但是一开始误以为是大数加法,
// 后来发现100位加起来最大也只有 100*9 = =||
// 然后后来因为没有考虑 0 的情况有一个测试点一直没过,
// 所以说一定要审题细心,考虑周到
 

int sumNum[N];
char numStr[N];
int numStrLen;
char englishNum[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void print(int num){
    if (num==0){
        printf("%s",englishNum[0]);                
    }
    int printNum[3]={0},first=1,i=0;
    while(num>0){
        printNum[i]=num%10;
        num/=10;
        i++;
    }
    for(int k=i-1;k>=0;k--){
        if(k!=i-1) printf(" ");
        printf("%s",englishNum[printNum[k]]);        
    }
}

void calc(){
    memset(sumNum,0,N);  
    int sum=0;  
    for(int i=numStrLen-1;i>=0;i--){
        int digit=numStr[i]-'0';
        // add(digit);
        sum+=digit;
    }
    print(sum);
}



int main(){
    scanf("%s",numStr);
    numStrLen=(int)strlen(numStr);
    calc();
    // printNum();
    // print();
    return 0;
}