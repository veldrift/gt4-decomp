typedef short s16;
typedef int s32;
typedef float f32;

struct Obj00370D70;

struct VEnt00195270 {
    s16 delta;
    s16 pad;
    void *(*fn)(void *);
};

struct ObjA00195270 {
    char pad0[0x64];
    VEnt00195270 *vtbl;
};

extern "C" int func_00192E20(s32);
extern "C" void func_00370DB0(void *p, s32 v);
extern "C" f32 func_00370D70(Obj00370D70 *p);

extern "C" f32 func_00195270(s32 arg0, s32 arg1, s32 arg2)
{
    ObjA00195270 *o;
    VEnt00195270 *e;
    char *p;

    o = (ObjA00195270 *)func_00192E20(arg1);
    e = (VEnt00195270 *)((char *)o->vtbl + 0x4B0);
    p = (char *)e->fn((char *)o + e->delta) + 0xE28;
    func_00370DB0(p, arg2);
    return func_00370D70((Obj00370D70 *)p);
}
