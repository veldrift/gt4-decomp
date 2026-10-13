typedef int s32;
typedef unsigned short u16;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct H {
    void *p;
    char pad[0xC];
};

struct S;
struct func_00446AE0_Obj;

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" int func_00147D80(S *arg0);
extern "C" s32 func_00441248(Obj *arg0);
extern "C" void func_00446AE0(func_00446AE0_Obj *self, unsigned short id);

extern "C" void MCarGarage__removeParts(void *arg0, void *arg1, int count, void **arg3) {
    if (count > 0) {
        H h;
        func_0013BDC0(&h, arg1);
        Obj *o = (Obj *)*arg3;
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        s32 id = e->fn((char *)o + e->delta);
        s32 obj = func_00147D80((S *)h.p);
        id &= 0xFFFF;
        s32 self = func_00441248((Obj *)obj);
        func_00446AE0((func_00446AE0_Obj *)self, (u16)id);
        func_0013BD68(&h, 2);
    }
}
