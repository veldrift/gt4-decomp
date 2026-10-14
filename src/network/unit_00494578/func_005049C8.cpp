extern "C" void func_00504630(int) throw();
extern "C" int func_00504640(void) throw();
extern "C" void func_00504728(void *) throw();
extern "C" void func_005048D8(void *) throw();
extern "C" void func_005049B8(int *) throw();
extern "C" int func_0052EAF8(signed char, int, int, int, int, int, void *);
extern int D_0064A150;

struct L {
    char a[0x1C];
    char b[0x34];
    int code;
};

extern "C" int func_005049C8(void) {
    L l;
    int r = 0;
    if (func_00504640() == 1) {
        func_00504630(0);
        func_005049B8(&l.code);
        if (l.code == 0) {
            func_005048D8(l.a);
            func_00504728(l.b);
            r = func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 1, 0x4C, l.a);
        }
        if (r != 0) return -5;
    } else {
        if (func_00504640() == 3) return -14;
        if (func_00504640() == 2) return -5;
    }
    return 0;
}
