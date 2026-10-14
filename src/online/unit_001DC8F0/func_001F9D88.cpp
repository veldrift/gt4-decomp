typedef int s32;
typedef unsigned int u32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };

struct Item {
    char name[0x64];
    s32 i64;
    s32 i68;
    s32 i6C;
    char s70[0x64];
    char sD4[0x64];
    char s138[0x20];
    const char *p158;
    u32 n15C;
};

extern StringRep D_00659FA8;
extern char D_00645570[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F75E0(void *, Item **, s32);
extern "C" s32 func_004F7558(void *, s32);
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
extern "C" void func_00314B20(Handle *, String *);
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

extern "C" Handle *func_001F9D88(Handle *ret, void *ctx, s32 id) {
    Item *item;
    Handle row;
    Handle tmp;
    Handle v;
    String s1;
    Handle v2;
    Handle v3;
    Handle v4;
    Handle v5;
    String s5;
    String s6;
    String s7;
    String s8;
    int zero;
    int zero2;

    if (!func_004F75E0(D_00645570, &item, id)) {
        while (!func_004F7558(D_00645570, id))
            mUpdateContext__Sync(1);
        if (!func_001F1368(ctx)) {
            zero = 0;
            func_002ED590(ret, &zero);
            return ret;
        }
        if (!func_004F75E0(D_00645570, &item, id)) {
            zero2 = 0;
            func_002ED590(ret, &zero2);
            return ret;
        }
    }
    Handle *prow = &row;
    func_002EFBF0(prow);
    Item *it = item;
    Handle *ptmp = &tmp;
    { void *a = get(prow); construct(&s1, it->name); add_str(a, &s1, &v, ptmp); }
    { void *a = get(prow); func_002FE278(&v2, it->i64); add_int(a, &v2, ptmp); }
    { void *a = get(prow); func_002FE278(&v3, it->i68); add_int(a, &v3, ptmp); }
    { void *a = get(prow); func_002FE278(&v4, it->i6C); add_int(a, &v4, ptmp); }
    { void *a = get(prow); construct(&s5, it->s70); add_str(a, &s5, &v5, ptmp); }
    { void *a = get(prow); construct(&s6, it->sD4); add_str(a, &s6, &v, ptmp); }
    { void *a = get(prow); construct(&s7, it->s138); add_str(a, &s7, &v, ptmp); }
    { void *a = get(prow); construct(&s8, it->p158, it->n15C); add_str(a, &s8, &v, ptmp); }
    func_002ED5A8(ret, prow);
    func_002ED5C0(prow, 2);
    return ret;
}
