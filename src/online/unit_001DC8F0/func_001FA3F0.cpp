typedef int s32;
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };

struct Info {
    char pad0[0x18];
    s32 id;
    char name[0x20];
    s32 type;
    char kind;
    char msg[0x3F];
};

struct Self {
    char pad0[0x18];
    s32 x18;
    char pad1C[0x1BC - 0x1C];
    void *obj;
    s32 out;
    char x1C4[4];
    s32 x1C8;
    s32 x1CC;
    char name[0x20];
};

extern "C" void func_0030BB18(void *);


extern "C" void func_0030BB18(void *);
struct Value { s32 p; Value() { func_0030BB18(this); } };
struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, s32 *);
};

struct VEntryStr {
    short delta;
    short index;
    void (*fn)(s32 *, void *);
};

extern StringRep D_00659FA8;
extern char D_00645570[];
extern char D_006959D8[];
extern char D_00696D38[];
extern char D_00696D28[];
extern char D_00695AE0[];
extern char D_00696D48[];
extern char D_00696D50[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F7AE8(void *, Info *);
extern "C" void func_001F84E0(Self *, char *);
extern "C" s32 func_001F2BB0(Self *, const char *, s32);
extern "C" int func_005A5A30(char *, u32, const char *, ...);
struct Pipe; extern "C" void func_00227110(void *, char *);
extern "C" void func_00227128(void *, int);
extern "C" void func_00227BE0(s32, const char *);
extern "C" void *func_002FA120(void *);
extern "C" void func_002F9B38(void *, int);
extern "C" s32 HSymID__GetID(String *);
extern "C" void func_003069F8(void *, void *, s32 *);
extern "C" void func_0030BB18(void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_002117A0(void *);
extern "C" s32 func_00213158(s32);
extern "C" s32 func_00251BD8(s32, s32);
extern "C" void func_00211408(void *, int);
extern "C" void func_0022AC98(void *, const s32 *);
extern "C" void func_0022ACC8(void *, int);
extern "C" void func_00314B20(s32 *, String *);
extern "C" void func_00312318(void *, int);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);


static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    func_005C2630(str, 0, (u32)-1, s, func_0057F260(s));
}

static inline void release(String *s) {
    StringRep *q = (StringRep *)(s->dat - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(String *s) {
    char *p = s->dat;
    int len = ((int *)p)[-4];
    if (len == 0) return D_006959D8;
    p[len] = 0;
    return s->dat;
}

static inline void set_arg(s32 *dst, s32 *src) {
    if (dst != src) {
        s32 newVal = *src;
        if (newVal != 0)
            func_003285A8(newVal);
        s32 oldVal = *dst;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *dst = newVal;
    }
}

extern "C" void func_001FA3F0(Self *self) {
    Info info;
    char buf[0x80];
    s32 h[4];
    s32 ret[4];
    String s;

    if (!func_004F7AE8(D_00645570, &info))
        return;
    if (info.type == 1) {
        if (self->x1C8 == 0 && self->x1CC < 0) {
            self->x1CC = info.id;
            func_001F84E0(self, info.name);
        }
        if (self->x1CC == info.id) {
            func_005A5A30(buf, 0x80, D_00696D28, self->name, info.msg);
            s32 *t = h;
            func_00227110(t, self->x1C4);
            func_00227BE0(t[0], buf);
            func_00227128(t, 2);
        } else if (self->obj) {
            s32 *ph = h;
            func_002FA120(ph);
            s32 *pv = ret;
            construct(&s, D_00696D38);
            *pv = HSymID__GetID(&s);
            func_003069F8(self->obj, ph, pv);
            release(&s);
            if (*ph) {
                func_0030BB18(pv);
                Value args[2];
                s32 tmp[4];
                String s2;
                s32 v;
                s32 *pa = &args[0].p;
                s32 *pt = tmp;
                func_002117A0(pt);
                s32 x = func_00251BD8(func_00213158(*pt), 0);
                func_00211408(pt, 2);
                v = x;
                func_0022AC98(pt, &v);
                set_arg(pa, pt);
                func_0022ACC8(pt, 2);
                s32 *pa1 = &args[1].p;
                construct(&s2, info.msg);
                func_00314B20(pt, &s2);
                set_arg(pa1, pt);
                func_00312318(pt, 2);
                release(&s2);
                {
                    VObj *o = (VObj *)*ph;
                    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
                    e->fn((char *)o + e->delta, pv, 2, pa);
                }
                {
                    VObj *o = (VObj *)*pv;
                    VEntryStr *e = (VEntryStr *)(o->vtbl + 0x18);
                    e->fn(pt, (char *)o + e->delta);
                    func_001F2BB0(self, c_str((String *)pt), info.id);
                    release((String *)pt);
                }
                {
                    s32 *q = &args[2].p;
                    while (pa != q) {
                        --q;
                        func_00309378(q, 2);
                    }
                }
                func_00309378(pv, 2);
            }
            func_002F9B38(ph, 2);
        }
    } else if (self->x18 || __builtin_expect(info.type, 0)) {
        switch (info.kind) {
        case '0':
        case '1':
        case '2':
            func_005A5A30(buf, 0x80, D_00695AE0, info.name, info.msg);
            break;
        case '3':
            func_005A5A30(buf, 0x80, D_00696D48, D_00696D50, info.msg);
            break;
        }
        func_00227BE0(self->out, buf);
    }
}
