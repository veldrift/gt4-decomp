/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Pool;
struct Chunk {
    Pool *owner;
    s32 f4, f8, fC;
    char *f10;
    char *f14;
    char *f18;
};
struct Pool {
    char pad0[0x38];
    Chunk *f38;
    char pad3C[4];
    s32 f40;
    u32 f44;
    char pad48[4];
    u32 f4C;
};

extern "C" u32 func_00328A38(Pool *);
extern "C" Chunk *func_00578CF0(int, int);

extern "C" void func_003288F8(Pool *p) {
    u32 n = p->f44;
    if (n != 0) {
        if (p->f4C >= n) {
            u32 t = func_00328A38(p);
            p->f44 = t;
            n = t;
        }
        if (n != 0) {
            s32 sz = p->f40;
            sz += 4;
            s32 total = sz * n;
            Chunk *c = func_00578CF0(0x10, total + 0x1C);
            char *a;
            char *last;
            char **end;
            c->owner = p;
            c->f4 = 0;
            c->f8 = 0;
            c->fC = 0;
            c->f10 = 0;
            c->f14 = 0;
            c->f18 = 0;
            if (total != 0) {
                char *first = (char *)c + 0x1C;
                c->f14 = first;
                c->f18 = first + sz * (n - 1);
                for (a = first; a < c->f18; a += sz) {
                    *(char **)a = a + sz;
                }
                *(char **)c->f18 = 0;
                c->f10 = c->f14;
            }
            p->f38 = c;
        }
    }
}
