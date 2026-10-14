typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern "C" void func_00304210(void *arg0, void *arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_003041B8(void *arg0, int arg1);
extern "C" u8 *func_00314920(u8 *arg0);

struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; char *vtbl; };

struct A {
    VObj *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void Module__global_0083F008(void *arg0, void *arg1, int count, void *name)
{
    if (count == 1) {
        A a;
        B b;
        func_00304210(&a, arg1);
        func_00312370(&b, name);
        VObj *o = a.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x190);
        char *self = (char *)o + e->delta;
        u8 *arg = func_00314920((u8 *)get(&b));
        e->fn(self, arg);
        func_00312318(&b, 2);
        func_003041B8(&a, 2);
    }
}
