
typedef int s32;
extern s32 func_0056FC78(s32, s32, s32, s32);
extern s32 func_0056FD70(s32, s32, s32, s32);
extern s32 func_0056FE28(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4)
{
  s32 r = func_0056FC78(arg0, arg1, (s32) arg2, arg3);
  if (r < 0)
  {
    return r;
  }
  r = func_0056FD70(arg0, arg1, *arg2, arg4);
  s32 neg = r < 0;
  if ((r < 0) == 0)
  {
    r = 0;
  }
  return r;
}
