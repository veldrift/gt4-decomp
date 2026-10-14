struct S8 { int a, b; };
struct Obj {
    int f0; int f4; S8 name;
    int pad10[(0x88 - 0x10) / 4];
    int a88[43];
    int a134[43];
    int f1E0, f1E4, f1E8;
    void *f1EC;
};
extern char D_006882C0[];
extern S8 D_006A6D18;
extern "C" int func_00443308(Obj *o) {
    o->f0 = 0;
    o->f1EC = D_006882C0;
    o->f4 = -1;
    S8 *d = &o->name;
    for (int i = 42; i >= 0; i--) {
        o->a88[42 - i] = 0;
        o->a134[42 - i] = 0;
    }
    o->f1E0 = 0;
    o->f1E4 = 0;
    o->f1E8 = 0;
    __builtin_strcpy((char *)d, "specdb/");
}
