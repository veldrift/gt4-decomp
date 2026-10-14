/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Mgr { char pad[0x24]; f32 f24; f32 f28; };
struct Ent { f32 x; f32 y; f32 z; f32 w; };
struct Self { char pad[0x2F4]; f32 f2F4; };
extern s32 PDISTD__global_font_manager;
extern Ent D_00618770[];
extern char D_0068DDC0[];
extern char D_0068DDC8[];
extern char D_0068DDD0[];
extern "C" void func_00490290(void *, void *);
extern "C" void func_00490518(void *, f32, f32, f32, f32);
extern "C" void func_00490890(void *, f32, f32);
extern "C" void func_00490950(void *, const char *, ...);

extern "C" void func_00122A50(Self *arg0, s32 arg1, f32 fparg0) {
    fparg0 += 12.5f;
    Ent *e = &D_00618770[arg1];
    f32 v = arg0->f2F4;
    v -= fparg0;
    func_00490290((void *)PDISTD__global_font_manager, D_0068DDC0);
    Mgr *m = (Mgr *)PDISTD__global_font_manager;
    m->f28 = 2.0f;
    m->f24 = 2.0f;
    func_00490890((void *)PDISTD__global_font_manager, 64.0f, v);
    func_00490518((void *)PDISTD__global_font_manager, e->x, e->y, e->z, 0x1.999998p-2f);
    func_00490950((void *)PDISTD__global_font_manager, D_0068DDC8, D_0068DDD0[arg1]);
}
