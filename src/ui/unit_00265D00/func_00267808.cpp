/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self {
    char pad0[0x68];
    s32 h68;
    char pad6C[0x98 - 0x6C];
    s32 flags98;
};

extern char D_00830A18[];
extern "C" void func_0024B218(void *, s32 *);
extern "C" void func_0024B230(void *, void *);
extern "C" void func_0024B248(void *, s32);
extern "C" void func_0024BDB8(void *);
extern "C" void func_002679B0(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_005769F0(s32);
extern "C" void func_00576A28(s32);

static inline void assign(s32 *dst, s32 *src) {
    if (dst != src) {
        s32 v = *src;
        if (v != 0) {
            func_003285A8(v);
        }
        if (*dst != 0) {
            func_003285F8(*dst);
        }
        *dst = v;
    }
}

static inline bool empty(s32 *p) { return *p == 0; }

extern "C" void *func_00267808(void *out, Self *self) {
    s32 hv[4];
    s32 tmp[4];
    s32 zero;
    if (self->flags98 & 0x200000) {
        func_002679B0(self);
    }
    zero = 0;
    func_0024B218(hv, &zero);
    func_005769F0((s32)D_00830A18);
    s32 *src = &self->h68;
    if (empty(src)) {
        func_0024BDB8(tmp);
        assign(hv, tmp);
        func_0024B248(tmp, 2);
    } else {
        assign(hv, src);
    }
    func_00576A28((s32)D_00830A18);
    func_0024B230(out, hv);
    func_0024B248(hv, 2);
    return out;
}
