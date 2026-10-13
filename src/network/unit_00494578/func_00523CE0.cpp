
typedef int s32;
extern s32 func_005292C0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00529228(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00523CE0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 var_v0 = 2;
  if (arg0 == 0)
  {
    return var_v0;
  }
  if (arg1 == 0)
  {
    var_v0 = func_005292C0(*arg0, arg2, arg3);
    if (var_v0 == 0)
    {
      goto zero;
    }
    return var_v0;
  }
  var_v0 = 1;
 do { if (arg1 != var_v0) { return 2; } var_v0 = func_00529228(*arg0, arg2, arg3); if (var_v0 == 0) { goto zero; } return var_v0; zero: var_v0 = 0; } while (0);
  return var_v0;
}
