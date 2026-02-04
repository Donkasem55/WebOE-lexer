#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>

typedef struct {
    char *data;
    size_t len;
    size_t cap;
} String;

void str_init(String *s) {
    s->cap = 16;
    s->len = 0;
    s->data = malloc(s->cap);
    s->data[0] = '\0';
}

void str_push(String *s, char c) {
    if (s->len + 1 >= s->cap) {
        s->cap *= 2;
        s->data = realloc(s->data, s->cap);
    }
    s->data[s->len++] = c;
    s->data[s->len] = '\0';
}

char *str_take(String *s) {
    char *out = s->data;
    s->data = NULL;
    s->len = s->cap = 0;
    return out;
}
#ifdef __cplusplus
}
#endif