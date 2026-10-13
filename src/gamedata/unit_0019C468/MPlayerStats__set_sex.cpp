typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj { char pad0[4]; VEntry *vtbl; };

extern "C" void func_0019C1D8(void *arg0, void *arg1);
extern "C" void func_0019C180(void *arg0, int arg1);

extern "C" void func_0019C990(void *a0, void *a1, void *a2, Obj **a3) {
    s32 buf[4];
    s32 s1;
    Obj *obj;
    VEntry *e;
    func_0019C1D8(buf, a1);
    s1 = buf[0];
    obj = *a3;
    e = (VEntry *)((char *)obj->vtbl + 0x58);
    *(u8 *)((char *)s1 + 0x11) = e->fn((char *)obj + e->delta);
    func_0019C180(buf, 2);
}
