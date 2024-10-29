#include <stdio.h>
#include <stdbool.h>

int main()
{
    int obrazec;
    int a;
    int b;

    scanf("%d%d%d", &obrazec, &a, &b);

    switch (obrazec)
    {
        case 0:
            for(int i = 0; i < b; i++)
            {
                for(int k = 0; k < a; k++)
                {
                    printf("x");
                }
                printf("\n");
            }
            
            break;
        case 1:
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            for(int i = 0; i < b - 2; i++)
            {
                printf("x");
                for(int k = 0; k < a - 2; k++)
                {
                    printf(" ");
                }
                printf("x\n");
            }
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");

            break;
        case 2:
            int cislo = 0;
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            for(int i = 0; i < b - 2; i++)
            {
                printf("x");
                for(int k = 0; k < a - 2; k++)
                {
                    printf("%d", cislo%10);
                    cislo++;
                }
                printf("x\n");
            }
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");

            break;
        case 3:
            for(int i = 0; i < a; i++)
            {
                for(int k = 0; k < i; k++)
                {
                    printf(" ");
                }
                printf("x\n");
            }
            break;
        case 4:
            for(int i = 0; i < a; i++)
            {
                for(int k = a - i - 1; k > 0; k--)
                {
                    printf(" ");
                }
                printf("x");
                for(int k = 0; k < i; k++)
                {
                    printf(" ");
                }
                printf("\n");
            }
            break;
        case 5:
            int firstXPosition = a - 1;
            int secondXPosition = a + 1;
            bool secondXPlaced = false;

            for(int i = 0; i < a - 1; i++)
            {
                secondXPlaced = false;
                if(i == 0)
                {
                    for(int k = 0; k < a - 1; k++)
                    {
                        printf(" ");
                    }
                    printf("x");
                    for(int k = 0; k < a - 1; k++)
                    {
                        printf(" ");
                    }
                    printf("\n");
                } 
                else
                {
                    for(int k = 0; k < a * 2 - 1; k++)
                    {
                        if((k + 1) == firstXPosition)
                        {
                            printf("x");                    
                            firstXPosition -= 1;

                        }
                        else if((k + 1) == secondXPosition && !secondXPlaced)
                        {
                            printf("x");
                            secondXPosition += 1;
                            secondXPlaced = true;
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            }

            for(int k = 0; k < a * 2 - 1; k++)
            {
                printf("x");
            }
            printf("\n");
            break;

        case 6:
            int stred = a / 2 + 1;
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            for(int i = 0; i < b - 1; i++)
            {
                for(int k = 0; k < stred - 1; k++)
                {
                    printf(" ");
                }
                printf("x\n");
            }
            break;
        case 7:
            for(int k = 0; k < b / 2; k++)
            {
                printf("x");
                for(int i = 0; i < a - 2; i++)
                {
                    printf(" ");
                }
                printf("x\n");
            }
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            for(int k = 0; k < b / 2; k++)
            {
                printf("x");
                for(int i = 0; i < a - 2; i++)
                {
                    printf(" ");
                }
                printf("x\n");
            }
            break;
        case 9:
            int num = 0;
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            for(int i = 1; i < b - 1; i++)
            {
                printf("x");
                for(int k = 0; k < a - 2; k++)
                {
                    printf("%d", num % 10 );
                    num += b - 2;
                }
                num = i;
                printf("x\n");
            }
            for(int i = 0; i < a; i++)
            {
                printf("x");
            }
            printf("\n");
            break;
        default:
            printf("Neznamy obrazec\n");
            break;
    }

    return 0;
}