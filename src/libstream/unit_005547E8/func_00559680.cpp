typedef int s32;

extern "C" void func_00558DA8(char *p);

extern "C" void func_00559680(char *arg0) {
    char *a = arg0;
    s32 n = 0x17;
    do {
        char *next = a + 0x58;
        func_00558DA8(a);
        a = next;
        n--;
    } while (n != -1);
}
