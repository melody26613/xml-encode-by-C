#ifndef XML_ENCODE_H
#define XML_ENCODE_H

#ifdef __cplusplus
extern "C"{
#endif

char *xml_encode(const char *str);

void xml_decode(char *str);

#ifdef __cplusplus
}
#endif

#endif