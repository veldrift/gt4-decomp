/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S8 { s32 a; s32 b; };

extern Rep D_00659FA8;
extern char D_0069A478[];

extern "C" const char *func_005223B8(void *, S8);
extern "C" int func_00523190(const char *, void *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_0069A478;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" Str *func_00271E70(Str *ret, Str *key) {
    S8 t;
    char buf[0x30];
    if (func_00523190(c_str(key), &t) == 0) {
        const char *name = func_005223B8(buf, t);
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = (char *)(r + 1);
                r->ref++;
            }
            ret->p = p;
        }
        func_005C2630(ret, 0, -1, name, func_0057F260(name));
        return ret;
    }
    {
        Rep *r = &D_00659FA8;
        char *p;
        if (r->sel != 0) {
            p = func_005C2560(r);
        } else {
            p = (char *)(r + 1);
            r->ref++;
        }
        ret->p = p;
    }
    return ret;
}
