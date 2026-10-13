typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern Pair D_0064C480[5];

extern "C" void func_0054D848(s32 arg0) {
    s32 i;
    Pair *p = D_0064C480;
    for (i = 0; i < 5; i++, p++) {
        if (arg0 == p->a) {
            p->b = 0;
            p->a = 0;
            return;
        }
    }
}
