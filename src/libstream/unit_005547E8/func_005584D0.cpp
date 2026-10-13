
typedef float f32;
typedef int s32;
struct Obj
{
  char pad0[0x768];
  s32 unk768;
  char pad1[0x78C - 0x76C];
  s32 unk78C;
  f32 unk790;
  f32 unk794;
  s32 unk798;
};
extern void func_00551400(int arg0, int arg1);
extern void func_005783A0(s32 arg0);
extern void func_00578500(s32 arg0);
extern void func_005584D0(struct Obj *arg0)
{
  f32 k = 0x1.FFF8p+13f;
  s32 v;
  struct Obj *new_var;
 do { goto top; } while (0);
  do
  {
    v = (s32) ((arg0->unk790 * arg0->unk794) * k);
    new_var = &(*arg0);
    func_00551400((*new_var).unk768, v & 0x3FFF);
    top:
    if (arg0->unk78C == 0)
    {
      break;
    }

    func_00578500(arg0->unk798);
  }
  while (arg0->unk78C != 0);
  func_005783A0(arg0->unk798);
}
