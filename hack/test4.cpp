#include <stdio.h>
#include <math.h>
int main()  
{ 
    int n,i,j;
    printf("Enter number of line ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
      for(j=0;j<=i;j++){
        printf("*");
      }
      printf("\n");
    }

    
    return 0;   
} 