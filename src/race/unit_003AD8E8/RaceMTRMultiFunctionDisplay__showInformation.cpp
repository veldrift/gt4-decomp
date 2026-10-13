typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern "C" s32 func_003A1E10(s32 arg0);
extern "C" void func_003A9850(void *o, f32 t);
extern "C" void func_003A98E8(void *self, f32 a0, f32 a1, f32 a2, f32 a3);
extern "C" s32 D_00621530[];

struct Self_003ADCE8 {
    char pad0[0x18];
    u32 mode;
    s32 slot;
    char pad1[0x51 - 0x20];
    u8 flag;
};

extern "C" void func_003ADCE8(struct Self_003ADCE8 *self, u32 arg1, f32 fparg0) {
    s32 lt = arg1 < 4;
    f32 keep = fparg0;
    if (arg1 != self->mode) {
        if (lt == 0) {
            arg1 = 0;
        }
        s32 x = 0;
        self->mode = arg1;
        s32 t = D_00621530[arg1];
        if (t != 0) {
            x = func_003A1E10(t);
        }
        self->slot = x;
        if (self->flag != 0) {
            return func_003A9850((char *)self + 0x20, 0.2f);
        }
        func_003A98E8((char *)self + 0x20, 0.0f, keep, 0.2f, 0.5f);
    }
}
