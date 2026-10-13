typedef int s32;
typedef unsigned char u8;

struct Blk20 {
    char b[0x10];
    s32 w;
};

struct Blk8 {
    char b[8];
};

struct Pair {
    s32 w0;
    char p0[4];
    s32 w8;
};

struct Locals {
    char s20[0xC0];
    s32 w;
    char pad[0x1C];
    Blk8 t8;
};

struct Obj;

extern "C" void func_004AF6B8(void *);
extern "C" void func_004AF598(void *);
extern "C" s32 func_004AE1F8(s32, s32);
extern "C" void func_004AF3E8(Obj *);
extern "C" void func_004AF568(Obj *);
extern "C" void func_004AF5D8(void *, s32);

extern "C" void *func_004AE440(void *arg0, s32 arg1, Blk8 *arg2, Pair *arg3, s32 arg4) {
    Blk20 L;
    Locals loc;
    char *o;
    char *p8;

    func_004AF6B8(&L);
    func_004AF598(loc.s20);
    o = (char *)func_004AE1F8((s32)loc.s20, arg1);
    p8 = (char *)arg3 + 8;
    if (o != 0) {
        loc.t8 = *arg2;
        loc.w = arg4;
        *(s32 *)(o + 0x74) = 0;
        if (arg3->w0 != 0) {
            *(Blk8 *)(o + 0x64) = *(Blk8 *)arg3;
        }
        if (*(s32 *)p8 != 0) {
            *(Blk8 *)(o + 0x6C) = *(Blk8 *)p8;
        }
        func_004AF3E8((Obj *)o);
        L = *(Blk20 *)(o + 0x84);
        func_004AF568((Obj *)o);
    }
    *(Blk20 *)arg0 = L;
    func_004AF5D8(loc.s20, 2);
    return arg0;
}
