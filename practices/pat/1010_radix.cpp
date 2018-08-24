#include<cstdio>
#include<cstring>
#define MAX_DIGITS 11

int convert_to_dec(char *num_str,int radix){
    int len = strlen(num_str);
    int base = 1,ret = 0;
    for(int i=len-1;i>=0;i--){
        int cur = (num_str[i]>='0'&&num_str[i]<='9')?
            num_str[i]-'0':num_str[i]-'a'+10;
        if(cur>radix-1) return -1;
        ret+=base*cur;
        base*=radix;
    }
    return ret;
}

int find_min_radix(char* num_str){
    int len = strlen(num_str);
    int min=2;
    for(int i = 0; i < len; i++)
    {
        int cur = (num_str[i]>='0'&&num_str[i]<='9')?
            num_str[i]-'0':num_str[i]-'a'+10;
        min=cur<min?cur:min;
    }
    return min; 
}

int main(){

    char a[MAX_DIGITS],b[MAX_DIGITS];
    int tag,base_radix;
    int num_a,num_b;
    scanf("%s %s %d %d",a,b,&tag,&base_radix);

    if(tag==1){
        num_a=convert_to_dec(a,base_radix);
        
        for(int i = 0; i <=36; i++)
        {
            if(num_a==convert_to_dec(b,i)){
                printf("%d",i);
                return 0;
            }
        }
        
    }else{
        num_a=convert_to_dec(b,base_radix);      
        for(int i = 0; i <=36; i++)
        {
            if(num_a==convert_to_dec(a,i)){
                printf("%d",i);
                return 0;
            }
        }  
    }

    printf("Impossible");
    return 0;
}