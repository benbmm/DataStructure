#include <stdio.h>
#include <string.h>

typedef struct {
    char c;       // 1 byte
    int i;        // 4 bytes
    union {
        double d; // 8 bytes
        int x;    // 4 bytes
    } u;
    enum { A, B, C } type; // 4 bytes
} mystruct;

int main() {
    mystruct s;

    // 初始化各欄位
    s.c = 'Z';
    s.i = 42;
    s.u.d = 3.14159;  // 使用 union 中的 double
    s.type = B;

    // 輸出欄位內容
    printf("char c      : %c\n", s.c);
    printf("int i       : %d\n", s.i);
    printf("union u.d   : %.5f\n", s.u.d);
    printf("enum type   : %d\n", s.type);

    // 檢查整體結構大小
    printf("sizeof(mystruct) = %zu bytes\n", sizeof(mystruct));

    return 0;
}
