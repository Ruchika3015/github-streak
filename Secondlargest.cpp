#include<stdio.h>
#include<limits.h>
int main()
{
    int arr[100],n,i;
    int max1=INT_MIN;
    int max2=INT_MIN;
    printf("Enter number of elemnets=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++)
    {
        if (arr[i]>max1)
        {
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>max2 && arr[i]!=max1)
        {
            max2=arr[i];
        }
    }
    printf("Second maximum number is %d",max2);
}
