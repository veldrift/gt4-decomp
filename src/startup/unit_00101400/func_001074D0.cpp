typedef int s32;
struct Entry { s32 p0, p4, p8, pC; };
struct T {
    s32 f0, f4, f8;
    char pad[0x18];
    s32 f24, f28, f2c, f30, f34, f38;
};
extern "C" Entry *func_00106058(s32);
extern s32 D_0081EB00;
extern "C" void func_001074D0(T *t, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 w = a1 != 0 ? a1 : 1;
    s32 c = t->f2c;
    c = c == 0 ? 1 : c;
    if (a2 == 0) a2 = D_0081EB00;
    if (c != w || t->f30 != a2 || t->f34 != a3 || t->f38 != a4) {
        Entry *e = func_00106058(a2);
        t->f28 = (t->f4 ^ e->p8) ? 0x3C : 3;
        t->f0 = e->p4;
        t->f4 = e->p8;
        t->f8 = e->pC;
        t->f24 = 1;
        t->f2c = a1;
        t->f30 = a2;
        t->f34 = a3;
        t->f38 = a4;
    }
}
