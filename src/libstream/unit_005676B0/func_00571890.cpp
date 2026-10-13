
typedef int s32;
typedef unsigned int u32;
extern s32 func_00571890(char *arg0, u32 arg1, s32 *arg2)
{
  char *a0;
  u32 a1;
  s32 var_a3;
  s32 var_v0;
  s32 n;
  s32 done;
  a0 = arg0;
  a1 = arg1;
  var_a3 = 0;
  var_v0 = 2;
  if (arg2 != 0)
  {
    *arg2 = 0;
    if (a0 != 0)
    {
      if (a1 >= 0x40U)
      {
        goto test;
        do
        {
 do { n = (*((s32 *) (a0 + 0x8))) + 0x40; a1 -= n; a0 += n; } while (0);
          done = a1 < 0x40U;
          var_a3 += n;
          if (done)
          {
            break;
          }
          test:
          if (0 != (*((s32 *) a0)))
          {
            break;
          }

        }
        while ((*((s32 *) (a0 + 0x3C))) == 0);
      }
      *arg2 = var_a3;
      var_v0 = 0;
    }
  }
  return var_v0;
}
