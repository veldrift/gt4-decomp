typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[12];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct VEntryInt {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct Hnd {
    char pad[0x10];
    char *p10;
};

extern char D_006901F0[];

extern "C" void func_0015F388(void *arg0, int arg1);
extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_004307D0(void *arg0, const char *arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006901F0;
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_00161A50(void *arg0, void *arg1, s32 arg2, Obj **arg3) {
    if (arg2 >= 3) {
        union {
            s32 buf[4];
            Str s;
        } u;
        func_0015F3E0(u.buf, arg1);
        s32 h = u.buf[0];
        char *base = ((Hnd *)h)->p10;
        {
            Obj *o1 = arg3[0];
            VEntryInt *e1 = (VEntryInt *)(o1->vtbl + 0x58);
            s32 n = e1->fn((char *)o1 + e1->delta);
            base += n * 0x68;
        }
        func_0015F388(u.buf, 2);
        char *tgt = base + 0xD8;
        {
            Obj *o2 = arg3[1];
            VEntry *e = (VEntry *)(o2->vtbl + 0x18);
            e->fn(&u.s, (char *)o2 + e->delta);
        }
        func_004307D0(tgt, c_str(&u.s));
        {
            Rep *q = (Rep *)(u.s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            Obj *o3 = arg3[2];
            VEntryInt *e3 = (VEntryInt *)(o3->vtbl + 0x58);
            *(s32 *)(tgt + 0x48) = e3->fn((char *)o3 + e3->delta);
        }
    }
}
