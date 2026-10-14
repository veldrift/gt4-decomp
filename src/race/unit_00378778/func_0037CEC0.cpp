/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct Obj { char pad0[0x148]; s32 u148; char pad1[0x2c0 - 0x14c]; s32 w; s32 w2; };
extern "C" void func_00379CE0(Obj *, s32, s32) throw();
extern "C" void func_0037CFC8(Obj *);

extern "C" void func_0037CEC0(Obj *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    char *a1;

    func_00379CE0(arg0, arg1, 0);
    arg0->u148 = 5;
    if (arg2 != 0) {
        a1 = (char *)arg0 + 0x2C0;
        *(u8 *)a1 = 0;
        *(u8 *)(a1 + 1) = 0;
        *(s32 *)a1 = *(s32 *)a1 & 0xFF00FFFF;
        *(u8 *)(a1 + 3) = 0;
        arg0->w2 = -1;
    }
    if (arg3 != 0) {
        arg0->w = *arg3;
    }
    func_0037CFC8(arg0);
}
