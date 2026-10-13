
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern s32 func_00539068(u8 *arg0, u32 arg1)
{
  s32 var_v0;
  u32 temp_v1;
  u32 temp_a3;
  u32 temp_a2;
  temp_v1 = arg1 >> 8;
  temp_a3 = arg1 >> 24;
  temp_v1 = arg1 >> 16;
  temp_a2 = temp_v1;
  var_v0 = 2;
 do { if (arg0 != 0) { *arg0 = (u8) arg1; arg0++; *arg0 = (u8) (arg1 >> 8); arg0++; *arg0 = (u8) temp_a2; var_v0 = 0; arg0[1] = (u8) temp_a3; } } while (0);
  return var_v0;
}
