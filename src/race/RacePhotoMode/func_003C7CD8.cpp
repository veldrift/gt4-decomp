typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" void func_003BBBC0(void *self, u32 innerColor, u32 outerColor, f32 innerRadius, f32 outerRadius);
extern "C" s32 func_004AA0D0(void *, void *, f32, f32, f32, f32, f32);

extern "C" void func_003C7CD8(void *arg0, void *arg1) {
    f32 prod;

    prod = *(f32 *)((char *)arg0 + 0x1E66C) * 0x1.666666p-1f * 0x1.47AE14p-7f;
    func_003BBBC0(arg1, (u32)func_004AA0D0(arg0, arg1, 0.0f, 0.0f, 0.0f, prod, 255.0f), 0, 420.0f, 200.0f);
}
