
typedef int s32;
typedef float f32;
extern f32 func_00228A38(void *);
extern void *func_0057B0F8(void *, f32, f32);
extern f32 func_00228A78(char *arg0)
{
  f32 v;
  char *s1;
  s1 = arg0 + 0x1C;
  v = func_00228A38(arg0);
  if ((*((f32 *) (arg0 + 0x28))) != v)
  {
    *((f32 *) (arg0 + 0x28)) = v;
  }
  else
  {
    v = v + 0x1.0624DCp-10f;
  }
  if (v > 1.0f)
  {
    v = 1.0f;
  }
  if (v < 1.0f)
  {
    s1 = arg0;
    s1 = s1 + 0x1C;
    func_0057B0F8(s1, v, 0x1.47AE14p-7f);
  }
  else
  {
    func_0057B0F8(s1, v, 0x1.333332p-2f);
  }
  return *((f32 *) (s1 + 0x8));
}
