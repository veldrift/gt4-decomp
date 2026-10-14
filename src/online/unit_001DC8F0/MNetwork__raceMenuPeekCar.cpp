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
    char s64[0x64];
    s32 iC8;
    char sCC[0x20];
    char sEC[0x20];
    s32 i10C;
    char s110[0x14];
    const char *p124;
    u32 n128;
    const char *p12C;
    u32 n130;
};

extern StringRep D_00659FA8;
extern char D_00645570[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F7460(void *, Item **, s32);
extern "C" s32 func_004F73D8(void *, s32);
extern "C" s32 func_001F1368(void *) throw();
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



extern "C" void func_001DC650(Handle *, void *) throw();
extern "C" void func_001DC5F8(Handle *, int) throw();
extern "C" void func_002FC8C8(Handle *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_001F6F68(void *, int, char *, int *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MNetwork__raceMenuPeekCar(Handle *ret, void *ctx, int n, void *args) {
    Handle hctx;
    Handle arg;
    char name[0x80];
    int value;
    Handle row;
    Handle tmp;
    Handle v;
    String str;
    Handle v2;
    if (n > 0) {
        func_001DC650(&hctx, ctx);
        Handle *parg = &arg;
        func_002FC8C8(parg, args);
        void *c = get(&hctx);
        int id = func_002FE250(parg->p);
        char *pname = name;
        func_001F6F68(c, id, pname, &value);
        Handle *prow = &row;
        func_002EFBF0(prow);
        Handle *ptmp = &tmp;
        { void *a = get(prow); construct(&str, pname); add_str(a, &str, &v, ptmp); }
        { void *a = get(prow); func_002FE278(&v2, value); add_int(a, &v2, ptmp); }
        if (ret != prow) {
            void *p = prow->p;
            if (p) func_003285A8(p);
            if (ret->p) func_003285F8(ret->p);
            ret->p = p;
        }
        func_002ED5C0(prow, 2);
        func_002FC870(parg, 2);
        func_001DC5F8(&hctx, 2);
    }
}
