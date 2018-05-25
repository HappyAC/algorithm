/*
 * easy question
 *
 */
#include<cstdio>

int main(){
    int n;
    int requests[105];
	scanf("%d",&n);
	requests[0]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&requests[i+1]);
	}
	int times=0;
	for(int i=0;i<n;i++){
		int a=requests[i];
		int b=requests[i+1];
		if(a>b){
			times+=(a-b)*4;
		}else{
			times+=(b-a)*6;
		}
	}
	times+=n*5;
	printf("%d",times);
	return 0;
}
