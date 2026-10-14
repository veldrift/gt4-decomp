typedef int s32;
typedef float f32;

struct Obj;
struct func_0035A540_Obj;

extern "C" f32 func_0035A540(func_0035A540_Obj *self, int k);
extern "C" f32 func_00385478(Obj *arg0, s32 arg1);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 func_0044FAB0(Obj *arg0);

extern "C" f32 func_00385548(Obj *arg0, s32 arg1)
{
  f32 var_f20;
  f32 temp;
  f32 r;
  f32 hi;
  f32 lo;

  if (arg1 == 0)
  {
    var_f20 = -func_0035A540((func_0035A540_Obj *) arg0, 9) * 0x1.999998p-2f;
    r = func_00385478(arg0, 0);
    hi = 0x1.921FB4p+0f;
    lo = -0x1.921FB4p+0f;
    if (r < lo)
    {
      var_f20 = 0.0f;
    }
    else if (hi < r)
    {
      var_f20 = 0.0f;
    }
    return var_f20;
  }

  var_f20 = 0x1.999998p-2f;
  if (DRIVERSUPPORT_NAME__GetMotoristDynamicParameter() != 0)
  {
    var_f20 = func_0044FAB0((Obj *) DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
  }
  temp = -func_0035A540((func_0035A540_Obj *) arg0, 9);
  return temp * var_f20;
}
