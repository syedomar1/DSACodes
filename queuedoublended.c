#include <stdio.h>
#include <stdbool.h>

int size;
int fr = -1;
int back = 0;

bool isFull() {
    return ((fr == 0 && back == size-1) || fr == back+1);
}

bool isEmpty() {
    return (fr == -1);
}

void insertFront(int* queue, int key) {
    if (isFull()) {
        printf("\n Queue is full");
        return;
    }

    if (fr == -1) {
        fr = back = 0;
    }
    else if (fr == 0) {
        fr = size - 1 ;
    }
    else {
        fr = fr-1;
    }

    queue[fr] = key ;
}

void insertRear(int* queue, int key) {
    if (isFull()) {
        printf("\n Queue is full");
        return;
    }

    if (fr == -1) {
        fr = back = 0;
    }
    else if (back == size-1) {
        back = 0;
    }
    else {
        back = back+1;
    }

    queue[back] = key;
}

void deleteFront(int* queue) {
    if (isEmpty()) {
        printf("\n Queue is empty ");
        return ;
    }

    if (fr == back) {
        fr = -1;
        back = -1;
    }
    else if (fr == size -1) {
        fr = 0;
    }
    else {
        fr = fr+1;
    }
}

void deleteRear(int* queue) {
    if (isEmpty()) {
        printf("\n Queue is empty ");
        return ;
    }

    if (fr == back) {
        fr = -1;
        back = -1;
    }
    else if (back == 0) {
        back = size-1;
    }
    else {
        back = back-1;
    }
}

int getFront(int* queue) {
    if (isEmpty()) {
        printf("\n Queue is empty ");
        return -1 ;
    }
    return queue[fr];
}

int getRear(int* queue) {
    if(isEmpty() || back < 0) {
        printf("\n Queue is empty ");
        return -1 ;
    }
    return queue[back];
}

int main() {
    int n;
    printf ("Enter no of elements: \n");
    scanf ("%d", &n);
    size = n;
    int arr[n];

    printf ("Input for the queue : ");
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        insertRear(arr, num);
    }

    printf ("Element at front is %d\n", getFront(arr));
    printf ("Element at rear is %d\n", getRear(arr));

    deleteRear(arr);
    printf ("After deleteRear, element at rear is %d\n", getRear(arr));

    deleteFront(arr);
    printf ("After deleteFront, element at front is %d\n", getFront(arr));

    return 0;
}
