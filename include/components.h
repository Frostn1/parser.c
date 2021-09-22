#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string.h>

typedef struct type_ {
    int id; // Id of the type based of enum
    char* rep; // Represntation in string

    void (*free)(TYPE* type);
}TYPE;

typedef struct symbol_ {
    TYPE type;
    char* value;

    void (*free)(SYMBOL* type);
}SYMBOL;

typedef struct seq_ {
    int cap;
    SYMBOL* seq; // Array

    void (*add)(SEQ_SYMBOL* seq, SYMBOL symbol);
    void (*free)(SEQ_SYMBOL* type);
}SEQ_SYMBOL;

typedef struct chunk_ {
    int cap;
    SEQ_SYMBOL* seq; // Array
    void (*add)(CHUNK_SYMBOL* chunk, SEQ_SYMBOL symbol);
    void (*free)(CHUNK_SYMBOL* type);
}CHUNK_SYMBOL;

typedef struct repeat_ {
    CHUNK_SYMBOL* chunk; // Pointer
    
    void (*free)(REPEAT_SYMBOL* type);
}REPEAT_SYMBOL;


#endif // !COMPONENETS_H