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
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F41E0(void *);
extern "C" char *func_004F4428(void *, s32);
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


extern "C" Handle *func_001F52A8(Handle *ret, void *ctx) {
    Handle list;
    Handle row;
    Handle tmp;
    Handle v;
    Handle v2;
    String s1;
    Handle v3;
    Handle v4;
    Handle v5;
    Handle v6;
    String s2;
    String s3;
    int zero;
    int count;
    int i;

    while (!func_004F41E0(D_00645570))
        mUpdateContext__Sync(1);
    if (!func_001F1368(ctx)) {
        zero = 0;
        func_002ED590(ret, &zero);
    } else {
    func_002EFBF0(&list);
    count = *(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30);
    for (i = 0; i < count; i++) {
        char *e = func_004F4428(D_00645570, i);
        func_002EFBF0(&row);
        Handle *ptmp = &tmp;
        { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x1C)); add_int(p, &v, ptmp); }
        { void *p = get(&row); construct(&s1, e + 0x20); add_str(p, &s1, &v2, ptmp); }
        { void *p = get(&row); func_002FE278(&v3, *(s32 *)(e + 0x40)); add_int(p, &v3, ptmp); }
        { void *p = get(&row); func_002FE278(&v4, *(s32 *)(e + 0x44)); add_int(p, &v4, ptmp); }
        { void *p = get(&row); func_002FE278(&v5, *(s32 *)(e + 0x48)); add_int(p, &v5, ptmp); }
        { void *p = get(&row); construct(&s2, e + 0x4C); add_str(p, &s2, &v6, ptmp); }
        { void *p = get(&row); construct(&s3, e + 0x8C); add_str(p, &s3, &v, ptmp); }
        func_002EEEB0(ptmp, list.p, &row);
        func_00309378(ptmp, 2);
        func_002ED5C0(&row, 2);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    }
    return ret;
}
