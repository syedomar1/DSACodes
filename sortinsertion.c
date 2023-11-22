#include <stdio.h>
#include <stdlib.h>
void insertion(int arr[], int n){
    int j,x;
    for (int i = 1; i < n; i++)
    {
        j=i-1;
        x=arr[i];
        while (j>-1 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;        
    }
}
int main()
{
    int n;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}