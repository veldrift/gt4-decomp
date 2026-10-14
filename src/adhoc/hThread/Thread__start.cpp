/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj {
    s32 field0;
    char *vtbl;
};
struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *, s32, s32);
};
struct StackFrame {
    char first[0x10];
    Obj *object;
    char pad[0xC];
};

extern char D_00841060[];
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030B410(Obj *, void *, void *);
extern "C" void func_0030BB18(void *);
extern "C" void func_00318538(void *, int) throw();
extern "C" void func_00318590(void *, void *) throw();

extern "C" void Thread__start(void *arg0, Obj **arg1, s32 arg2, s32 arg3) {
    StackFrame sp;
    func_00318590(&sp, arg1);
    Obj **p = &sp.object;
    func_0030BB18(p);
    func_0030B410(*arg1, p, D_00841060);
    Obj *o = *p;
    VEntry *e = (VEntry *)(o->vtbl + 0xA0);
    e->fn((char *)o + e->delta, &sp, arg2, arg3);
    func_00309378(p, 2);
    func_00318538(&sp, 2);
}
