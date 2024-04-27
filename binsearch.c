#include<stdio.h>
int b_search(int a[100], int l, int h, int key) 
{
    int mid;
  if(l > h)
  {
    printf("SEARCH FAILURE !!!");
  return -1;
  }
  mid=(l+h)/2;
  if(key<a[mid])
  {b_search(a,l,mid-1,key);
  }
  else if(key>a[mid] )
  {b_search(a,mid+1,h,key);
  }
  else
  {
printf("\n Search successful ");
return mid+1;

  }
}
int main()
{
    int a[100],n,i,l,h,key,loc;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0; i < n ; i++ )
      scanf("%d", &a[i]);
    printf("\n Enter the search key:") ;
    scanf("%d",&key) ;
    l=0;
    h=n-1;
    loc=b_search(a,l,h,key);
    printf("\n key %d is at location %d",key,loc);
    return 0;
}