#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv){
    char* inputFile = "";
    char* outputFile = "";
    int ignoreUpper = 0;
    char* needle = "";
    int missOutput = 0;
    int output = 0;
    int needlee = 0;


    if (argc < 2) {
         printf("Input path not provided\n");
         exit(1);
    }
    int numOfOutputs = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-o")){
            numOfOutputs++;
            output = 1;
            if (!strcmp(outputFile, "")) {
                if (i + 1 < argc && strstr(argv[i + 1], ".txt")) {
                    outputFile = argv[i + 1];
                    i++;
                } else {
                    missOutput = 1;
                }
            }
            if (numOfOutputs > 1){
                printf("Parameter -o provided multiple times\n");
                exit(1);
            }
        }
        else if (!(strcmp(argv[i], "-i"))) {
            if (ignoreUpper == 1) {
                printf("Parameter -i provided multiple times\n");
                exit(1);
            } else {
                ignoreUpper = 1;
            }
        }
        else if (strstr(argv[i], ".txt")) {
            inputFile = argv[i];
        } 
        else if (!strstr(argv[i], ".txt") && strcmp(argv[i], "-o") && strcmp(argv[i], "-i")) {
            needle = argv[i];
            needlee++;
        }   
    }

    if (!strcmp(inputFile, "") && missOutput == 1 && ignoreUpper == 1) {
        printf("Input path not provided\n");
        exit(1);
    } else if (missOutput == 1) {
        printf("Missing output path\n");
        exit(1);
    } else if (needlee > 1) {
        printf("Too many parameters provided\n");
        exit(1);
    } else if (needlee == 1 && !strcmp(inputFile, "")) {
        printf("Needle not provided\n");
        exit(1);
    } if (!strcmp(inputFile, "")) {
        printf("Input path not provided\n");
        exit(1);
    }

    FILE* outputPrint;
    if (output == 1) {
        outputPrint = fopen(outputFile, "w");
    }

    FILE* soubor = fopen(inputFile, "r");
    char row[101];
    while (fgets(row, sizeof(row), soubor) != NULL) {
        if (ignoreUpper == 0){ 
            if (strstr(row, needle)) {
                if (output == 0) {
                printf("%s", row);
                } else {
                    fprintf(outputPrint, "%s", row);
                }
            }
        } else if (ignoreUpper) {
            int nlenght = strlen(needle);
            int lenght = strlen(row);
            char lowerRow[101];
            char lowerNeedle[101];
            for (int i = 0; i < lenght + 1; i++) {
                lowerRow[i] = tolower(row[i]);
            }
            for (int i = 0; i < nlenght + 1; i++) {
                lowerNeedle[i] = tolower(needle[i]);
            }

            if  (strstr(lowerRow, lowerNeedle)){
                if (output == 0) {
                    printf("%s", row);
                } else {
                    fprintf(outputPrint, "%s", row);
                }
            }
        } 
    }   

    fclose(soubor);
    if (output == 1){
        fclose(outputPrint);
    }
    
    return 0;
}