#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void bubble(int a[], int s){
    int flag=0;
    for (int i = 0; i < s; i++)
    {
        flag=0;
        for (int j = 0; j < s-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }      
        if (flag==0)
        {
            break;
        }
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
    bubble(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}