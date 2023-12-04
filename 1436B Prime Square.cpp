#include<stdio.h>
int main()
{
    int a[102][102],i,j,tc,num,row,col,mid ;
    scanf("%d",&tc);
    while(tc--)
    {
        for(row=0; row<100; row++)
        {
            for(col=0; col<100; col++)
            {
                a[row][col] = 0 ;
            }
        }
        scanf("%d",&num);
        for(row=0,col=0; col<num; col++,row++)
        {
            a[row][col] = 1 ;
        }
        for(row=0,col=num-1; row<num; col--,row++)
        {
            a[row][col] = 1 ;
        }
        if(num%2!=0)
        {
            mid=(num-1)/2 ;
            a[mid-1][mid]=1;
            a[mid][mid-1]=1;
        }
        for(row=0; row<num; row++)
        {
            for(col=0; col<num-1; col++)
            {
                printf("%d ",a[row][col]);
            }
            printf("%d",a[row][num-1]);
            printf("\n");
        }


    }
}