typedef int s32;
typedef float f32;

struct Obj {
    char p0[0xC];
    char *fC;
};

extern "C" s32 func_004080B8(Obj *arg0);
extern "C" void func_00407DE8(char *p, s32 a, f32 x, s32 b, f32 y);
extern "C" void func_00407EF0(char *p, s32 a);

extern "C" void func_004081B8(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0, f32 fparg1) {
    if (func_004080B8(arg0) != 0) {
        s32 off = arg1 * 0x178;
        func_00407DE8(arg0->fC + off, arg3, fparg0, arg4, fparg1);
        func_00407EF0(arg0->fC + off, arg2);
    }
}
