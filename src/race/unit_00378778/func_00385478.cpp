typedef int s32;
typedef float f32;

struct Obj;
struct func_0035A540_Obj;

extern "C" f32 func_0035A540(func_0035A540_Obj *self, int k);
extern "C" void *func_0044F4C0(void);
extern "C" f32 func_0044FAB0(Obj *arg0);

extern "C" f32 func_00385478(Obj *arg0, s32 arg1)
{
  f32 var_f20;
  f32 hi;
  f32 lo;
  f32 call_res;
  f32 temp;
  f32 r;

  if (arg1 == 0)
  {
    call_res = func_0035A540((func_0035A540_Obj *) arg0, 8);
    hi = 0x1.921FB4p+0f;
    temp = -call_res;
    r = temp * 0x1.999998p-2f;
    lo = -0x1.921FB4p+0f;
    if (r < lo)
    {
      r = lo;
    }
    else if (hi < r)
    {
      r = hi;
    }
    return r;
  }

  var_f20 = 0x1.999998p-2f;
  if (func_0044F4C0() != 0)
  {
    var_f20 = func_0044FAB0((Obj *) func_0044F4C0());
  }
  return -func_0035A540((func_0035A540_Obj *) arg0, 8) * var_f20;
}
