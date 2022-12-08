//enter a number n and print sum of squares till n.

#include<stdio.h>
int naive(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i*i;
    }
    return sum;
}
int interesting(int n)
{
    return (n*(n+1)*(2*n+1))/6;
}
int main()
{
    int n,i=1,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    if (n>0){
        printf("Sum of squares till %d is %d \n",n,naive(n));
        printf("Sum of squares till %d is %d",n,interesting(n));
    }
    else
    {
        printf("Enter a positive number");
        return 0;
    }
}
