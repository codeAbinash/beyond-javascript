#include "stdio.h"
#define len 5

int matrix[len][len] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};
int visited[len] = {0, 0, 0, 0, 0};

void DFS(int n) {
    int i;
    printf("%d ", n);
    visited[n] = 1;

    for (i = 0; i < len; i++) {
        if (matrix[n][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("DFS : ");
    DFS(4);
    return 0;
}