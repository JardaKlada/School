#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[10];

    fgets(a, sizeof(a), stdin);

    int n = atoi(a);
    char radky[n][51];
    int staremezery = 0;
    int novemezery = 0;
    int velkap = 0;
    int malap = 0;
    int novevelke = 0;
    int novemale = 0;

    for (int i = 0; i < n; i++) {
        fgets(radky[i], sizeof(radky[i]), stdin);
    }

    for (int i = 0; i < n; i++) {
        char normalizovanyradek[50];
        int kontrolovanyindex = 0;
        int index = 0;
        int delka = strlen(radky[i]);

        while (kontrolovanyindex < delka && radky[i][kontrolovanyindex] == ' ') {
            kontrolovanyindex++;
            staremezery++;
        }

        while (kontrolovanyindex < delka) {
            int delkaslova = 0;
            int obsahujeVelkePismeno = 0;
            int pocatekSlova = kontrolovanyindex;


            while (kontrolovanyindex < delka && radky[i][kontrolovanyindex] != ' ' && radky[i][kontrolovanyindex] != '\0') {
                normalizovanyradek[index] = radky[i][kontrolovanyindex];
                if (isupper(normalizovanyradek[index])) {
                    obsahujeVelkePismeno = 1;
                    velkap++;
                } else{
                    malap++;
                }
                kontrolovanyindex++;
                index++;
            }

            if (obsahujeVelkePismeno == 1) {
                normalizovanyradek[pocatekSlova] = toupper(normalizovanyradek[pocatekSlova]);
                for (int k = 1; k < delkaslova; k++) {
                    normalizovanyradek[pocatekSlova + k] = tolower(normalizovanyradek[pocatekSlova + k]);
                    novevelke++;
                }
                
            } else {
                for (int k = 0; k < delkaslova; k++) {
                    normalizovanyradek[pocatekSlova + k] = toupper(normalizovanyradek[pocatekSlova + k]);
                }                    
            }

            if (kontrolovanyindex < delka) {
                normalizovanyradek[index] = ' ';
                index++;
                kontrolovanyindex++;
                staremezery++;
                novemezery++;

                while (kontrolovanyindex < delka && radky[i][kontrolovanyindex] == ' ') {
                    kontrolovanyindex++;
                    staremezery++;
                }
            }
            delkaslova = 0;
        }

        normalizovanyradek[index] = '\0';
        printf("%s", normalizovanyradek);
        printf(" lowercase: %i -> %i \n", malap - 1, novemale);
        printf(" uppercase: %i -> %i \n", velkap, novevelke );
        printf(" spaces: %i -> %i \n", staremezery, novemezery - 1);
        staremezery = 0;
        novemezery = 0;
        velkap = 0;
        malap = 0;
        novemale = 0;
        novevelke = 0;
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%s", radky[i]);
    // }

    return 0;
}

