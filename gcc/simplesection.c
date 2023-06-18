/**
  *Author:      yulmx
  *Linux:       gcc -c simplesection.c
  *Windows:     cl simplesection.c /c /Za
**/

int global_init_var = 50;
int global_uninit_var;

int printf(const char* format, ...);

void func1(int i) {
    printf("%d\n", i);
}

int main() {
    static int static_var = 51;
    static int static_auto_var;
    int local_init_var = 1;
    int local_auto_var;

    func1(static_var + static_auto_var + local_init_var + local_auto_var);

    return 0;
}