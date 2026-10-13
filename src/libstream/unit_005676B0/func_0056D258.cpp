
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int s128;
typedef unsigned int u128;
void *memcpy(void *, const void *, unsigned int);
struct func_0056D258_arg7
{
  s16 w0;
  s16 w2;
  s16 w4;
};
extern f32 func_0056D258(f32 *arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5, s32 *arg6, struct func_0056D258_arg7 *arg7)
{
  f32 scale = 0x1.0000000000000p-6f;
  f32 val = (f32) arg3;
  s32 n;
  s32 *src;
  s32 *dst;
  scale = val * scale;
  if (scale > 0x1.FAE146p-1f)
  {
    scale = 0x1.FAE146p-1f;
  }
  if (arg5 > 0)
  {
    n = arg5;
    src = ((s32 *) arg0) - arg1;
    dst = (s32 *) arg0;
    do
    {
      val = (f32) (*src);
      src++;
      n -= 1;
      val = val * scale;
      *dst = (s32) val;
      dst++;
    }
    while (n != 0);
  }
  *arg6 = arg1;
  arg7->w2 = arg3;
  arg7->w4 = (arg7->w0 = 0);
  return val;
}
