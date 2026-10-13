
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
void func_004C9090(u16 *arg0, u8 *arg1, s32 arg2)
{
  u16 *var_a0;
  u8 *var_a1;
  s32 var_a2;
  unsigned short c;
  s32 hi;
  s32 lo;
  var_a0 = arg0;
  var_a1 = arg1;
  var_a2 = arg2;
  while ((var_a2 > 0) && ((c = *var_a1) != 0))
  {
    if (((s32) (c << 24)) >= 0)
    {
      hi = 0;
      lo = *var_a1;
      var_a1 += 1;
    }
    else
    {
      hi = *var_a1;
      var_a1 += 1;
      lo = *var_a1;
      var_a1 += 1;
      hi <<= 8;
    }
    var_a2 -= 1;
    *var_a0 = (u16) (hi | lo);
    var_a0 += 1;
  }

  *var_a0 = 0;
}
