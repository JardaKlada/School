#include <stdio.h>

int main() {
    int obrazec = 0;
    int a = 0;
    int b = 0;
    
    scanf("%d%d%d", &obrazec, &a, &b);
    
    if (obrazec == 0) {
        for (int i = 0; i < b; i++) {
            for (int k = 0; k < a; k++) {
                printf("x");
            }
            printf("\n");
        }

    }
    else if (obrazec == 1) {
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");
        for (int i = 0; i < b - 2; i++) {
            printf("x");
            for (int k = 0; k < a - 2; k++) {
                printf(" ");
            }
            printf("x\n");
        }
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");

    }
    else if (obrazec == 2) {
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");
        int x = 0;
        for (int i = 0; i < b - 2; i++) {
        printf("x");
            for (int k = 0; k < a - 2; k++) {
                printf("%d", x);
                x = x + 1;
                if (x == 10) {
                    x = 0;
                }
            }
        printf("x\n");
        }  
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");

    }
    else if (obrazec == 3) {
        printf("x\n");
        int x = 0;
        for (int i = 0; i < a - 1; i++) {
            x = x + 1;
            for (int k = 0; k < x; k++) {
                printf(" ");
                if (x > a + 1) {
                    break;
                }
            }
            printf("x\n");
        }
    }
    else if (obrazec == 6) {
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");
        int x = a / 2;
        for (int i = 0; i < b - 1; i++) {
            for (int k = 0; k < x; k++) {
                printf(" ");
            }
            printf("x\n");
        }
    }
    else if (obrazec == 9) {
        for (int i = 0; i < a; i++) {
            printf("x");
        }
        printf("\n");
        int x = 0;
        for (int i = 0; i < b - 2; i++) {
            printf("x");

            for (int k = 0; k < a - 2; k++) {
                printf("%d", x);
                x = x + (b - 2);

                if (x > 9) {
                    x = x % 10;
                }
            }

            x = (i + 1);             
            printf("x\n");
        }
        for (int i = 0; i < a; i++) {
            printf("x");
        } 
        printf("\n");
    }
    else {
            printf("Neznamy obrazec");
            printf("\n");
        }
    return 0;
}