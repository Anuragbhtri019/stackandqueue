#include<stdio.h>
void toh(int n ,char from, char Aux ,char to)
{
    if (n==1)
    {
        printf("\n move disk %d from rod %c to rod %c",n,from,to);
        return ;
    }
    toh(n-1,from,to,Aux);
    printf("\n move disk %d from rod %c to rod %c  ",n,from,to);
    toh(n-1,Aux,from,to);

}
int main()
{int n;
    printf("enter the number of disks in source rod :");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}
