#include "stdio.h"
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    printf("%d\n",*arr); // first element
    printf("%d\n",*(arr+1)); // second element
    return 0;
}