#include <stdio.h>
#include <stddef.h>  // for offsetof

typedef struct {
    char c1;        // 1 byte
    int i;          // 4 bytes
    char c2;        // 1 byte
    double d;       // 8 bytes
} TestStruct;

int main() {
    TestStruct s;

    printf("Memory Layout of TestStruct:\n");
    printf("-----------------------------------\n");
    printf("Size of TestStruct        : %zu bytes\n", sizeof(TestStruct));
    printf("Offset of c1              : %zu bytes\n", offsetof(TestStruct, c1));
    printf("Offset of i               : %zu bytes\n", offsetof(TestStruct, i));
    printf("Offset of c2              : %zu bytes\n", offsetof(TestStruct, c2));
    printf("Offset of d               : %zu bytes\n", offsetof(TestStruct, d));
    printf("-----------------------------------\n");
    printf("Address of s              : %p\n", (void*)&s);
    printf("Address of s.c1           : %p\n", (void*)&s.c1);
    printf("Address of s.i            : %p\n", (void*)&s.i);
    printf("Address of s.c2           : %p\n", (void*)&s.c2);
    printf("Address of s.d            : %p\n", (void*)&s.d);
    printf("-----------------------------------\n");

    return 0;
}
