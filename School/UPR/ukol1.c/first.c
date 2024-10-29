#include <stdio.h>

int main()
{
    int bankovka; 

    printf("Zadejte bankovku.\n");
    scanf("%d", &bankovka);

    int bankovky[6] = {5000, 2000, 1000, 500, 200, 100};
    int i = 0;

    while(i < 6) 
    {
        int pocet = bankovka / bankovky[i]; 
        printf("Bankovka %d: %dx\n", bankovky[i], pocet);  
        bankovka = bankovka - (pocet * bankovky[i]);  
        i++;
    }

    return 0; 
}