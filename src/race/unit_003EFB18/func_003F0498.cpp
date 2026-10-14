/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Rec { s32 t; char pad[0x2c]; };
struct Car { char pad[0x544]; u8 idx; };
extern "C" Rec D_008456C0[6];
extern "C" s32 D_008457E0[6];
extern "C" Rec D_008457F8[6];
extern "C" s32 D_00845918[6];
extern "C" void func_003F0498(Car *car, Rec *rec, s32 val) {
    if ((unsigned)(rec->t + 1) < 2u)
        return;
    int i = car->idx;
    s32 *b = &D_008457E0[i];
    Rec *c;
    Rec *a = &D_008456C0[i];
    if (a->t < rec->t) {
        c = &D_008457F8[i];
        s32 old = *b;
        c->t = a->t;
        *c = *a;
        D_00845918[i] = old;
        *b = val;
        a->t = rec->t;
        *a = *rec;
    }
}
