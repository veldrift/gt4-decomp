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
extern "C" s32 func_004F41E0(void *);
extern "C" char *func_004F4428(void *, s32);
extern "C" s32 func_001F1368(void *) throw();
extern void mUpdateContext__Sync(int);
extern "C" s32 func_004F73D8(void *, s32);
extern "C" s32 func_001F1368(void *) throw();
extern void mUpdateContext__Sync(int);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" Handle *func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" void func_00314B20(Handle *, String *);
extern "C" void func_00312318(Handle *, int);

static inline char *clone(StringRep *r) { return func_005C2560(r); }

static inline char *grab(StringRep *r) {
    if (r->selfish) return clone(r);
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





extern "C" int func_004F2010(void *, int);
extern "C" char *func_004F22E0(void *, int);
extern "C" Handle *func_001F24D0(Handle *ret, void *ctx, int id) {
    Handle list;
    Handle row;
    Handle tmp;
    Handle v;
    Handle v2;
    String s;
    int zero;
    while (!func_004F2010(D_00645570, id)) mUpdateContext__Sync(1);
    if (!func_001F1368(ctx)) {
        zero = 0;
        func_002ED590(ret, &zero);
    } else {
    func_002EFBF0(&list);
    int count = *(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30);
    int i = 0;
    if (i < count) {
    Handle *prow = &row;
    Handle *pv = &v;
    Handle *pv2 = &v2;
    do {
        char *e = func_004F22E0(D_00645570, i++);
        Handle *ptmp = &tmp;
        func_002EFBF0(prow);
        { void *p = get(prow); func_002FE278(pv, *(int *)(e + 0x1C)); add_int(p, pv, ptmp); }
        { void *p = get(prow); construct(&s, e + 0x20); add_str(p, &s, pv2, ptmp); }
        func_002EEEB0(ptmp, list.p, prow);
        func_00309378(ptmp, 2);
        func_002ED5C0(prow, 2);
    } while (i < count);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    }
    return ret;
}
