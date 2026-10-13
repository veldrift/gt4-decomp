typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

static inline void sub_call(char *s) {
    VE *e = (VE *)(*(char **)(s + 0x14) + 0x28);
    e->fn(s + e->delta);
}

static inline void sub_test(char *s) {
    if (*(u8 *)s != 0) {
        sub_call(s);
    }
}

extern "C" void func_0039FDA8(void *arg0) {
    char *self = (char *)arg0;

    sub_test(self + 0x15F8);
    sub_test(self + 0x13F0);
    sub_test(self + 0x1438);
    sub_test(self + 0x1588);
    sub_test(self + 0x14A8);

    {
        f32 v = *(f32 *)(self + 0xBC) * *(f32 *)(self + 0x14D0);
        char *a = self + 0x16A0;
        char *s0 = self + 0x16BC;
        *(f32 *)(a + 0xC) = v;
        *(f32 *)(s0 + 0xC) = v;

        sub_test(a);
        sub_test(s0);
        sub_test(self + 0x16D8);
    }

    sub_test(self + 0x1748);
    sub_test(self + 0x1518);
}
