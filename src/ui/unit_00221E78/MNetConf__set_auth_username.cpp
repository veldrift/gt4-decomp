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

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, const char *);
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

extern "C" void MNetConf__set_auth_username(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];
        s32 *p_s2;
        func_00221B28(buf0, arg1);
        p_s2 = buf1;
        func_00312370(p_s2, arg3);
        VObj *o = (VObj *)buf0[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x268);
        char *self = (char *)o + e->delta;
        Str *s = (Str *)func_00314920((u8 *)p_s2[0]);
        const char *v = D_006980F0;
        s32 len = ((Rep *)s->p)[-1].len;
        if (len != 0) {
            s->p[len] = 0;
            v = s->p;
        }
        e->fn(self, v);
        func_00312318(p_s2, 2);
        func_00221AD0(buf0, 2);
    }
}
