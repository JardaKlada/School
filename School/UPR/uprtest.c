#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    int ingredience = atoi(argv[1]);
    int recepty = atoi(argv[2]);

    if(ingredience == 0 || recepty == 0) {
        printf("Zadny recept nelze uvarit :(\n");
    };


    for(int i = 0; i < ingredience; i++) {
        char dostupne[105];
        fgets(dostupne, sizeof(dostupne), stdin);

        int delka = strlen(dostupne);
        char slozka1[105];
        int pocetslozky = 0;
        int index = 0;
        char pocet1[50];

        while (dostupne[index] != ','){
            index++;
        }

        for(int j = 0; j < index; j++){
            slozka1[j] = dostupne[j];
        };


        pocet1[0] = dostupne[index + 2];
        pocet1[1] = dostupne[index + 3];

        int pocet2 = atoi(pocet1);

    }

    for(int i = 0; i < recepty; i++) {
        char recept[105];
        fgets(recept, sizeof(recept), stdin);

        int pocetin = recept[0];
        int index = 0;

        for(int j = 0; j < pocetin; j++) {
            char recept1[105];
            while(recept[index] != ';'){
                recept1[index] = recept1[index];
                index++;
            }
            printf("%s" , recept1);
        }
    }


    return 0;
}