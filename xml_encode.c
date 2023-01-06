#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xml_encode.h"

#define XML_SPECIAL_CHARS_NUM 5
#define MAX_XML_ENTITY_LEN 6 // strlen("&apos;") or strlen("&quot;")

static const char xml_special_chars[XML_SPECIAL_CHARS_NUM] = {
    '&',
    '\'',
    '\"',
    '<',
    '>'
};

static const char *xml_encode_entities[XML_SPECIAL_CHARS_NUM] = {
    "&amp;",
    "&apos;",
    "&quot;",
    "&lt;",
    "&gt;"
};

static int count_special_characters(const char *str);


char *xml_encode(const char *str) {
    int special_chars_count = count_special_characters(str);
    int max_encode_len = (strlen(str) + special_chars_count * MAX_XML_ENTITY_LEN) + 1;
    char *encode_str = (char*) calloc(max_encode_len, sizeof(char));
    int encode_index = 0;

    if (encode_str == NULL) {
        perror("xml_encode() calloc()");
        return NULL;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        bool encoded = false;

        for (int j = 0; j < XML_SPECIAL_CHARS_NUM; j++) {
            if (str[i] == xml_special_chars[j]) {
                int special_chars_len = strlen(xml_encode_entities[j]);
                strncat(encode_str, xml_encode_entities[j], special_chars_len);

                encode_index += special_chars_len;
                encoded = true;
                break;
            }
        }
        if (!encoded) {
            encode_str[encode_index++] = str[i];
        }
    }
    return encode_str;
}

static int count_special_characters(const char *str) {
    int special_chars_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < XML_SPECIAL_CHARS_NUM; j++) {
            if (str[i] == xml_special_chars[j]) {
                special_chars_count++;
            }
        }
    }
    return special_chars_count;
}

void xml_decode(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < XML_SPECIAL_CHARS_NUM; j++) {
            if (strncmp(str + i, xml_encode_entities[j], strlen(xml_encode_entities[j])) == 0) {
                str[i] = xml_special_chars[j];

                int move_len = strlen(xml_encode_entities[j]);
                char *move = str + i + move_len;

                memmove(str + i + 1, move, strlen(move));
                str[strlen(str) - move_len + 1] = '\0';
                break;
            }
        }
    }
}