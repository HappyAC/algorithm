#include <cstdio>

int main()
{
    float maxodds[3];
    float odds,max = -1e8;
    int max_index;
    const char *result_names = "WTL";
    for (int i = 0; i < 3; i++)
    {
        max_index=0;
        max=-1e8;
        for (int j = 0; j < 3; j++)
        {
            scanf("%f",&odds);
            if(odds>max){
                max=odds;
                max_index=j;
            }
        }
        maxodds[i]=max;
        // if(i!=0) printf(" ");
        printf("%c ",result_names[max_index]);
    }
    printf("%.2f",(maxodds[0]*maxodds[1]*maxodds[2]*0.65-1)*2);
    return 0;
}
