#include "../include/components.h"

void __ADDSYMBOL_SEQ__(SEQ_SYMBOL* seq, SYMBOL symbol) {
    seq->seq = ((SYMBOL*)realloc(seq->seq, sizeof(SYMBOL)*(seq->cap+1)));
    seq->seq[seq->cap].type = symbol.type;
    seq->seq[seq->cap].value = (char*)malloc(sizeof(char)*strlen(symbol.value)+1);
    strcpy(seq->seq[seq->cap].value, symbol.value);
    seq->cap++;
    return;
}

void __ADDSEQ_CHUNK__(CHUNK_SYMBOL* chunk, SEQ_SYMBOL symbol) {
    chunk->seq = ((SYMBOL*)realloc(chunk->seq, sizeof(SYMBOL)*(chunk->cap+1)));
    chunk->seq[chunk->cap].seq = (char*)malloc(sizeof(char)*strlen(symbol.seq)+1);
    strcpy(chunk->seq[chunk->cap].seq, symbol.seq);
    chunk->cap++;
    return;
}

void __FREE_TYPE__(TYPE* type) {
    free(type->rep);
    type->id = 0;
    free(type);
    return;
}

void __FREE_SYMBOL__(SYMBOL* symbol) {
    symbol->type.free(&symbol->type);
    free(symbol->value);
    free(symbol);
    return;
}

void __FREE_SEQ__(SEQ_SYMBOL* seq) {
    seq->seq->free(seq->seq);
    seq->cap = 0;
    free(seq);
    return;
}

void __FREE_CHUNK__(CHUNK_SYMBOL* chunk) {
    chunk->seq->free(chunk->seq);
    chunk->cap = 0;
    free(chunk);
    return;
}

void __FREE_REPEAT__(REPEAT_SYMBOL* repeat) {
    repeat->chunk->free(repeat->chunk);
    free(repeat);
    return;
}



// exposed constructors
TYPE* Type(int id, char* rep) {
    TYPE* new = (TYPE*)malloc(sizeof(TYPE));
    new->id = id;
    new->rep = (char*)malloc(sizeof(char)*strlen(rep)+1);
    strcpy(new->rep, rep);
    return new;
}

SYMBOL* Symbol(TYPE* type, char* value) {
    SYMBOL* new = (SYMBOL*)malloc(sizeof(SYMBOL));
    new->type = *type;
    new->value = (char*)malloc(sizeof(char)*strlen(value)+1);
    strcpy(new->value, value);
    return new;
}

SEQ_SYMBOL* Seq() {
    SEQ_SYMBOL* new = (SEQ_SYMBOL*)malloc(sizeof(SEQ_SYMBOL));
    new->cap = 0;
    new->seq = (SYMBOL*)malloc(sizeof(SYMBOL));
    new->add = &__ADDSYMBOL_SEQ__;
    return new;
}

CHUNK_SYMBOL* Chunk() {
    CHUNK_SYMBOL* new = (CHUNK_SYMBOL*)malloc(sizeof(CHUNK_SYMBOL));
    new->cap = 0;
    new->seq = (SEQ_SYMBOL*)malloc(sizeof(SEQ_SYMBOL));
    new->add = &__ADDSEQ_CHUNK__;
    return new;
}

REPEAT_SYMBOL* Repeat() {
    REPEAT_SYMBOL* new = (REPEAT_SYMBOL*)malloc(sizeof(REPEAT_SYMBOL));
    new->chunk = (CHUNK_SYMBOL*)malloc(sizeof(CHUNK_SYMBOL));
    return new;
}


