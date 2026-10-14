/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void *func_0048F628(void *, const void *, int *, int *);
extern "C" void free(int) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

struct Str { char *p; char pad[12]; };

static inline char *copy(Rep *d) {
    char *p;
    if (d->sel != 0) {
        p = func_005C2560(d);
    } else {
        s32 r = d->ref;
        p = (char *)d + 0x10;
        d->ref = r + 1;
    }
    return p;
}

extern "C" char **func_0029DF18(char **arg0, s32 arg1, const void *arg2) {
    int allocated;
    int size;
    const char *r = (const char *)func_0048F628((char *)arg1 + 0x10, arg2, &allocated, &size);
    if (r != 0) {
        Str h; Str *ps = &h;
        s32 n = size;
        ps->p = copy(&D_00659FA8);
        func_005C2630(ps, 0, (u32)-1, r, n);
        if (allocated != 0) {
            free((int)r);
        }
        char *p = copy((Rep *)(ps->p - 0x10));
        *arg0 = p;
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    } else {
        *arg0 = copy(&D_00659FA8);
    }
    return arg0;
}
