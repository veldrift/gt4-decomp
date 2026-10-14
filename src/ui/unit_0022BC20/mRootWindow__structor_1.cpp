/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };
struct Vec { int pad; char *start, *finish, *eos; };

extern char mRootWindow__vtable[];
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003286B8(void *);
extern "C" void func_005DB760(void *);
extern "C" void *func_005DBBC0(void);
extern "C" void *HSymID__tf(void);
extern "C" void mFBox__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    func_005DB760(m);
    void *p0 = *(void **)(m + 0x4);
    void *r3 = func_005DBBC0();
    func_00326798(p0, 0xc, 0x4, *(const char **)(r3));
}

extern "C" void mRootWindow__structor_1(char *arg0, s32 arg1) {
    char *p, *e, *s;
    s32 n;
    char *sp[4];
    *(char **)(arg0 + 4) = mRootWindow__vtable;
    str_release((Str *)(arg0 + 0xE0));
    str_release((Str *)(arg0 + 0xDC));
    Vec *v = (Vec *)(arg0 + 0xCC);
    s = v->start;
    e = v->finish;
    p = s;
    sp[0] = s;
    if (s != e) {
        do {
            p += 4;
        } while (p != e);
    }
    n = (v->eos - s) >> 2;
    if (s != 0) func_00326798(s, n << 2, 4, *(const char **)HSymID__tf());
    if (*(void **)(arg0 + 0xC8) != 0) func_003286B8(*(void **)(arg0 + 0xC8));
    member_0(arg0 + 0xC0);
    mFBox__structor_1(arg0, 0);
    if (arg1 & 1) func_00326798(arg0, 0xF0, 4, "RefCounter");
}
