#include <stdio.h>
#include <math.h>
int main()  
{   
    int n,a=0,b=1,c=0;

    printf("Enter number of terms you want to print\n");
    scanf("%d",&n);

    for(int i=0;i<=n;i++){
        printf("term %d is %d\n",i,c);
        a=b;
        b=c;
        c=a+b;
    }
    


    return 0;   
} 