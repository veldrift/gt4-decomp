typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern struct Pair D_00621540[];
extern char D_00621880[];
extern s32 DisplayRText__rtext_ptrs_;
extern s32 D_00621888;

extern "C" s32 func_00485FF0(s32, s32, s32);

extern "C" void func_003AE9A0(void) {
    struct Pair *p = D_00621540;
    s32 n = 0x65;
    do {
        s32 a2 = p->b;
        n--;
        s32 idx = p->a;
        p++;
        ((s32 *)DisplayRText__rtext_ptrs_)[idx] = func_00485FF0((s32)D_00621880, D_00621888, a2);
    } while (n >= 0);
}
