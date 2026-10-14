typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern char D_006A2A20[];

struct Range {
    s32 v[4];
};

extern "C" Range func_0045B4D8(s32 a, s32 b);
extern "C" void GT4Model__BinStreamWriter__write8u(s32 a, s32 b);
extern "C" void func_0045B548(s32 *arg0, void *arg1);

struct VEntryPTCL {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryPTCL3 {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, void *);
};

struct NodePTCL {
    NodePTCL *next;
    struct {
        char pad[0];
    } dummy;
    char *vtbl;
};

extern "C" void func_003C2990(void *arg0, s32 arg1) {
    Range r = func_0045B4D8(arg1, (s32)D_006A2A20);
    char *self = (char *)arg0;
    char *n;
    s32 v;

    GT4Model__BinStreamWriter__write8u(arg1, 0);
    n = *(char **)(self + 4);
    if (n != 0) {
        do {
            VEntryPTCL *e8 = (VEntryPTCL *)(*(char **)(n + 4) + 0x8);
            v = e8->fn(n + e8->delta);
            GT4Model__BinStreamWriter__write8u(arg1, v + 1);
            VEntryPTCL3 *e28 = (VEntryPTCL3 *)(*(char **)(n + 4) + 0x28);
            e28->fn(n + e28->delta, arg1, arg0);
            n = *(char **)n;
        } while (n != 0);
    }
    GT4Model__BinStreamWriter__write8u(arg1, 0);
    func_0045B548(r.v, (void *)arg1);
}
