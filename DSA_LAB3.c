// Prob 1
/*#include <stdio.h>
int countBits(int num) {
    int c = 0;
    while (num) {
        c += num & 1;
        num >>= 1;
    }
    return c;
}
void bubbleSort(int arr[], int arr2[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr2[j] < arr2[j + 1]) {
                int tempAux = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = tempAux;
                int tempArr = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempArr;
            }
        }
    }
}
void BSort(int arr[], int n) {
    int arr2[n];
    for (int i = 0; i < n; i++)
        arr2[i] = countBits(arr[i]);
    bubbleSort(arr, arr2, n);
}
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    BSort(arr, n);
    printArr(arr, n);
    return 0;
}*/

// Prob2
#include <stdio.h>
int compareDates(int date1[], int date2[]) {
    if (date1[2] < date2[2]) {
        return -1;
    } else if (date1[2] > date2[2]) {
        return 1;
    } else {
        if (date1[1] < date2[1]) {
            return -1;
        } else if (date1[1] > date2[1]) {
            return 1;
        } else {
            if (date1[0] < date2[0]) {
                return -1;
            } else if (date1[0] > date2[0]) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
void swapDates(int dateA[], int dateB[]) {
    for (int i = 0; i < 3; i++) {
        int temp = dateA[i];
        dateA[i] = dateB[i];
        dateB[i] = temp;
    }
}
void Date_sort(int dates[][3], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (compareDates(dates[j], dates[j + 1]) > 0) {
                swapDates(dates[j], dates[j + 1]);
            }
        }
    }
}
int main() {
    int dates[][3] = {{20, 1, 2014}, {25, 3, 2010}, {3, 12, 1676}, {18, 11, 1982}, {19, 4, 2015}, {9, 7, 2015}};
    int n = sizeof(dates) / sizeof(dates[0]);
    Date_sort(dates, n);  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d, ", dates[i][j]);
        }
        printf("%d\n", dates[i][2]);
    }
}
