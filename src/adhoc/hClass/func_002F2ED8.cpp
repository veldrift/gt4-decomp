/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEnt { s16 delta; s16 pad; void (*fn)(void *, void *, void *, void *); };
struct VT { char pad[0xA8]; VEnt e; };
struct Obj { char pad[4]; VT *vt; };
struct T { Obj *o; char pad[0xC]; };
struct H { void *p; char pad[0xC]; };
struct Self { void *f0; };

extern char D_0083CE50[];
extern char D_0083CE48[];

extern "C" void func_002F2A08(void *, int) throw();
extern "C" void func_002F2A60(void *, void *) throw();
extern "C" void func_003069F8(void *, void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030B410(void *, void *, void *);
extern "C" void func_0030BB18(void *);

extern "C" void func_002F2ED8(Self *self, void *arg1, void *arg2, void *arg3) {
    H h;
    T t;
    func_002F2A60(&h, arg1);
    T *pt = &t;
    func_0030BB18(pt);
    func_003069F8(h.p, pt, D_0083CE50);
    if (pt->o != 0) {
        VEnt *e = &pt->o->vt->e;
        e->fn((char *)pt->o + e->delta, self, 0, arg1);
    }
    func_00309378(pt, 2);
    func_0030BB18(pt);
    func_0030B410(self->f0, pt, D_0083CE48);
    if (pt->o != 0) {
        T u;
        T *pu = &u;
        func_0030BB18(pu);
        VEnt *e = &pt->o->vt->e;
        e->fn((char *)pt->o + e->delta, pu, arg2, arg3);
        func_00309378(pu, 2);
    }
    func_00309378(pt, 2);
    func_002F2A08(&h, 2);
}
