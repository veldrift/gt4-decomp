typedef int s32;
typedef float f32;

struct mTransition;

struct mColorTransition {
    s32 m0;
    s32 m4;
    char pad8[0x18];
    union { s32 i; f32 f; } m20;
    f32 f24;
};

extern "C" void *mTransition__structor_0(struct mTransition *arg0);
extern "C" void func_00203148(void *arg0, float fparg0, float fparg1, float fparg2, float fparg3);
extern char mColorTransition__vtable[];

extern "C" void mColorTransition__structor_0(struct mColorTransition *arg0) {
    mTransition__structor_0((struct mTransition *)arg0);
    arg0->m20.i = 0;
    arg0->m4 = (s32)mColorTransition__vtable;
    f32 z = arg0->m20.f;
    func_00203148((void *)((char *)arg0 + 0x28), z, z, z, 1.0f);
    arg0->f24 = 0x1.111110p-4f;
}
