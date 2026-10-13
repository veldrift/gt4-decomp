
typedef int s32;
typedef signed char s8;
extern s32 func_005391C0(s8 *arg0, s32 arg1)
{
  s32 var_v0;
  var_v0 = 2;
  if (arg0 != 0)
  {
    arg0[0] = arg1 >> 24;
    arg0 = arg0 + 1;
    arg0[0] = arg1 >> 16;
    arg0 = arg0 + 1;
    arg0[0] = arg1 >> 8;
    arg0[1] = arg1;
    var_v0 = 0;
  }
  return var_v0;
}
