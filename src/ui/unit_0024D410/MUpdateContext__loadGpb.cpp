typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Obj {
    s32 pad0;
    char *vt;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, u8 *, u8 *);
};

extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" void func_0024E3D0(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);
extern "C" void func_0024E378(void *arg0, s32 arg1);
extern "C" u8 *func_00314920(u8 *arg0);

extern "C" void MUpdateContext__loadGpb(void *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *pb1;
    s32 *pb2;
    Obj *o;
    VEntry *e;
    u8 *r1;
    if (arg2 >= 0x2) {
        func_00312370(buf0, arg3);
        pb1 = buf1;
        func_00312370(pb1, (char *)arg3 + 0x4);
        pb2 = buf2;
        func_0024E3D0(pb2, arg1);
        o = (Obj *)pb2[0];
        e = (VEntry *)(o->vt + 0x1B0);
        o = (Obj *)((char *)o + e->delta);
        r1 = func_00314920((u8 *)buf0[0]);
        e->fn((void *)o, r1, func_00314920((u8 *)pb1[0]));
        func_0024E378(pb2, 0x2);
        func_00312318(pb1, 0x2);
        func_00312318(buf0, 0x2);
    }
}
