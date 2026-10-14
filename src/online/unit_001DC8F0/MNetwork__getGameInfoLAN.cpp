typedef int s32;
typedef unsigned int u32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };



extern StringRep D_00659FA8;
extern char D_00645570[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F55E0(void *, s32, s32);
extern "C" char *func_004F5668(void *, s32);
extern "C" s32 func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" s32 func_004F73D8(void *, s32);
extern "C" s32 func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" Handle *func_00314B20(Handle *, String *);
extern "C" void func_00312318(Handle *, int);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void release(String *s) {
    StringRep *q = (StringRep *)(s->dat - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}




static inline void *get(Handle *h) { return h->p; }
static inline void add_str(void *a, String *s, Handle *v, Handle *tmp) {
    func_00314B20(v, s);
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_00312318(v, 2);
    release(s);
}
static inline void add_int(void *a, Handle *v, Handle *tmp) {
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_002FC870(v, 2);
}


extern "C" void func_001DC650(void *, void *) throw();
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" long func_001F6A50(void *, int, char *, int *, int *, char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MNetwork__getGameInfoLAN(void **dst, void *ctx, int n, void *args) {
    if (n > 0) {
        Handle h;
        Handle input;
        char buf[128];
        int num1, num2;
        char buf2[128];
        Handle list;
        Handle tmp;
        Handle v;
        String s;
        Handle v2;
        Handle v3;
        Handle v4;
        String s2;
        func_001DC650(&h, ctx);
        Handle *pi = &input;
        func_002FC8C8(pi, args);
        void *pctx = h.p;
        int id = func_002FE250(pi->p);
        if (func_001F6A50(pctx, id, buf, &num1, &num2, buf2)) {
            Handle *pl = &list;
            func_002EFBF0(pl);
            Handle *pt = &tmp;
            { void *p = get(pl); String *ps = &s; construct(ps, buf); add_str(p, ps, &v, pt); }
            { void *p = get(pl); func_002FE278(&v2, num1); add_int(p, &v2, pt); }
            { void *p = get(pl); func_002FE278(&v3, num2); add_int(p, &v3, pt); }
            { void *p = get(pl); String *ps = &s2; construct(ps, buf2); add_str(p, ps, &v4, pt); }
            if ((void *)dst != (void *)pl) {
                void *p = pl->p;
                if (p) func_003285A8(p);
                if (*dst) func_003285F8(*dst);
                *dst = p;
            }
            func_002ED5C0(pl, 2);
        }
        func_002FC870(pi, 2);
        func_001DC5F8(&h, 2);
    }
}
