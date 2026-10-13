/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[0x3444];
    s32 idx;   /* 0x3444 */
};

struct Tab {
    u32 n;       /* 0x0 */
    s32 pad4;    /* 0x4 */
    Obj **base;  /* 0x8 */
};

struct Outer {
    char pad0[0x60];
    Tab *tab;    /* 0x60 */
};

extern "C" void RaceOrganization__defaultPosition(Outer *arg0) {
    Tab *t = arg0->tab;
    u32 i = 0;

    if (t->n != 0) {
        do {
            ((Obj **)t->base)[i]->idx = (s32)i;
            i++;
        } while (i < t->n);
    }
}
