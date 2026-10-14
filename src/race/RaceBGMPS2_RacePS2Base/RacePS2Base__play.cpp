typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern char D_00622F4C[];

struct Obj {
    char pad0[0x64];
    char *tbl;
    char pad1[0xCE0 - 0x68];
    s32 unkCE0;
};

struct VEntry_v {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct VEntry_r {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" void func_004365B8(s32 *arg0);
extern "C" void func_00387EF0(Obj *self, int arg1, int arg2);
extern "C" void func_0010AF10(s32 arg0);
extern "C" s32 func_0054C6E8(s32 v);

extern "C" void RacePS2Base__play(void *arg0, s32 arg1) {
    Obj *self = (Obj *)arg0;
    s32 s0;
    s32 r;

    func_004365B8((s32 *)(*(s32 *)D_00622F4C + 0x38CB0));
    do {
        func_00387EF0(self, arg1, 1);
        func_0010AF10(1);
        do {
            s0 = func_0054C6E8(0);
            {
                VEntry_v *e = (VEntry_v *)(self->tbl + 0x10);
                e->fn((char *)self + e->delta);
            }
            {
                VEntry_v *e = (VEntry_v *)(self->tbl + 0x20);
                e->fn((char *)self + e->delta);
            }
            func_0054C6E8(s0);
            {
                VEntry_r *e = (VEntry_r *)(self->tbl + 0x2D8);
                r = e->fn((char *)self + e->delta);
            }
        } while (r != 1);
    } while (self->unkCE0 == 5);
    {
        VEntry_v *e = (VEntry_v *)(self->tbl + 0x2C0);
        e->fn((char *)self + e->delta);
    }
}
