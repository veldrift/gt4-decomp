/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct V {
    char pad0[4];
    char *b4;
    char *e8;
    char padC[4];
    s32 f10, f14, f18, f1C, f20;
    f32 f24;
};

struct It { u32 p; };

struct Obj {
    char pad[0xC4];
    V v;
};

extern "C" s32 func_00575D00(void);
extern "C" void *func_005A47D4(void *, const void *, unsigned) throw();
extern "C" void func_005CD968(void *);
extern "C" void func_005CD9E8(void *, char *, u32, char *);

static inline void body(Obj *self, u32 n) {
    struct { u32 p; char c; } L;
    V *v = &self->v;
    v->f24 = 0x1.555554p+0f;
    s32 oldheight = v->f14;
    s32 total = v->f10 * v->f20;
    total = total * oldheight;
    s32 t2 = v->f18 * v->f1C;
    total = total * t2;
    v->f10 = 0x500;
    v->f14 = 0x3c0;
    v->f20 = 3;
    v->f18 = 1;
    v->f1C = 1;
    u32 avail = func_00575D00();
    if (total != n) {
        func_005CD968(v);
        if (!(avail < n)) {
            L.c = 0;
            char *e = v->e8;
            char *b = v->b4;
            u32 used = e - b;
            if (used > n) {
                char *mid = v->b4 + n;
                func_005A47D4((void *)mid, (void *)e, 0);
                L.p = (u32)mid;
                v->e8 = v->e8 - (e - mid);
            } else {
                func_005CD9E8(v, e, n - used, &L.c);
            }
        }
    }
}

extern "C" void func_0019AEF0(Obj *self) { body(self, 0x384000); }
