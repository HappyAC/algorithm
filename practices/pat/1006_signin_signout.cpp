#include<cstdio>
#include<cstring>
// 2017-12-11 thewinds 
// [题目] PAT A-1006
// 输出开门和锁门(最早登录和最晚登出)的ID
// [考点] ...C++基础
// [心得]
//  水题一枚 😐
#define MIN -1
#define MAX 1e9
struct Log{
    char id[20];
    int hour;
    int minute;
    int second;
};

int logTimeCmp(Log a,Log b){
    if(a.hour==b.hour){
        if(a.minute==b.minute){
            if(a.second==b.second){
                return 0;
            }
            return a.second>b.second?1:-1;
        }
        return a.minute>b.minute?1:-1;
    }
    return a.hour>b.hour?1:-1;
}

int main(){
    Log first,last,currentIn,currentOut;
    first.hour=first.minute=first.second=MAX;
    last.hour=last.minute=last.second=MIN;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",&currentIn.id);
        strcpy(currentOut.id,currentIn.id);
        scanf("%d:%d:%d",&currentIn.hour,&currentIn.minute,&currentIn.second);
        scanf("%d:%d:%d",&currentOut.hour,&currentOut.minute,&currentOut.second);
        if(logTimeCmp(currentIn,first)==-1){
            first=currentIn;
        }
        if(logTimeCmp(currentOut,last)==1){
            last=currentOut;
        }
    }
    printf("%s %s",first.id,last.id);
    return 0;
}