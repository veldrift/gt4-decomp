
typedef int s32;
typedef float f32;
struct Obj
{
  char pad0[0xFC];
  f32 unkFC;
  char pad1[0x24];
  s32 unk124;
};
extern f32 func_002B1FE0(struct Obj *arg0);
extern f32 func_002B1F90(struct Obj *arg0);
extern f32 func_002B2340(struct Obj *arg0);
extern f32 func_002B2390(struct Obj *arg0);
extern f32 func_002D4980(struct Obj *arg0);
extern f32 func_002B2400(struct Obj *arg0)
{
  f32 temp_f0;
  f32 temp_f2;
  f32 temp_f20;
  f32 temp_f21;
  f32 temp_f22;
  f32 scale;
  f32 var_f0;
  f32 var_f1;
  var_f0 = 0.0f;
  if (arg0->unk124 >= 0)
  {
    temp_f20 = func_002B1FE0(arg0);
    temp_f21 = func_002B1F90(arg0);
    var_f0 = func_002D4980(arg0);
    temp_f22 = temp_f20 + var_f0;
    temp_f0 = func_002B2390(arg0);
    var_f1 = 0.0f;
    if (temp_f21 <= temp_f0)
    {
      scale = func_002B2340(arg0);
      temp_f2 = arg0->unkFC;
      var_f1 = (temp_f21 * temp_f2) - ((temp_f22 * ((f32) arg0->unk124)) + (scale * temp_f2));
      if (var_f1 > 0.0f)
      {
        var_f1 = 0.0f;
      }
      if ((var_f1 + temp_f0) < temp_f21)
      {
        var_f1 = temp_f21 - temp_f0;
      }
    }
    var_f0 = var_f1;
  }
  return var_f0;
}
