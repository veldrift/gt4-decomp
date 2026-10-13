typedef int s32;
typedef unsigned char u8;

extern "C" void func_0024E3D0(void *, void *);
extern "C" void func_0024E378(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" u8 *func_00314920(u8 *);

struct VEntry { short delta; short index; void (*fn)(void *, u8 *); };
struct VObj { char pad0[4]; char *vtbl; };

struct A {
    VObj *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline u8 *get(B *b) { return (u8 *)b->v[0]; }

extern "C" void func_0024EE38(void *arg0, void *arg1, int arg2, void *arg3)
{
    A a;
    B b;
    A *pa = &a;
    func_0024E3D0(pa, arg1);
    VObj *o = pa->p;
    VEntry *e = (VEntry *)(o->vtbl + 0x1C0);
    char *self = (char *)o + e->delta;
    func_00312370(&b, arg3);
    e->fn(self, func_00314920(get(&b)));
    func_00312318(&b, 2);
    func_0024E378(pa, 2);
}
