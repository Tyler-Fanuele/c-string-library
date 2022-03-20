#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char** argv) {
    // Constructor testing
    MY_STRING string = string_init("test");
    MY_STRING string2 = string_init("test2");
    MY_STRING test = string_init_default();

    // test Concat
    string_concat(string, string2);

    printf("%s\n%s\n%s\n", string_c_str(string), string_c_str(string2), string_c_str(test));

    if (string_find(string, string2)) {
        printf("is in\n");
    }

    string_insertion(string, stdout);

    // Bookend testing
    string_destroy(&string);
    string_destroy(&string2);
    string_destroy(&test);
    return 0;
}
