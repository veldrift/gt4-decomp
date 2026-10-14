typedef int s32;
extern char D_006AB1F0[];
extern "C" int func_0045B368(void *s, s32 a, void *b, char *c);
extern "C" void func_0045A4A0(void *self, void *stream);
extern "C" void func_0045A7D8(void *a, void *b);

struct Blk { char pad[0x13C]; float tab[12]; };

static inline void row(float *p, float a, float b) {
    p[0] = a;
    p[1] = b;
    p[2] = a;
}

extern "C" s32 func_0045A3F8(void *arg0, s32 arg1, void *arg2) {
    s32 out[2];
    Blk blk;
    Blk *pb;
    s32 i;
    float *t;
    func_0045B368(out, arg1, arg0, D_006AB1F0);
    if (out[1] < 0) {
        return 0;
    }
    pb = &blk;
    t = pb->tab;
    i = 3;
    do {
        i -= 1;
        row(t, 0.0f, 1.0f);
        t += 3;
    } while (i != -1);
    func_0045A4A0(pb, arg0);
    func_0045A7D8(arg2, pb);
    return 1;
}
