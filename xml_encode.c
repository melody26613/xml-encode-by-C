#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGV_INPUT_STR 1

#define XML_SPECIAL_CHARS_NUM 5
#define MAX_XML_ENTITY_LEN 6 //strlen("&apos;") or strlen("&quot;")

#define MAX_XML_ENTITY_BUFFER_LEN (MAX_XML_ENTITY_LEN + 1)

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

int CountSpecialCharacters(char *str);
char *XmlEncode(char *str);
void XmlDecode(char *str);

int main(int argc, char *argv[]){
    if(argv[ARGV_INPUT_STR] == NULL){
        printf("usage: ./xml_encode \"input string\"\n");
        exit(-1);
    }

    /*demo XmlEncode and XmlDecode*/
    char *str = argv[ARGV_INPUT_STR];
    printf("input str: %s\n", str);

    char *str_encode = XmlEncode(str);
    if(str_encode == NULL){
        exit(-1);
    }
    printf("encode: %s\n", str_encode);

    XmlDecode(str_encode);
    printf("decode: %s\n", str_encode);
    free(str_encode);

    return 0;
}

int CountSpecialCharacters(char *str){
    int special_chars_count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; j < XML_SPECIAL_CHARS_NUM; j++){
            if(str[i] == xml_special_chars[j]){
                special_chars_count++;
            }
        }
    }
    return special_chars_count;
}

char *XmlEncode(char *str){
    int special_chars_count = CountSpecialCharacters(str);
    int max_encode_len = strlen(str) + special_chars_count * MAX_XML_ENTITY_LEN;
    char *encode_str = calloc(max_encode_len, sizeof(char));
    int encode_index = 0;

    if(encode_str == NULL){
        perror("XmlEncode calloc()");
        return NULL;
    }

    for(int i = 0; str[i] != '\0'; i++){
        bool no_encode = true;

        for(int j = 0; j < XML_SPECIAL_CHARS_NUM; j++){
            if(str[i] == xml_special_chars[j]){
                no_encode = false;
                
                int special_chars_len = strlen(xml_encode_entities[j]);
                for(int k = 0; k < special_chars_len; k++){
                    encode_str[encode_index ++] = xml_encode_entities[j][k];
                }
                break;
            }
        }
        if(no_encode){
            encode_str[encode_index ++] = str[i];
        }
    }
    return encode_str;
}

void XmlDecode(char *str){    
    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; j < XML_SPECIAL_CHARS_NUM; j++){
            if(!strncmp(str + i, xml_encode_entities[j], strlen(xml_encode_entities[j]))){
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