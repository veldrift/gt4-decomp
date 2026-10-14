/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Out {
    s32 w0;
    s32 w4;
    f32 f8;
};

struct Ctx {
    char pad0[4];
    char *p4;
    char pad8[4];
    char *pC;
    s32 p10;
    s32 p14;
    Out *p18;
};

struct VA {
    s16 delta;
    s16 index;
    void *(*fn)(void *self, s32 a1);
};

struct VB {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct VC {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a1, s32 a2);
};

extern "C" void func_00377098(Ctx *arg0)
{
    VA *ea = (VA *)(*(char **)arg0->p4 + 0xD8);
    char *r = (char *)ea->fn(arg0->p4 + ea->delta, arg0->p10);
    if (r != arg0->pC) {
        VB *eb = (VB *)(*(char **)r + 0xC8);
        f32 f = eb->fn(r + eb->delta);
        VC *ec = (VC *)(*(char **)arg0->pC + 0x140);
        ec->fn(arg0->pC + ec->delta, arg0->p14, 0);
        *(s32 *)(arg0->pC + 0xE8) = 3;
        char *record = arg0->p4 + arg0->p10 * 0x19C;
        *(char **)(record + 0x13C) = arg0->pC;
        arg0->p18->w0 = 1;
        arg0->p18->f8 = f;
    }
}
