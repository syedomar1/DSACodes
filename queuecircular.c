#include <stdio.h>
#include <stdbool.h>

int size;
int fr = 0;
int back = 0;
int count = 0;

bool empty() {
    return count == 0;
}

bool full() {
    return count == size;
}

void enqueue(int stk[]) {
    if (full()) {
        printf("Queue is full\n");
    } else {
        int val;
        scanf("%d", &val);
        stk[back] = val;
        back = (back + 1) % size;
        count++;
    }
}

void dequeue(int stk[]) {
    if (empty()) {
        printf("Queue is empty\n");
    } else {
        int val = stk[fr];
        fr = (fr + 1) % size;
        count--;
        printf("Removed element is %d\n", val);
    }
}

void display(int stk[]) {
    if (empty()) {
        printf("Queue is empty\n");
    } else {
        int count = 0;
        int i = fr;
        while (count++ < size) {
            printf("%d ", stk[i]);
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

int main() {
    int n, ch;
    printf("Enter no of elements: \n");
    scanf("%d", &n);
    size = n;
    int arr[n];
    while (1) {
        printf("Choose from the menu\n");
        printf("Enter 1 to Enqueue the elements\n");
        printf("Enter 2 to Dequeue the elements\n");
        printf("Enter 3 to Display the elements\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &ch);
        if (ch == 4) break;
        switch (ch) {
            case 1:
                enqueue(arr);
                break;
            case 2:
                dequeue(arr);
                break;
            case 3:
                display(arr);
                break;
        }
    }
    return 0;
}
