typedef int s32;
typedef unsigned char u8;

struct Blk20 {
    char b[0x10];
    s32 w;
};

struct Blk8 {
    char b[8];
};

struct Locals {
    char s20[0xE0];
    Blk8 t8;
};

extern "C" void func_004AF6B8(void *);
extern "C" void func_004AF598(void *);
extern "C" s32 func_004AE1F8(s32, s32);
extern "C" void func_004AF3E8(void *);
extern "C" void func_004AF568(void *);
extern "C" void func_004AF5D8(void *, s32);

extern "C" void *func_004AE5C0(void *arg0, s32 arg1, void *arg2) {
    Blk20 L;
    Locals loc;
    char *o;

    func_004AF6B8(&L);
    func_004AF598(loc.s20);
    o = (char *)func_004AE1F8((s32)loc.s20, arg1);
    if (o != 0) {
        loc.t8 = *(Blk8 *)arg2;
        *(s32 *)(o + 0x74) = 1;
        func_004AF3E8(o);
        L = *(Blk20 *)(o + 0x84);
        func_004AF568(o);
    }
    *(Blk20 *)arg0 = L;
    func_004AF5D8(loc.s20, 2);
    return arg0;
}
