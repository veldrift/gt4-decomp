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
extern "C" s32 func_004F5D28(void *, s32);
extern "C" char *func_004F5F28(void *);
extern "C" bool func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" s32 func_004F73D8(void *, s32);
extern "C" bool func_001F1368(void *);
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


extern "C" Handle *func_001F3418(Handle *ret, void *ctx, s32 id) {
    Handle row;
    Handle tmp;
    Handle v;
    Handle v2;
    Handle v3;
    Handle v4;
    Handle v5;
    Handle v6;
    String s1;
    String s2;
    int zero;

    while (!func_004F5D28(D_00645570, id))
        mUpdateContext__Sync(1);
    bool fail = !func_001F1368(ctx);
    if (fail) {
        zero = 0;
        func_002ED590(ret, &zero);
    } else {
    char *e = func_004F5F28(D_00645570);
    func_002EFBF0(&row);
    Handle *ptmp = &tmp;
    { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x20)); add_int(p, &v, ptmp); }
    { void *p = get(&row); func_002FE278(&v2, *(s32 *)(e + 0x24)); add_int(p, &v2, ptmp); }
    { void *p = get(&row); func_002FE278(&v3, *(s32 *)(e + 0x28)); add_int(p, &v3, ptmp); }
    { void *p = get(&row); func_002FE278(&v4, *(s32 *)(e + 0x2C)); add_int(p, &v4, ptmp); }
    { void *p = get(&row); func_002FE278(&v5, *(s32 *)(e + 0x30)); add_int(p, &v5, ptmp); }
    { void *p = get(&row); construct(&s1, e + 0x34); add_str(p, &s1, &v6, ptmp); }
    { void *p = get(&row); construct(&s2, e + 0x134); add_str(p, &s2, &v, ptmp); }
    { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x174)); add_int(p, &v, ptmp); }
    { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x178)); add_int(p, &v, ptmp); }
    { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x17C)); add_int(p, &v, ptmp); }
    { void *p = get(&row); func_002FE278(&v, *(s32 *)(e + 0x180)); add_int(p, &v, ptmp); }
    func_002ED5A8(ret, &row);
    func_002ED5C0(&row, 2);
    }
    return ret;
}
