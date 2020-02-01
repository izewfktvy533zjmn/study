#include <stdio.h>

void test(int n, char* s) {
    printf("%d %s\n", n, s);
}

void func(void (*test_func)(int, char*), int n, char* s) {
    (*test_func)(n, s);
}

int main() {
    void (*test_func)(int, char*) = test;
    func(test_func, 1, "test");
    return 0;
}
