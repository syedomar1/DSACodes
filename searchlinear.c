#include <stdio.h>
#include <string.h>
struct Array {
    int A[10];
    int length;
};
int LinearSearch(struct Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if (key==arr.A[i])
        {
            return i;
        }
        return -1;
    }    
}
int main()
{
    struct Array arr={{2,3,4,5,6},10};
    printf("%d\n",LinearSearch(arr,4));
    return 0;
}