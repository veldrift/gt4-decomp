struct B { char p[0x1C]; char *tab; };
struct A { char p[4]; B *f4; };
struct E { char p[4]; short a; short b; short c; };
extern "C" int func_0042A220(A *self, int idx);
extern "C" int func_00429060(A *self, int a1, int a2, int a3, float f0, int a4, int a5, int a6, float f1);

extern "C" int func_00428F88(A *self, int arg1, int arg2, int arg3, int arg4, float f0, float f1) {
    int r = func_0042A220(self, arg1);
    if (r != 0) {
        r = 0;
        if (self->f4 != 0) {
            return func_00429060(self, ((E *)(self->f4->tab + arg1 * 0x10))->a, ((E *)(self->f4->tab + arg1 * 0x10))->b, ((E *)(self->f4->tab + arg1 * 0x10))->c, f0, arg2, arg3, arg4, f1);
        }
    }
    return r;
}
