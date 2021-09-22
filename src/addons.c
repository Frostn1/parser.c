#include "../include/addons.h"

int isalpha(char chr) {
    return chr >= 'A' && chr <= 'Z' ||
        chr >= 'a' && chr <= 'z';
}

int isnumber(char chr) {
    return chr >= '0' &&  chr <= '9';
}

int isspecial(char chr) {
    return !isnumber(chr) && !isalpha(chr) && isnumber != '\n';
}

int isspace(char chr) {
    return chr == ' ';
}

char peek(char* string, int index, int size) {
    if(index+1 >= size) return '\0';
    return string[index + 1];
}