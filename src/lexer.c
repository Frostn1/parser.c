#include <string.h>
#include <stdlib.h>
#include "../include/addons.h"

void __LEXIFY__(char* code) {
    int size = strlen(code), index = 0, currentSize = 0;
    char currentIden[256] = { 0 };

    while(index < size) {
        while(isspace(code[index])) index++;
        if(isalpha(code[index])) {
            currentIden[currentSize++] = code[index];
            index++;
        } else if(isnumber(code[index])) {
            currentIden[currentSize++] = code[index];
            index++;
        } else {
            switch(code[index]) {
                
            }
        }
        
    }
}