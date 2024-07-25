#include<stdio.h>
#define MAX 50
int p[MAX],w[MAX],n;
int knapsack(int,int);
int max(int,int);
void main()
{
int m,i,optsoln;

printf("enter no. of objects:");
scanf("%d",&n);
printf("\nenter the weights:\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter the profits:\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("\nenter the knapsack capacity:");
scanf("%d",&m);
optsoln=knapsack(1,m);
printf("\nthe optimal solution is:%d",optsoln);
}
int knapsack(int i,int m)
{
if(i==n)
return(w[n]>m)?0:p[n];
if(w[i]>m)
return max(knapsack(i+1,m),knapsack(i+1,m-w[i])+p[i]);
}
int max(int a,int b)
{
if(a>b)
return a;
else return b;
}
