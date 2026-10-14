/* compiler: ee-gcc2.96-no-strict-aliasing */
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

struct Obj {
    char pad0[0xF0];
    char *str;
    char pad1[0x114 - 0xF4];
    s32 h;
};

extern Rep D_00659FA8;
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void * func_005C2630(void *, s32, s32, const char *, s32);
struct R { s32 m0; R(const R &o); };
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" R func_00218A60(s32);
extern "C" void func_0021D828(void *, s32) throw();
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_0021FC78(Obj *self, s32 unused, const char *arg2) {
    char *buf[4];
    char **p = buf;
    char **dst = &self->str;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        *p = d;
    }
    func_005C2630(p, 0, -1, arg2, func_0057F260(arg2));
    if (buf != dst) {
        str_release(*dst);
        {
            Rep *r = (Rep *)(buf[0] - 0x10);
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            *dst = d;
        }
    }
    str_release(buf[0]);
    s32 *h = &self->h;
    new (buf) R(func_00218A60((s32)dst));
    if (h != (s32 *)buf) {
        s32 newVal = ((s32 *)buf)[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        s32 oldVal = *h;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *h = newVal;
    }
    func_0021D828(buf, 2);
}
