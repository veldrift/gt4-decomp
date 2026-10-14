typedef int s32;

struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct Tgt { char pad0[4]; char *vtbl; };
struct B16 {
    s32 w[4];
    B16(s32, s32, s32) __asm__("func_00129830");
};
struct A0 { char pad[0x80]; Tgt *f80; };

extern s32 D_00618710;
extern char D_0068DD20[];
extern char D_0068DD30[];

extern "C" s32 func_003A1E10(const char *);

extern "C" void func_0011FF98(A0 *arg0, Tgt **arg1) {
    Tgt *t = *arg1;
    arg0->f80 = t;
    if (t != 0) {
        s32 a = func_003A1E10(D_0068DD20);
        B16 buf(D_00618710, a, func_003A1E10(D_0068DD30));
        Tgt *u = *arg1;
        VEntry *e = (VEntry *)(u->vtbl + 0x300);
        e->fn((char *)u + e->delta, &buf);
    }
}
