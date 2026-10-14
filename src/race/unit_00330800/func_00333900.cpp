/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Blob32 { s32 w[8]; };
struct VEntry1 { short delta; short index; char *(*fn)(void *, s32); };
struct VEntry2 { short delta; short index; Blob32 *(*fn)(void *); };

struct G {
    char pad0[0x64];
    char *vtbl;
    char pad68[0xCF5C - 0x68];
    f32 fCF5C;
    char padCF60[0xE320 - 0xCF60];
    s32 uE320;
    char padE324[0xE330 - 0xE324];
    s32 uE330;
};

struct Obj {
    G *g;
    char pad4[0x40];
    char sub[0x100];
    Blob32 b144;
    s32 u164;
    s32 u168;
};

extern "C" void func_00332530(void *);
extern "C" void func_00334E38(void *);

extern "C" void func_00333900(Obj *arg0) {
    arg0->g->fCF5C = 0x1.111110p-6f;
    arg0->g->uE330 = 0x100;
    arg0->g->uE320 = 0;
    func_00332530(&arg0->sub[0]);
    if (arg0->u164 == 0) {
        G *g = arg0->g;
        VEntry1 *e = (VEntry1 *)(g->vtbl + 0xD0);
        char *r = e->fn((char *)g + e->delta, 0);
        VEntry2 *e2 = (VEntry2 *)(*(char **)r + 0x1C0);
        Blob32 *p = e2->fn(r + e2->delta);
        arg0->b144 = *p;
    }
    if (arg0->u168 == 0) {
        func_00334E38(arg0);
    }
}
