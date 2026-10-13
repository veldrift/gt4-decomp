typedef int s32;
typedef float f32;

struct func_004213A0_arg0;

struct func_004213A0_arg1
{
    f32 a;
    f32 b;
};

struct func_004215E8_arg1
{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" void func_004213A0(struct func_004213A0_arg0 *arg0, struct func_004213A0_arg1 *arg1, f32 fparg0);

extern "C" s32 func_004215E8(struct func_004213A0_arg0 *arg0, struct func_004215E8_arg1 *arg1, f32 fparg0, f32 fparg1)
{
    struct func_004213A0_arg1 t;
    f32 k = fparg0;
    f32 a;
    f32 b;
    func_004213A0(arg0, &t, fparg1);
    a = t.a;
    b = t.b;
    arg1->unk0 = k;
    arg1->unk4 = k;
    arg1->unk8 = a;
    arg1->unkC = b;
    return 1;
}
