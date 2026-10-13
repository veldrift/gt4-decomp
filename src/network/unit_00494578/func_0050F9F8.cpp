typedef int s32;

struct Obj;
typedef s32 (*ObjFn)(Obj *, s32, s32);

struct Obj {
    char pad0[0x24];
    ObjFn fn;
};

extern "C" Obj *D_0064A55C;
extern "C" char D_006C2200[];
extern "C" void func_0057D9C0(const char *fmt, ...);

extern "C" s32 func_0050F9F8(s32 arg0, s32 arg1) {
    Obj *o = D_0064A55C;
    s32 r = o->fn(o, arg0, arg1);
    if (r != 0) {
        func_0057D9C0(D_006C2200, r);
        return -0xD;
    }
    return r;
}
