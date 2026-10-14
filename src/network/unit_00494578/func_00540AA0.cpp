struct O {
    char pad0[8];
    char c8;
    char pad1[0xFF];
    char t108[0x100];
    int m208;
    int m20C;
};
extern char D_006C4F40[];
extern "C" int func_0053F300(char *, int *, const char *) throw();
extern "C" char *func_005A6DC8(const char *, const char *) throw();

extern "C" void func_00540AA0(const char *s, O *o) {
    if (o->m20C == 0) {
        if (func_0053F300(o->t108, &o->m208, s) == 0) {
            o->m20C = 1;
        }
        if (func_005A6DC8(D_006C4F40, s) != 0) {
            o->c8 = 10;
        }
    }
}
