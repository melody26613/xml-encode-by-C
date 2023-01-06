#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
#include "xml_encode.h"

static const char STR1[] = "&'\"<>";
static const char STR1_ENCODE[] = "&amp;&apos;&quot;&lt;&gt;";

static const char STR2[] = "&&&''\"<>>><";
static const char STR2_ENCODE[] = "&amp;&amp;&amp;&apos;&apos;&quot;&lt;&gt;&gt;&gt;&lt;";

static const char STR3[] = "&amp;&amp;&\"<&apos;>>><";
static const char STR3_ENCODE[] = "&amp;amp;&amp;amp;&amp;&quot;&lt;&amp;apos;&gt;&gt;&gt;&lt;";

TEST(testEncode, STR1) {
    char *str_encode = xml_encode(STR1);

    ASSERT_STREQ(str_encode, STR1_ENCODE);

    free(str_encode);
    str_encode = NULL;
}

TEST(testEncode, STR2) {
    char *str_encode = xml_encode(STR2);

    ASSERT_STREQ(str_encode, STR2_ENCODE);

    free(str_encode);
    str_encode = NULL;
}

TEST(testEncode, STR3) {
    char *str_encode = xml_encode(STR3);

    ASSERT_STREQ(str_encode, STR3_ENCODE);

    free(str_encode);
    str_encode = NULL;
}

TEST(testDecode, STR1) {
    char *str = (char*) calloc(strlen(STR1_ENCODE) + 1, sizeof(char));
    strncpy(str, STR1_ENCODE, strlen(STR1_ENCODE));
    xml_decode(str);

    ASSERT_STREQ(str, STR1);

    free(str);
    str = NULL;
}

TEST(testDecode, STR2) {
    char *str = (char*) calloc(strlen(STR2_ENCODE) + 1, sizeof(char));
    strncpy(str, STR2_ENCODE, strlen(STR2_ENCODE));
    xml_decode(str);

    ASSERT_STREQ(str, STR2);

    free(str);
    str = NULL;
}

TEST(testDecode, STR3) {
    char *str = (char*) calloc(strlen(STR3_ENCODE) + 1, sizeof(char));
    strncpy(str, STR3_ENCODE, strlen(STR3_ENCODE));
    xml_decode(str);

    ASSERT_STREQ(str, STR3);

    free(str);
    str = NULL;
}

TEST(testEncodeDecode, STR1) {
    char *str = xml_encode(STR1);
    xml_decode(str);

    ASSERT_STREQ(str, STR1);

    free(str);
    str = NULL;
}

TEST(testEncodeDecode, STR2) {
    char *str = xml_encode(STR2);
    xml_decode(str);

    ASSERT_STREQ(str, STR2);

    free(str);
    str = NULL;
}

TEST(testEncodeDecode, STR3) {
    char *str = xml_encode(STR3);
    xml_decode(str);

    ASSERT_STREQ(str, STR3);

    free(str);
    str = NULL;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}