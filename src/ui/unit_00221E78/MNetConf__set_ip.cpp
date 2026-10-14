typedef int s32;
typedef unsigned char u8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    s32 pad[3];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, const char *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct A {
    VObj *p;
    s32 pad[3];
};

struct B {
    s32 v[4];
};

extern char D_006980F0[];

extern "C" void func_00221AD0(void *arg0, int arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" Str *func_00314920(s32 arg0);

extern "C" void MNetConf__set_ip(void *arg0, void *arg1, s32 count, void *name) {
    if (count > 0) {
        A a;
        B b;
        A *pa = &a;
        B *pb;
        func_00221B28(pa, arg1);
        pb = &b;
        func_00312370(pb, name);
        s32 h = pb->v[0];
        VObj *o = pa->p;
        VEntry *e = (VEntry *)(o->vtbl + 0x208);
        char *self = (char *)o + e->delta;
        Str *s = func_00314920(h);
        const char *v = D_006980F0;
        s32 len = ((Rep *)s->p)[-1].len;
        if (len != 0) {
            s->p[len] = 0;
            v = s->p;
        }
        e->fn(self, v);
        func_00312318(pb, 2);
        func_00221AD0(pa, 2);
    }
}
