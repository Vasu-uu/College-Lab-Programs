#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateObjectCode();

int main() {
    FILE *fIntermediate, *fSymtab, *fOptab, *fList;
    char locctr[10], lbl[10], opcd[10], oprnd[20];
    char code[10], value[10], symbl[10], addr[10];

    fIntermediate = fopen("intermediate.txt", "r");
    fSymtab = fopen("symtab.txt", "r");
    fOptab = fopen("optab.txt", "r");
    fList = fopen("file.txt", "w");

    if (!fIntermediate || !fSymtab || !fOptab || !fList) {
        printf("Error opening files.\n");
        return 1;
    }

    fscanf(fIntermediate, "%s %s %s %s", locctr, lbl, opcd, oprnd);
    if (strcmp(opcd, "START") == 0) {
        fprintf(fList, "%s\t%s\t%s\t%s\n", locctr[0]?locctr:"-", lbl, opcd, oprnd);
        fscanf(fIntermediate, "%s %s %s %s", locctr, lbl, opcd, oprnd);
    }

    while (strcmp(opcd, "END") != 0) {
        if (strcmp(opcd, "BYTE") == 0) {
            fprintf(fList, "%s\t%s\t%s\t%s\t", locctr, lbl[0]?lbl:"-", opcd, oprnd);
            if (oprnd[0] == 'C') {
                for (int i = 2; i < strlen(oprnd)-1; i++)
                    fprintf(fList, "%02X", oprnd[i]); 
            } else if (oprnd[0] == 'X') {
                for (int i = 2; i < strlen(oprnd)-1; i++)
                    fprintf(fList, "%c", oprnd[i]); 
            }
            fprintf(fList, "\n");
        } else if (strcmp(opcd, "WORD") == 0) {
            int wordValue = atoi(oprnd); 
            fprintf(fList, "%s\t%s\t%s\t%s\t%06X\n", locctr, lbl[0]?lbl:"-", opcd, oprnd, wordValue); 
        } else if ((strcmp(opcd, "RESB") == 0) || (strcmp(opcd, "RESW") == 0)) {
            fprintf(fList, "%s\t%s\t%s\t%s\n", locctr, lbl[0]?lbl:"-", opcd, oprnd);
        } else { 
            rewind(fOptab);
            int opFound = 0;
            while(fscanf(fOptab, "%s %s", code, value) != EOF) {
                if(strcmp(opcd, code) == 0) {
                    opFound = 1;
                    break;
                }
            }

            if(opFound) {
                rewind(fSymtab);
                char operandAddr[10] = "0000"; 
                while(fscanf(fSymtab, "%s %s", addr, symbl) != EOF) {
                    if(strcmp(symbl, oprnd) == 0) {
                        strcpy(operandAddr, addr);
                        break;
                    }
                }

                fprintf(fList, "%s\t%s\t%s\t%s\t%s%s\n", locctr, lbl[0]?lbl:"-", opcd, oprnd, value, operandAddr);
            }
        }
        fscanf(fIntermediate, "%s %s %s %s", locctr, lbl, opcd, oprnd);
    }

    fprintf(fList, "%s\t%s\t%s\t%s\n", locctr[0]?locctr:"-", lbl[0]?lbl:"-", opcd, oprnd);

    fclose(fIntermediate);
    fclose(fSymtab);
    fclose(fOptab);
    fclose(fList);

    printf("Intermediate listing (file.txt) generated successfully.\n");

    generateObjectCode();
    return 0;
}

void generateObjectCode() {
    FILE *fList = fopen("file.txt", "r");
    FILE *fObj = fopen("objcode.txt", "w");
    if (!fList || !fObj) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    char loc[10], label[10], opcode[10], operand[20], objcode[20];
    char progname[10] = "COPY";
    int startAddr = 0, firstAddr = 0, lastAddr = 0;
    int textLen = 0;
    char textRecord[100] = "";
    int currentTextStartLoc = 0;

    fgets(line, sizeof(line), fList);
    sscanf(line, "%s %s %s %s", loc, label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        startAddr = strtol(operand, NULL, 16); 
        firstAddr = startAddr;
        strcpy(progname, label);
    } else {
        rewind(fList);
    }

    while (fgets(line, sizeof(line), fList) != NULL) {
        sscanf(line, "%s %s %s %s", loc, label, opcode, operand);
        if (strcmp(opcode, "END") == 0) {
            lastAddr = strtol(loc, NULL, 16); 
            break;
        }
    }
    
    int progLen = lastAddr - startAddr;
   
    fprintf(fObj, "H^%-6s^%06X^%06X\n", progname, startAddr, progLen);

    rewind(fList);
    fgets(line, sizeof(line), fList); 
   
    textLen = 0;
    textRecord[0] = '\0';

    while (fgets(line, sizeof(line), fList) != NULL) {
        objcode[0] = '\0'; 
        int fields = sscanf(line, "%s %s %s %s %s", loc, label, opcode, operand, objcode);
       
        if (fields < 4 || loc[0] == '-') continue;
        if (strcmp(opcode, "END") == 0) break;
       
        int currentLoc = strtol(loc, NULL, 16); 

        if (objcode[0] == '\0') continue;

        int bytes = strlen(objcode) / 2; 

        if (textLen == 0) {
            currentTextStartLoc = currentLoc;
        }
       
        if (textLen + bytes > 30) {
            fprintf(fObj, "T^%06X^%02X%s\n", currentTextStartLoc, textLen, textRecord);
            textLen = 0;
            textRecord[0] = '\0';
            currentTextStartLoc = currentLoc;
        }

        strcat(textRecord, "^");
        strcat(textRecord, objcode);
        textLen += bytes;
    }

    if (textLen > 0) {
        fprintf(fObj, "T^%06X^%02X%s\n", currentTextStartLoc, textLen, textRecord);
    }

    fprintf(fObj, "E^%06X\n", firstAddr); 

    fclose(fList);
    fclose(fObj);

    printf("SIC Object Program (objcode.txt) generated successfully.\n");
}