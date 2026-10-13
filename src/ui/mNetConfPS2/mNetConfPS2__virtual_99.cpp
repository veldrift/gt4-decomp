typedef int s32;
typedef short s16;

struct VE275 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

static inline s32 vc275(char *self, s32 off) {
    VE275 *e = (VE275 *)(*(char **)(self + 4) + off);
    return e->fn(self + e->delta);
}

extern "C" void func_004ED588(s32 conn, s32 user, s32 password);
extern "C" void func_004ED660(s32 conn, s32 a1, s32 a2, s32 a3, s32 a4);
extern "C" void func_004ED790(s32 conn, s32 a1, s32 a2, s32 a3, s32 a4);
extern "C" void func_004ED850(s32 conn, s32 a1);

extern "C" void func_00275B08(void *arg0) {
    char *self = (char *)arg0;
    s32 s4 = vc275(self, 0x1D0);
    s32 s3 = vc275(self, 0x190);
    s32 s5 = vc275(self, 0x1A0);
    if (s4 != 0) {
        s32 s0 = vc275(self, 0x270);
        func_004ED588(*(s32 *)(self + 0x268), vc275(self, 0x260), s0);
    } else {
        s32 s1 = vc275(self, 0x220);
        s32 s0 = vc275(self, 0x210);
        func_004ED660(*(s32 *)(self + 0x268), s3, vc275(self, 0x200), s0, s1);
    }
    s32 s0b = vc275(self, 0x240);
    func_004ED790(*(s32 *)(self + 0x268), s4, s5, vc275(self, 0x230), s0b);
    func_004ED850(*(s32 *)(self + 0x268), vc275(self, 0x280));
}
