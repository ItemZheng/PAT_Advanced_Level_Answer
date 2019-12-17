#include<stdio.h>
#include<string.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int c = a + b;

    char arr[100];
    sprintf(arr, "%d", c);

    int i = 0, len = strlen(arr);
    while(arr[i] != '\0'){
        char ch = arr[i];
        printf("%c", ch);
        i++;
        if(ch == '-'){
            continue;
        }
        if((len - i) % 3 == 0 && i != len){
            printf(",");
        }
    }
    return 0;
}