typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj {
    char pad[0x4A0];
    s32 unk4A0;
};

struct Dest {
    s32 v[8];
};

typedef Dest S;

extern char D_006A6988[];

extern "C" s32 func_00441280(Obj *arg0);
extern "C" s32 func_00445350(Obj *arg0);
extern "C" int func_004487D8(void *arg0, Dest *dest);
extern "C" s32 func_00448868(S *arg0);

extern "C" s32 func_00441128(Obj *arg0) {
    char *a0 = D_006A6988 + 4;
    s32 i;
    char *t1;
    Dest d;
    f32 f20;
    u32 q;
    s32 key;
    s32 r;
    s32 v;

    i = 0;
    t1 = a0 - 4;
    f20 = 0.0f;
    q = (u32)arg0->unk4A0 / 1000000u;
    while (i < 10) {
        key = *(s32 *)(t1 + i * 8);
        if ((s32)q < key || key < 0) {
            f20 = *(f32 *)(a0 + i * 8);
            break;
        }
        i++;
    }

    r = func_00441280(arg0);
    r = func_00445350((Obj *)r);
    func_004487D8((void *)r, &d);
    v = func_00448868(&d);
    return (s32)((f32)v * f20);
}
