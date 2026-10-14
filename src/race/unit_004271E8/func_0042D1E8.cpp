/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; void (*fn)(void *, int); };
struct VT { char pad[0x20]; VE e8; };
struct Sub { VT *vt; };
struct Obj { char pad[0xC]; int flag[8]; Sub *sub; };
extern "C" int func_0042CE98(int, float, float, float) throw() __attribute__((const));
extern "C" void func_004A1638(int);
extern "C" void func_004A5BF8(int, int, void *);
extern "C" void func_0042D1E8(Obj *o, int sel, float a, float b, float c) {
    unsigned idx = sel & 0xFF;
    if (idx < 8) {
        Sub *s = o->sub;
        if (s) {
            VE *e = &s->vt->e8;
            e->fn((char *)s + e->adj, idx);
        } else {
            float v[4];
            v[0] = a; v[1] = b; v[2] = c; v[3] = 0;
            int h = func_0042CE98(idx, a, b, c);
            int off = idx * 4;
            int *flags = (int *)((char *)o + 0xC);
            int *p = (int *)((char *)flags + off);
            if (*p == 0) {
                func_004A1638(h);
                *p = 1;
            }
            func_004A5BF8(h, 0xD, v);
        }
    }
}
