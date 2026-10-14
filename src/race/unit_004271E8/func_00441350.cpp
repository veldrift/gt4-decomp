extern "C" int func_00441300(int n);
extern "C" int func_004462E0(void *p);

extern "C" void func_00441350(char *arg0) {
    char *s1 = arg0 + 0xF8;
    char *s0 = arg0 + 8;
    int i = 2;
    do {
        int r = func_004462E0(s0);
        s0 += 0x178;
        i -= 1;
        *(long *)s1 = *(long *)(arg0 + func_00441300(r) * 8 + 0x470);
        s1 += 0x178;
    } while (i >= 0);
}
