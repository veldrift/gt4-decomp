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
};

struct A {
    void *p;
    s32 pad[3];
};

struct B {
    s32 v[4];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern char D_006980F0[];

extern "C" void func_00221AD0(void *arg0, int arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);

static inline s32 get(B *b) {
    return b->v[0];
}

extern "C" void MNetConf__set_netmask(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        A a;
        B b;
        A *pa;
        VObj *o;
        VEntry *e;
        char *self;
        s32 bv;
        Str *s;
        const char *v;
        s32 len;

        func_00221B28(&a, arg1);
        func_00312370(&b, arg3);
        pa = &a;
        bv = get(&b);
        o = (VObj *)pa->p;
        e = (VEntry *)(o->vtbl + 0x218);
        self = (char *)o + e->delta;
        s = (Str *)func_00314920((u8 *)bv);
        v = D_006980F0;
        len = ((Rep *)s->p)[-1].len;
        if (len != 0) {
            s->p[len] = 0;
            v = s->p;
        }
        e->fn(self, (void *)v);
        func_00312318(&b, 2);
        func_00221AD0(&a, 2);
    }
}
