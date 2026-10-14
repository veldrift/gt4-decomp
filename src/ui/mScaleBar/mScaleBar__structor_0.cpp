/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct V { f32 x, y, z; };
struct O {
    char pad[4]; void *vt; char pad1[0xC0 - 8];
    s32 c0, c4; f32 c8, cc, d0, d4, d8;
    V v;
    f32 e8, ec;
    s32 f0, f4;
    char pad2[8];
    s32 f100, f104;
};
extern char mScaleBar__vtable[];
extern "C" void *mFBox__structor_0(void *);
extern "C" int func_002FA120(void *);
extern "C" void func_0025B4C8(void *, f32, f32);
extern "C" void func_00265F10(void *, s32);
extern "C" void func_00206858(void *, s32);

extern "C" void mScaleBar__structor_0(O *arg0) {
    mFBox__structor_0(arg0);
    arg0->vt = mScaleBar__vtable;
    arg0->c0 = 1;
    arg0->c4 = 0;
    f32 z = *(float *)&arg0->c4;
    arg0->c8 = z;
    arg0->cc = 100.0f;
    arg0->d0 = z;
    arg0->d4 = 100.0f;
    arg0->d8 = 1.0f;
    V *v = &arg0->v;
    v->x = z;
    v->y = z;
    v->z = z;
    arg0->e8 = z;
    arg0->ec = z;
    arg0->f0 = 0;
    arg0->f4 = 0;
    func_002FA120((char *)arg0 + 0xF8);
    func_002FA120((char *)arg0 + 0xFC);
    arg0->f100 = 0;
    arg0->f104 = 0;
    func_0025B4C8(arg0, 256.0f, 24.0f);
    func_00265F10(arg0, 1);
    return func_00206858(arg0, 0);
}
