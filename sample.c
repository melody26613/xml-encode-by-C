#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "xml_encode.h"

#define ARGV_INPUT_STR 1

#define LOG(format, arg...) \
    printf("[%s(): %d] " format, __FUNCTION__, __LINE__,  ##arg)

typedef enum {
    APP_EXIT_NORMAL = 0,
    APP_EXIT_ARGUMENT_INCORRECT,
    APP_EXIT_ENCODE_ERROR
} app_exit_code;


int main(int argc, char *argv[]) {
    if (argv[ARGV_INPUT_STR] == NULL) {
        LOG("usage: %s \"input string\"\n", argv[0]);
        exit(APP_EXIT_ARGUMENT_INCORRECT);
    }

    char *str = argv[ARGV_INPUT_STR];
    char *str_encode = NULL;
    LOG("input str: %s\n", str);

    str_encode = xml_encode(str);
    if (str_encode == NULL) {
        exit(APP_EXIT_ENCODE_ERROR);
    }
    LOG("encode: %s\n", str_encode);

    xml_decode(str_encode);
    LOG("decode: %s\n", str_encode);

    free(str_encode);
    str_encode = NULL;

    return APP_EXIT_NORMAL;
}