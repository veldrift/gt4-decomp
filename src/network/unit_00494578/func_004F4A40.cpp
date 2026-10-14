/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub {
    char pad0[0x18];
    int m18;
    char t1C[0x14];
    int m30;
    int m34;
};
struct Obj {
    char pad[0x5A8];
    Sub *m5A8;
    char pad2[0x54C];
    char tAF8[0x11];
};
extern "C" int func_004F0C88(Obj *) throw();
extern "C" void func_004F0CD0(Obj *, int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_005A6AB0(void *, void *, int) throw();

extern "C" void func_004F4A40(Obj *o, int a, int b) {
    if (func_004F0C88(o) != 0) {
        func_005A48D8(o->m5A8, 0, 0x38);
        Sub *s = o->m5A8;
        func_005A6AB0(s->t1C, o->tAF8, 0x11);
        s->m18 = (a != 0) ? 2 : -0x3D9;
        s->m30 = b;
        s->m34 = 1;
        return func_004F0CD0(o, 0x44);
    }

}
