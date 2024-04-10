#include <stdio.h>
#include <stdlib.h>

struct zelva {
    int row;
    int col;
    int direction;
    int active;
};

char **createMatrix(int radky, int sloupce);
void printMatrix(char **a, int radky, int sloupce);
void freeMatrix(char **matice, int radky);

int main() {
    int radky = 0;
    int sloupce = 0;
    char operace[150];
    char op;
    int count = 0;
    int aczelvy = 1;

    struct zelva cislo[3];

    cislo[0] = (struct zelva) {0, 0, 0, 1};
    cislo[1] = (struct zelva) {0, 0, 0, 0};
    cislo[2] = (struct zelva) {0, 0, 0, 0};

    scanf("%d %d", &radky, &sloupce);
    while (op != 'x') {
        scanf(" %c", &op);
        operace[count] = op;
        count = count + 1;
    }

    char **a = createMatrix(radky, sloupce);

    for (int i = 0; i < count; i++) {
        switch (operace[i]) {
            case 'r':
                for (int j = 0; j < 3; j++) {
                    if (cislo[j].active == 1) {
                        cislo[j].direction = (cislo[j].direction + 1) % 4;
                    }
                    printf("smer %d \n", *&cislo[j].direction);
                }
                break;
            case 'l':
                for (int j = 0; j < 3; j++) {
                    if (cislo[j].active == 1) {
                        cislo[j].direction = (cislo[j].direction - 1) % 4;
                    }
                    printf("smer %d \n", *&cislo[j].direction);                    
                }
                break;
            case 'm':
                for (int j = 0; j < 3; j++) {
                    if (cislo[j].active == 1) {
                        if (cislo[j].direction == 0) {
                            cislo[j].col = (cislo[j].col + 1) % sloupce;
                        } else if (cislo[j].direction == 1) {
                            cislo[j].row = (cislo[j].row + 1 + radky) % radky;
                        } else if (cislo[j].direction == 2) {
                            cislo[j].col = (cislo[j].col - 1 + sloupce) % sloupce;
                            if (cislo[j].col == -1){
                                cislo[j].col = 3;
                            }
                        } else if (cislo[j].direction == 3) {
                            cislo[j].row = (cislo[j].row - 1) % radky;
                            if (cislo[j].row == -1){
                                cislo[j].row = 3;
                            }
                        }
                        printf("sloupec %d \n", *&cislo[j].col);
                        printf("radek %d \n", *&cislo[j].row);
                    }
                }
                break;
            case 'o':
                for (int j = 0; j < 3; j++) {
                    if (cislo[j].active == 1) {
                        if (a[cislo[j].row][cislo[j].col] == '.') {
                            a[cislo[j].row][cislo[j].col] = 'o';
                        } else {
                            a[cislo[j].row][cislo[j].col] = '.';
                        }
                    }
                }
                break;
            case 'f':
                if (aczelvy < 3) {
                    cislo[aczelvy].active = 1;
                    aczelvy = aczelvy + 1;
                }
                break;
            case 'x':
                printMatrix(a, radky, sloupce);
                freeMatrix(a, radky);
                break;
        }
    }

    return 0;
}

char **createMatrix(int radky, int sloupce) {
    char **matice = (char **)malloc(radky * sizeof(char *));
    
    for (int i = 0; i < radky; i++) {
        matice[i] = (char *)malloc(sloupce * sizeof(char));
        for (int j = 0; j < sloupce; j++) {
            matice[i][j] = '.';
        }
    }
    return matice;
}

void printMatrix(char **a, int radky, int sloupce) {
    for (int i = 0; i < radky; i++) {
        for (int j = 0; j < sloupce; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(char **matice, int radky) {
    for (int i = 0; i < radky; i++) {
        free(matice[i]);
    }
    free(matice);
}
