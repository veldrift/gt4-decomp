typedef int s32;
typedef unsigned int u32;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" s32 func_00147D80(s32 arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, u32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_003434A8(u32 *arg0, u32 arg1);

extern "C" void MCarGarage__get_odometer(s32 *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 newVal;
    s32 oldVal;
    u32 *s2;

    func_0013BDC0(buf, arg1);
    s2 = (u32 *)((char *)func_00147D80(buf[0]) + 0x4A0);
    func_0013BD68(buf, 2);
    if (n > 0) {
        Obj *o = args[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        s32 v = e->fn((char *)o + e->delta);
        func_003434A8(s2, v);
        return;
    }
    func_002FE278(buf, *s2);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf, 2);
}
