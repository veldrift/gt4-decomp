typedef int s32;
typedef short s16;
typedef void (*VFn2072E8)(void *, s32);
struct VEntry2072E8 { s16 delta; s16 index; VFn2072E8 fn; };
struct Obj2072E8 { char p0[4]; char *vt; };
extern char D_0082AA00[];
extern "C" void mSceneViewFace__virtual_91(void *arg0);
extern "C" s32 func_00265DC8(void *arg0);
extern "C" s32 func_00265D60(void *arg0);
extern "C" void func_00576788(void *arg0);
extern "C" void func_005767C0(void *arg0);

extern "C" void mBox__virtual_91(void *arg0, s32 arg1) {
    struct VEntry2072E8 *e;

    mSceneViewFace__virtual_91(arg0);
    if (func_00265DC8(arg0) != 0 || func_00265D60(arg0) != 0) {
        func_00576788(D_0082AA00);
        e = (struct VEntry2072E8 *)(((struct Obj2072E8 *)arg0)->vt + 0x300);
        e->fn((char *)arg0 + e->delta, arg1);
        func_005767C0(D_0082AA00);
    }
}
