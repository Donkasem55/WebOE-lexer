#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>

typedef struct {
    char **items;
    size_t len;
    size_t cap;
} vector;

void vec_init(vector *v) {
    v->len = 0;
    v->cap = 4; // starting capacity
    v->items = malloc(sizeof(char*) * v->cap);
}

void vec_push(vector *v, char *s) {
    if (v->len == v->cap) {
        v->cap *= 2;
        v->items = realloc(v->items, sizeof(char*) * v->cap);
    }
    v->items[v->len++] = s;
}

char *vec_pop(vector *v) {
    if (v->len == 0) return NULL;
    return v->items[--v->len];
}
#ifdef __cplusplus
}
#endif