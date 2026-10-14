/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Cam {
    char pad[0x18];
    s32 f18;
};

struct Src {
    char pad[0x10];
    s32 a10;
    s32 a14;
    s32 a18;
    s32 a1c;
    s32 a20;
    float a24;
};

struct Obj {
    char pad[0xEC];
    Src *p;
};

struct Loc {
    s32 w0;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 a10;
    s32 a14;
    s32 a18;
    s32 a1c;
    s32 a20;
    float a24;
    char pad[0x18];
};

struct Tmp {
    s32 x;
    char pad[0xC];
};

struct Vec {
    char pad[4];
    s32 b;
    s32 e;
    s32 c;
};

struct Glob {
    char pad[0x39E2C];
    s32 f;
};

extern char D_006925F8[];
extern char D_00692600[];
extern char D_00692608[];
extern Glob *D_00622F4C;

extern "C" Cam *func_00197788(s32 arg0) throw();
extern "C" s32 func_00197808(s32 arg0) throw() __attribute__((const));
extern "C" void func_001CAB90(void *);
extern "C" const char *func_001CAD08(const char *, const char *, s32, s32, s32);
extern "C" void func_001CAF30(void *, void *, void *, s32);
extern "C" void func_00331608(void *);
extern "C" void func_00331930(void *, s32, s32);
extern "C" void func_00331B40(void *);
extern "C" s32 func_00333550(void);
extern "C" void func_00335558(void *);
extern "C" void free(s32) throw();
extern "C" void *func_005CDBE8(void *, void *);

static inline void copy(Loc *d, Src *s) {
    func_005CDBE8(d, s);
    d->a10 = s->a10;
    d->a14 = s->a14;
    d->a18 = s->a18;
    d->a1c = s->a1c;
    d->a20 = s->a20;
    d->a24 = s->a24;
}

extern "C" const char *func_0019B3A0(Obj *arg0, s32 arg1) {
    Loc loc;
    Vec v;
    Tmp t;
    Cam *cam;
    Src *s;
    Src *a1;
    s32 g;
    const char *r;
    if (arg0->p == 0) {
        return D_006925F8;
    }
    loc.a4 = 0;
    loc.a8 = 0;
    loc.aC = 0;
    loc.a10 = 0;
    loc.a14 = 0;
    loc.a18 = 1;
    loc.a1c = 1;
    loc.a20 = 3;
    loc.a24 = 1.0f;
    cam = func_00197788(arg1);
    if (cam != 0) {
        s = (Src *)((char *)cam + 0x1C);
        func_00335558(cam);
        copy(&loc, s);
    } else {
        s = arg0->p;
        copy(&loc, s);
    }
    func_00331608(&loc);
    if (cam != 0 && cam->f18 != 0) {
        func_00331B40(&loc);
        func_00331930(&loc, 0, 0);
    }
    if (func_00333550() == 0) {
        func_001CAB90(&loc);
    }
    g = func_00197808(D_00622F4C->f);
    v.b = 0;
    v.e = 0;
    v.c = 0;
    func_001CAF30(&v, &loc, cam, g);
    r = func_001CAD08(D_00692600, D_00692608, 10000, v.b, v.e - v.b);
    if (v.b != 0) {
        free(v.b);
    }
    t.x = loc.a4;
    if (t.x != 0) free(t.x);
    return r;
}
