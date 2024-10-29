#include <stdio.h>
#include <stdlib.h>

int CountDigits(int number);
void FindHistogram(int* histogram, int numOfNumbers, int interval);
void PrintHorizontal(int interval, int* histogram);
int FindMax(int* histogram);
void PrintVertical(int interval, int* histogram, int maxCount);

int main()
{
    char mode;

    scanf("%c", &mode);

    int numOfNumbers;
    int interval; 

    scanf("%d %d", &numOfNumbers, &interval);

    int histogram[10] = { 0 };
    
    FindHistogram(histogram, numOfNumbers, interval);

    if(mode == 'h')
    {
        PrintHorizontal(interval, histogram);
    } else if(mode == 'v')
    {
        int maxCount = FindMax(histogram);
        PrintVertical(interval, histogram, maxCount);
    } else 
    {
        printf("Neplatny mod vykresleni\n");
        exit(1);
    }
    
    return 0;
}

int CountDigits(int number)
{
    int digits = 0;
    do{
        digits++;
        number /= 10;
    }while (number != 0);

    return digits;   
}

void FindHistogram(int* histogram, int numOfNumbers, int interval)
{
    int scannedNum;
    for(int i = 0; i < numOfNumbers; i++)
    {
        scanf("%d", &scannedNum);
        if((scannedNum - interval) < 0 || (scannedNum - interval) > 8) 
        {
            histogram[9]++;
            continue;
        }
        histogram[scannedNum - interval]++;
    } 
}

void PrintHorizontal(int interval, int* histogram)
{
    int maxDigits = CountDigits(interval + 8);
    int currentDigits;
    for(int i = 0; i < 10; i++)
    {
        if(i < 9)
        {
        currentDigits = CountDigits(interval + i);
        if(maxDigits > currentDigits) 
        {
            printf(" ");    
        }
        printf("%d", interval + i);
        }
        else if (histogram[9] != 0){
            printf("invalid:");        
        }
        else if(histogram[9] == 0)
        {
            continue;
        }
        for(int k = 0; k < histogram[i]; k++)
        {   
            if(k == 0) {printf(" ");}
            printf("#");
        }
        printf("\n");
    }
}

void PrintVertical(int interval, int* histogram, int maxCount)
{
    for(int i = maxCount; i > 0; i--)
    {
        if(histogram[9] >= i)
        {
            printf("#");
        } else 
            printf(" ");
        for(int k = 0; k < 9; k++)
        {
            if(histogram[k] >= i)
            { 
                printf("#");
            }
            else    
                printf(" ");
        }
        printf("\n");
    }
    printf("i");
    for(int i = interval; i <= interval + 8; i++)
    {
        printf("%d", i);
    }
    printf("\n");
}

int FindMax(int* histogram)
{
    int max = 0;
    for(int i = 0; i < 10; i++)
    {
        if(histogram[i] > max)
            max = histogram[i];
    }

    return max;
}