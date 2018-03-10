#include<cstdio>
#include<cstring>
using namespace std;

#define N 110

int sumNum[N];
char numStr[N];
int numStrLen;
char englishNum[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printNum(){
    int printFlag=0,first=1;
    for(int i=N-1;i>=0;i--){
        if(sumNum[i]!=0){
            printFlag=1;
        }
        if(printFlag==1){
            if(first!=1){
                printf(" ");
            }else{
                first=0;
            }
            printf("%s",englishNum[sumNum[i]]);
        }
    }
    printf("\n");
}

void add(int digit){
    int i=0,carry=digit;
    while(carry>0){
        int c=(sumNum[i]+carry)/10;
        sumNum[i]=(sumNum[i]+carry)%10;        
        carry=c;
        i++;
    }
}

void print(int num){
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