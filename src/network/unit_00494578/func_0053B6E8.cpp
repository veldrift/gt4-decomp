struct Iface { char pad[0x80]; int (*f80)(int, char *); };
extern Iface *D_0064B4B0;
extern char D_006C3B40[];
extern "C" char *func_0053B538(char **, const char *) throw();
extern "C" unsigned int func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" long func_005A7170(const char *, char **, int) throw();

extern "C" int func_0053B6E8(char *arg0, char *arg1, int arg2, int *arg3) {
    int n = 0;
    unsigned int i = 0;
    char *sp0 = 0;
    if (arg0 == 0) return 2;
    if (arg1 == 0) return 2;
    for (; i < func_0057F260(arg0); i++) {
        char *p = arg0 + i;
        if (*p != '/') continue;
        n++;
        if (n == 2) {
            sp0 = p + 1;
        } else if (n == 3) {
            func_005A6AB0(arg1, p + 1, 0x200);
            *p = 0;
            char *t = func_0053B538(&sp0, D_006C3B40);
            if ((unsigned)((unsigned char)*t - '0') >= 10) return 0xD6DC;
            D_0064B4B0->f80(arg2, t);
            if (sp0 != 0) *arg3 = (int)func_005A7170(sp0, 0, 10);
            else *arg3 = 0x50;
        }
    }
    return 0;
}
