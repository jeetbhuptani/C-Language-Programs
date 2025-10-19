int cmp_desc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int cmp_asc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize,
                 int** returnColumnSizes) {
    int n = gridSize;

    int** res = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp[15], len = 0;
        for (int j = 0; i + j < n; j++) {
            tmp[len++] = res[i + j][j];
        }
        qsort(tmp, len, sizeof(int), cmp_desc);
        for (int j = 0; i + j < n; j++) {
            res[i + j][j] = tmp[j];
        }
    }

    for (int j = 1; j < n; j++) {
        int tmp[15], len = 0;
        for (int i = 0; j + i < n; i++) {
            tmp[len++] = res[i][j + i];
        }
        qsort(tmp, len, sizeof(int), cmp_asc);
        for (int i = 0; j + i < n; i++) {
            res[i][j + i] = tmp[i];
        }
    }

    *returnSize = n;
    return res;
}
