
typedef int s32;
typedef float f32;
struct func_004212F0_arg0;
struct func_004212F0_arg1
{
  f32 a;
  f32 b;
};
struct func_00421598_arg1
{
  f32 unk0;
  f32 unk4;
  f32 unk8;
  f32 unkC;
};
extern void func_004212F0(struct func_004212F0_arg0 *arg0, struct func_004212F0_arg1 *arg1, f32 fparg0);
extern s32 func_00421598(struct func_004212F0_arg0 *arg0, struct func_00421598_arg1 *arg1, f32 fparg0, f32 fparg1)
{
  struct func_004212F0_arg1 t;
  f32 k = fparg1;
  f32 a;
  f32 b;
  func_004212F0(arg0, &t, fparg0);
  a = t.a;
  b = t.b;
  arg1->unk8 = k;
  arg1->unk0 = a;
  arg1->unkC = k;
  arg1->unk4 = b;
  return 1;
}
