#include <stdio.h>
#include <string.h>

int printArray(char *pole);
int arraya(int n, char *pole);
int leftArray(char *pole);
int rightArray(char *pole);
int allZero(char *pole);

int main() {

    int n;
    int a = 0;
    int b = 1;
    char pole[200];

    scanf("%d", &n);

    // while(b <= n) 
    // {
    //     a = 0;
    //     while(a < b) 
    //     {
    //     printf("%d", b);
    //     a++;
    //     }
    //     b++;
    // }

    arraya(n, pole);



    return 0; 
}

int arraya(int n, char *pole){
    int a = 0;
    int b = 1;
    int index = 0;

    while(b <= n) 
    {
        a = 0;
        while(a < b) 
        {
        pole[index] = b;
        index++;
        a++;
        }
        b++;
    }

    pole[index + 1] = '\0';

    printArray(pole);
    // leftArray(pole);
    // rightArray(pole);
    allZero(pole);
}
int leftArray(char *pole){
    int lenArray = strlen(pole);
    int changedNum = 0;

    for(int i = 0; i < lenArray; i++)
    {
        if(pole[i] > changedNum)
        {
        changedNum = pole[i];         
        pole[i] = 0;
        }

    }

    for(int i = 0; i < lenArray; i++)
    {
        printf("%d", pole[i]);
    }
    printf("\n");
}

int printArray(char *pole){
    int lenArray = strlen(pole);

    for(int i = 0; i < lenArray; i++)
    {
        printf("%d", pole[i]);
    }
    printf("\n");

}

int rightArray(char *pole){
    int lenArray = strlen(pole);
    int changedNum = pole[lenArray - 1];

    for(int i = lenArray; i >= 0; i--)
    {
        if(pole[i] == changedNum)
            {            
            changedNum = changedNum - 1;
            pole[i] = 0;
            }
    }

    for(int i = 0; i < lenArray; i++)
    {
        printf("%d", pole[i]);
    }
    printf("\n");
}

int allZero(char *pole){
    int lenArray = strlen(pole);
    int changedNum = pole[lenArray - 1];
    int num = changedNum;

    for(int k = 0; k < num; k++)
    {   
        changedNum = num;
        for(int i = lenArray; i >= 0; i--)
        {
            if(pole[i] == 0)
            {
                i--;
            }
            if(pole[i] == changedNum)
            {            
                changedNum = changedNum - 1;
                pole[i] = 0;
            }
        }
        for(int i = 0; i < lenArray; i++)
        {
        printf("%d", pole[i]);
        }      
        printf("\n");
    }  
     
    for(int i = 0; i < lenArray; i++)
    {
        printf("%d", pole[i]);
    }
    printf("\n");
}
