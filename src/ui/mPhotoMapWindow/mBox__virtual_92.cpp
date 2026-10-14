typedef int s32;
typedef short s16;
typedef void (*VFn2074E8)(void *, void *);
struct VEntry2074E8 { s16 delta; s16 index; VFn2074E8 fn; };
struct Obj2074E8 { char p0[4]; char *vt; };
extern char D_0082AA00[];
extern "C" void mSceneViewFace__virtual_92(void *p, void *n);
extern "C" s32 func_00265DC8(void *arg0);
extern "C" s32 func_00206850(void *arg0);
extern "C" void func_00231C10(void *arg0);
extern "C" void func_00231C48(void *arg0);
extern "C" void func_00576788(void *arg0);
extern "C" void func_005767C0(void *arg0);

extern "C" void mBox__virtual_92(void *arg0, void *arg1) {
    struct VEntry2074E8 *e;

    mSceneViewFace__virtual_92(arg0, arg1);
    if (func_00265DC8(arg0) != 0) {
        func_00576788(D_0082AA00);
        if (func_00206850(arg0) != 0) {
            func_00231C10(arg1);
        }
        e = (struct VEntry2074E8 *)(((struct Obj2074E8 *)arg0)->vt + 0x308);
        e->fn((char *)arg0 + e->delta, arg1);
        if (func_00206850(arg0) != 0) {
            func_00231C48(arg1);
        }
        func_005767C0(D_0082AA00);
    }
}
