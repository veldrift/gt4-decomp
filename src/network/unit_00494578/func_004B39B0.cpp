struct VEnt { short adj; short pad; void *fn; };
struct Obj { char *vt; };
struct Self { char *vt; int f4; int f8; Obj *oC; };
typedef void (*F0)(void *);
typedef int (*F1)(void *);
typedef int (*F5)(void *, int, int, int, int);
extern "C" void func_004B36E0(int, int);
extern "C" int func_004B38A0(Self *);
extern "C" int func_004B38F8(Self *, int);
extern "C" int func_004B3938(Self *, int);
extern "C" int func_004B3C68(char *, int, int *);

static inline void call1(Obj *b) {
    VEnt *e = (VEnt *)(b->vt + 0x10);
    ((F0)e->fn)((char *)b + e->adj);
}
static inline int call2(Obj *o) {
    VEnt *e = (VEnt *)(o->vt + 0x10);
    return ((F1)e->fn)((char *)o + e->adj);
}
static inline int call3(Obj *b, int a, int c, int d, int e5) {
    VEnt *e = (VEnt *)(b->vt + 0x18);
    return ((F5)e->fn)((char *)b + e->adj, a, c, d, e5);
}

extern "C" int func_004B39B0(Self *self, int arg1) {
    int sp0 = 0;
    int s4 = func_004B3C68((char *)self + 0x10, arg1, &sp0);
    if (sp0 == 0) {
        if (func_004B38A0(self) == 0) {
            int s0 = func_004B38F8(self, arg1);
            int s2 = func_004B38F8(self, arg1 + 1) - s0;
            int s1 = self->f4;
            call1(self->oC);
            int r = call2((Obj *)self);
            call3(self->oC, s4, r, s1 + s0, s2);
        } else {
            int s0 = func_004B3938(self, arg1);
            int s2 = func_004B3938(self, arg1 + 1) - s0;
            int s1 = self->f4;
            call1(self->oC);
            int r = call2((Obj *)self);
            call3(self->oC, s4, r, s1 + s0, s2);
            func_004B36E0(s4, call2((Obj *)self));
        }
    }
    return s4;
}
