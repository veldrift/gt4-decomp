typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VE {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Vec4_0021A768 {
    f32 v[4];
};

extern "C" void mWidget__virtual_70(char *arg0, Obj *arg1, s32 arg2);
extern "C" void func_0021A768(Vec4_0021A768 *arg0, Vec4_0021A768 *arg1);
extern "C" void MModel__render(s32 arg0, Obj *arg1);
extern "C" f32 func_002313E0(Obj *arg0);
extern "C" f32 func_00231400(Obj *arg0);
extern "C" f32 func_00231420(Obj *arg0);
extern "C" f32 func_00231440(Obj *arg0);

extern "C" void mModelFace__virtual_70(char *arg0, Obj *arg1, s32 arg2) {
    f32 buf[4];

    mWidget__virtual_70(arg0, arg1, 0);
    if (arg2 != 0) {
        Obj *o = *(Obj **)(arg0 + 0x2BC);
        if (o != 0) {
            VE *e = (VE *)(o->vtbl + 0x48);
            if (e->fn((char *)o + e->delta) != 0) {
                char *p = arg0 + 0xA0;
                f32 r0 = func_002313E0(arg1);
                f32 r1 = func_00231400(arg1);
                f32 r2 = func_00231420(arg1);
                f32 r3 = func_00231440(arg1);
                buf[0] = r0;
                buf[1] = r1;
                buf[2] = r2;
                buf[3] = r3;
                func_0021A768((Vec4_0021A768 *)p, (Vec4_0021A768 *)buf);
                MModel__render((s32)p, arg1);
            }
        }
    }
}
