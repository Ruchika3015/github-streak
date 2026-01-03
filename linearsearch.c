#include<stdio.h>
int main()
{
    int found=0;
    int arr[100],n,target;
    printf("Enter size of array=");
    scanf("%d",&n);
    printf("Enter array elements=");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\nEnter target=");
    scanf("%d",&target);
    for(int i=0;i<n;i++)
    {
        if (arr[i]==target)
        {printf("%d is found at %d",target,i+1);
        found=1;
        break;}
    }
    if (found==0)
    printf("Target not found");
}
