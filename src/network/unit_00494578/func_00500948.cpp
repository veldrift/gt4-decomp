/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef unsigned short u16;
struct Rec505938 {
    char pad0[0x12];
    s16 h12;
    s16 h14;
    s16 h16;
    s16 h18;
    int w1C;
};
struct Obj {
    char pad[0x5B8];
    int m5B8;
};
extern "C" int func_0052F880(int, int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" int func_00505938(Rec505938 *);

extern "C" int func_00500948(Obj *o) {
    u16 v[8];
    Rec505938 r;
    if (func_0052F880((int)v, o->m5B8) != 0) {
        return 0;
    }
    func_005A609C((char *)&r, (char *)o + 0x3F28);
    r.h12 = 1;
    r.h14 = 6;
    r.h18 = v[0];
    r.h16 = 1;
    r.w1C = 0;
    func_00505938(&r);
    return 1;
}
