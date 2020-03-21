#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 用栈存，递归，递归时判断类型

char strings[4][100] = { "\0", "Max Heap\0", "Min Heap\0", "Not Heap\0"};
int type = 0;  // 0 - to be decide   1-max  2 - min  3-Error
int stack[100], top = 0;

void adjust(int p, int c){
    if(type == 3){
        return;
    }
    if(p > c){
        if(type == 0){
            type = 1;
        }
        if(type == 2){
            type = 3;
        }
    }
    if(p < c){
        if(type == 0){
            type = 2;
        }
        if(type == 1){
            type = 3;
        }
    }
}

void output(){
    for (int i = 0; i < top; ++i) {
        if(i == 0){
            printf("%d", stack[i]);
        } else {
            printf(" %d", stack[i]);
        }
    }
    printf("\n");
}

void push(int x){
    stack[top++] = x;
}

void pop(){
    top--;
}

void traversal(int idx, int *arr, int len){
    int x = arr[idx];
    push(arr[idx]);
    // left child
    if(2 * idx + 1 > len - 1){
        output();
    } else {
        // right child
        if(2 * idx + 2 <= len - 1){
            int r = arr[2 * idx + 2];
            adjust(x, r);
            traversal(2 * idx + 2, arr, len);
        }
        int l = arr[2 * idx + 1];
        adjust(x, l);
        traversal(2 * idx + 1, arr, len);
    }
    pop();
}

int main(){
    int len;
    scanf("%d", &len);

    //read array
    int num[len];
    for(int i = 0; i < len; i++){
        scanf("%d", &num[i]);
    }

    traversal(0, num, len);
    printf("%s", strings[type]);
    return 0;
}