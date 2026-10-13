typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry_CC8 {
    s16 delta;
    s16 index;
    char *(*fn)(void *self, s32 a1);
};

struct Obj_CC8 {
    char pad0[0x64];
    char *vt;
    char pad1[0xCC8 - 0x68];
    u32 fCC8;
};

extern char *D_00622F4C;

extern "C" s32 func_003743E8(char *arg0, s32 arg1);
extern "C" s32 func_00388D80(s32 a);

extern "C" void func_00388CC8(Obj_CC8 *self) {
    VEntry_CC8 *e = (VEntry_CC8 *)(self->vt + 0xD0);
    char *r = e->fn((char *)self + e->delta, 0);
    if (self->fCC8 < 2) {
        *(s32 *)(D_00622F4C + 0x39DA4) = func_00388D80(func_003743E8(r, 0));
    }
}
