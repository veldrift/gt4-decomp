/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

struct Out {
    s32 id;
    s32 mB0;
    s32 hit;
    f32 pos;
};

struct Ctx {
    Obj *p0;
    char *p4;
    char *p8;
    char pad0C[4];
    s32 p10;
    void *p14;
    s32 *p18;
    void *p1C;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f);
};

extern "C" void func_003FD980(Obj *o, void *s, Out *out);
extern "C" s32 func_003FD940(s32 hit, f32 pos);
extern "C" f32 func_00578598(void *a);

extern "C" bool func_00376D90(Ctx *arg0)
{
    Out out;
    s32 s3;
    s32 hit;
    s32 r;
    char *t2;

    s3 = arg0->p0->unk80;
    func_003FD980(arg0->p0, arg0->p14, &out);
    if (out.hit == 0) {
        return 0;
    }
    hit = out.hit;
    r = func_003FD940(hit, out.pos);
    f32 f = func_00578598(arg0->p1C);
    t2 = arg0->p8;
    VEntry *e = (VEntry *)(*(char **)t2 + 0x138);
    e->fn(t2 + e->delta, arg0->p14, s3, out.mB0, hit, r, f);
    char *slot=arg0->p4;
    slot+=arg0->p10*0x19C;
    *(char **)(slot+0x13C)=arg0->p8;
    *arg0->p18 = 1;
    return 1;
}
