#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clib/boolean.h"
#include "clib/structstr.h"
#include "clib/vector.h"
#include "parser.h"

vector parse(const char *txt) {
    vector lexed;
    vec_init(&lexed);

    String new_tag;
    str_init(&new_tag);

    bool in_tag = False;

    for (size_t i = 0; txt[i]; i++) {
        char c = txt[i];

        if (c == '<') {
            if (new_tag.len > 0) {
                vec_push(&lexed, str_take(&new_tag));
                str_init(&new_tag);
            }
            in_tag = True;
            str_push(&new_tag, c);
        } 
        else if (c == '>') {
            str_push(&new_tag, c);
            if (in_tag) {
                in_tag = False;
                vec_push(&lexed, str_take(&new_tag));
                str_init(&new_tag);
            }
        } 
        else {
            str_push(&new_tag, c);
        }
    }

    if (new_tag.len > 0) {
        vec_push(&lexed, str_take(&new_tag));
    }

    return lexed;
}

void output(char in[]) {
    vector out = parse(in);
    for (size_t i = 0; i < out.len; i++) {
        char *element = out.items[i];
        printf("%s", element);
        if (i < out.len - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
#ifdef __cplusplus
}
#endif