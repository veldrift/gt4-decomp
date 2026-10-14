struct B8 { char c[8]; };
struct Ent { char pad[0x2C]; unsigned short v; char pad2[0x44 - 0x2E]; };
struct Dev { char pad[0x84]; Ent *tab; };

struct Out {
    short id; char pad2[2]; B8 a; B8 b; unsigned short s14; unsigned short s16;
    short s18; char c1a; char pad1b; char pad1c[0x5C - 0x1C]; unsigned short s5c;
};
struct Hook { char pad[0x28]; void (*fn)(int, int, void *); };
extern Hook *D_0064B710;
extern "C" void func_00526040(Dev *, int *, unsigned short *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00525648(int, int) throw() __attribute__((const));
extern "C" int func_00523C20(Dev *, int, int, void *, unsigned short *) throw();
extern "C" int func_00523CE0(Dev *, int, void *, unsigned short *) throw();

static inline unsigned short invalid_id() { return 0xFFFE; }

extern "C" int func_00526128(Dev *arg0, int arg1, Out *arg2) {
    struct { B8 m0; char p0[8]; B8 m1; char p1[8]; unsigned short s20, p20; int s24; unsigned short s28, p28, s2c, p2c; } L;
    int s0 = arg1 & 0xFFFF;
    int r;
    L.s24 = 0;
    L.s20 = invalid_id();
    func_00526040(arg0, &L.s24, &L.s20);
    func_005A48D8(arg2, 0, 0x64);
    arg2->id = func_00525648(0, 0x64);
    arg2->s18 = s0;
    arg2->s5c = arg0->tab[s0].v;
    if (s0 == L.s20) {
        arg2->c1a = 1;
        r = func_00523CE0(arg0, 0, &L.m0, &L.s28);
        if (r != 0) return r;
        r = func_00523CE0(arg0, 1, &L.m1, &L.s2c);
        if (r != 0) return r;
    } else {
        r = func_00523C20(arg0, s0, 0, &L.m0, &L.s28);
        if (r != 0) return r;
        r = func_00523C20(arg0, s0, 1, &L.m1, &L.s2c);
        if (r != 0) return r;
    }
    {
        arg2->a = L.m0;
        arg2->b = L.m1;
        arg2->s14 = L.s28;
        arg2->s16 = L.s2c;
        if (D_0064B710 != 0) D_0064B710->fn(-1, 0, (char *)arg2 + 0x1C);
    }
    return r;
}
