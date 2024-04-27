#include<stdio.h>
int main()
{
    int a[10],i,n,key;
    printf("Enter number of elements :");
    scanf("%d",&n);
    printf("\nEnter the array elements: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
        printf("enter search key :");
        scanf("%d",&key);
        for(i=0;   i<n; i++)
        {
            if (key==a[i])
            break;
        }
        if(i==n)
        printf("\n%d not found in array .",key);
        else
        printf("\n%d is at position %d in the array.",key,i+1); 
return 0;
}