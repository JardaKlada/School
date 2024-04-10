#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct akcie{
    unsigned int den;
    char* nazev;
    float zacatek;
    float konec;
    int obchody;
} Akcie;

char* formatobchod(int cislo) {
    char format[100];
    sprintf(format, "%d", cislo);
    int delka = strlen(format);
    int mezery = delka / 3;
    int novadelka = delka + mezery + 1;

    char *fobchody = (char*)malloc(novadelka * sizeof(char));

    int a = 0;
    for(int j = 0; j < delka; j++){
        if((delka - j) % 3 == 0 && j != 0){
            fobchody[a++] = '_';
        }
        fobchody[a++] = format[j];
    }
    fobchody[a] = '\0';

    return fobchody;
}

void uvolniPametAkcie(Akcie* akcie, int pocetradku) {
    for (int i = 0; i < pocetradku; i++) {
        free(akcie[i].nazev);
    }

    free(akcie);
}

Akcie najdinejlepsiakcii(Akcie* akcie, int pocetradku, char* nazevakcie) {
    int nejvicobchodu = 0;

    Akcie nejvetsiakcie = {.den = 0, .konec = 0, .nazev = 0, .obchody = 0, .zacatek = 0};

    for (int i = 0; i < pocetradku; i++) {
        if ((!(strcmp(akcie[i].nazev, nazevakcie))) && akcie[i].obchody > nejvicobchodu) {
            nejvicobchodu = akcie[i].obchody;
            nejvetsiakcie = akcie[i];    
        } 
    }

    return nejvetsiakcie;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("Wrong parameters\n");
        exit(1);
    } 
    
    char* nazevakcie = argv[1];
    int pocetradku = atoi(argv[2]);

    Akcie* akcie = (Akcie*)malloc(pocetradku * sizeof(Akcie));

    for(int i = 0; i < pocetradku; i++)
    {
        char celaakcie[100];
        char* rozdelenaakcie;

        if (fgets(celaakcie, sizeof(celaakcie), stdin) != NULL)
        {   
            rozdelenaakcie = strtok(celaakcie, ",");

            akcie[i].den = atoi(rozdelenaakcie);
            rozdelenaakcie = strtok(NULL, ",");
            akcie[i].nazev = strdup(rozdelenaakcie);
            rozdelenaakcie = strtok(NULL, ",");
            akcie[i].zacatek = atof(rozdelenaakcie);
            rozdelenaakcie = strtok(NULL, ",");
            akcie[i].konec = atof(rozdelenaakcie);
            rozdelenaakcie = strtok(NULL, ",");
            akcie[i].obchody = atoi(rozdelenaakcie);

        }
    }


    Akcie bigakcie = najdinejlepsiakcii(akcie, pocetradku, nazevakcie);

    printf("<html>\n<body>\n<div>\n");

    if (bigakcie.obchody != 0){
        char* fobchod = formatobchod(bigakcie.obchody);
        {printf("<h1>%s: highest volume</h1>\n<div>Day: %i</div>\n<div>Start price: %.2f</div>\n<div>End price: %.2f</div>\n<div>Volume: %s</div>\n</div>\n", nazevakcie, bigakcie.den, bigakcie.zacatek, bigakcie.konec, fobchod);}
        free(fobchod);
    }else{
        printf("Ticker AMC was not found\n</div>\n");
    }
    printf("<table>\n<thead>\n<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n</thead>\n<tbody>\n");
    for (int i = 0; i < pocetradku; i++) {
        if (!(strcmp(nazevakcie, akcie[(pocetradku - 1) - i].nazev))){
            float dif = akcie[(pocetradku - 1) - i].konec - akcie[(pocetradku - 1) - i].zacatek;
            char* fobchod = formatobchod(akcie[(pocetradku - 1) - i].obchody);
            printf("<tr>\n\t<td><b>%i</b></td>\n\t<td><b>%s</b></td>\n\t<td><b>%.2f</b></td>\n\t<td><b>%.2f</b></td>\n\t<td><b>%.2f</b></td>\n\t<td><b>%s</b></td>\n</tr>\n", akcie[(pocetradku - 1) - i].den, akcie[(pocetradku - 1) - i].nazev, akcie[(pocetradku - 1) - i].zacatek, akcie[(pocetradku - 1) - i].konec, dif, fobchod);
            free(fobchod);
        }
        else{
            char* fobchod = formatobchod(akcie[(pocetradku - 1) - i].obchody);
            float dif = akcie[(pocetradku - 1) - i].konec - akcie[(pocetradku - 1) - i].zacatek;
            printf("<tr>\n\t<td>%i</td>\n\t<td>%s</td>\n\t<td>%.2f</td>\n\t<td>%.2f</td>\n\t<td>%.2f</td>\n\t<td>%s</td>\n</tr>\n", akcie[(pocetradku - 1) - i].den, akcie[(pocetradku - 1) - i].nazev, akcie[(pocetradku - 1) - i].zacatek, akcie[(pocetradku - 1) - i].konec, dif, fobchod);
            free(fobchod);
        }
    }


    printf("</tbody>\n</table>\n</body>\n</html>\n");

    uvolniPametAkcie(akcie, pocetradku);  

    return 0;
}