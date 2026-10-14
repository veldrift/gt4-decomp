/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

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
    char pad[0xC];
};

struct Handle {
    s32 p;
    char pad[0xC];
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, const char *, s32);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern char D_0069DA18[];
extern "C" char *func_005C2560(Rep *r);


extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0069DA18;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FEAB0(void *arg0, int arg1) throw();
extern "C" void func_002FEB08(void *arg0) throw();
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_0030BB18(void *a0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" Str *func_00314920(s32 arg0);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);

extern "C" void IO__write(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    Handle o;
    if (arg2 == 1) {
        Handle x;
        Handle *px;
        Str s;
        Str *ps;
        Handle h;
        Handle *ph;
        char *d;
        func_002FEB08(&o);
        px = &x;
        func_00312370(px, arg3);
        ps = &s;
        {
            char *sp = func_00314920(px->p)->p;
            Rep *r = (Rep *)(sp - 0x10);
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = sp;
                r->ref++;
            }
            ps->p = d;
        }
        {
            VObj *vo = (VObj *)o.p;
            VEntry *e = (VEntry *)((char *)vo->vtbl + 0x198);
            void *self = (char *)vo + e->delta;
            const char *c = c_str(&s);
            s32 res = e->fn(self, c, str_length(&s));
            ph = &h;
            func_002FE278(ph, res);
        }
        if ((void *)arg0 != (void *)ph) {
            s32 newVal = ph->p;
            s32 oldVal;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(ph, 2);
        release(&s);
        func_00312318(px, 2);
        func_002FEAB0(&o, 2);
    } else {
        func_0030BB18(&o);
        if ((void *)arg0 != (void *)&o) {
            s32 newVal = o.p;
            s32 oldVal;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00309378(&o, 2);
    }
}
