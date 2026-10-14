/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct V4 { s32 a[4]; };
struct Self {
    void *vt; s32 f4; char pad[0x38 - 8]; s32 f38; V4 v3C;
    f32 f4C[2]; s32 f54; s32 f58; void *f5C; void *f60; f32 f64;
};
extern char D_00659CD0[];
extern char D_006184A8[];
extern char D_006184B0[];
extern f32 D_006184B8;
extern "C" void *func_00104538(void **) throw();

extern "C" void func_00104630(Self *arg0, V4 *arg1, s32 arg2) {
    func_00104538((void **)arg0);
    arg0->vt = D_00659CD0;
    arg0->f38 = arg2;
    arg0->v3C = *arg1;
    f32 *fp = arg0->f4C;
    fp[1] = fp[0] = 0.0f;
    arg0->f5C = D_006184A8;
    arg0->f60 = D_006184B0;
    arg0->f54 = 0;
    arg0->f58 = 0;
    arg0->f64 = D_006184B8;
    arg0->f4 = 0;
}
