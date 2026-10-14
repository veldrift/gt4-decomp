/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;

struct VE1D0A50 {
    short delta;
    short index;
    void *fn;
};

extern "C" void func_001CF1E8(s32 arg0, s32 *buf) throw();
extern "C" s32 func_001CF7D0(void *arg0) throw();
extern "C" void *func_00335638(void *arg0);

extern "C" void func_001D0A50(s32 arg0, s32 *arg1, s32 *arg2, void *arg3) {
    s32 buf[0x3C];
    VE1D0A50 *e = (VE1D0A50 *)(*(char **)(*(char **)arg3 + 0x64) + 0x1A8);
    ((void (*)(void *, void *, void *))e->fn)((char *)*(char **)arg3 + e->delta, buf, arg2);
    s32 v = *(s32 *)((char *)arg3 + 0x18);
    buf[0x37] = v;
    func_001CF1E8(arg0, buf);
    s32 *r = (s32 *)func_00335638(arg3);
    s32 kind = 2;
    s32 v1 = r[2];
    s32 mask = -0x40;
    s32 a2v = r[1];
    *arg1 = kind;
    *arg2 = (s32)((u32)((((v1 - a2v) + 0x47) & mask) + 0x3FF) >> 10);
    s32 q = func_001CF7D0((void *)(s32)arg0);
    s32 w = q + 0x3FF;
    q = q + 0x7FE;
    if (w < 0) {
        w = q;
    }
    *arg2 += w >> 10;
}
