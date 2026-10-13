
typedef int s32;
typedef unsigned char u8;
typedef float f32;
struct func_00369510_p10
{
  char pad0[0x237];
  u8 b237;
};
struct func_00369510_arg0
{
  char pad0[0x10];
  struct func_00369510_p10 *p10;
};
struct func_00369510_ent
{
  char pad0[0x20];
  f32 f20;
  char pad24[0x40];
  f32 f64;
};
extern s32 func_00359538(void *);
extern f32 func_00369510(struct func_00369510_arg0 *arg0, f32 *arg1)
{
  char *v = ((char *) arg0) + 0x104;
  f32 new_var;
  if (((new_var = *((f32 *) (v + 0x48C))) == 0.0f) || ((*((f32 *) (v + 0x514))) == 0.0f))
  {
    *arg1 = 1.0f;
    return 0.0f;
  }
  s32 r = func_00359538(arg0);
  u8 *pb = (u8 *) (r + arg0->p10->b237);
  u8 t0 = pb[0xC];
  u8 t1 = ((u8 *) (t0 + r))[0x24];
  struct func_00369510_ent *v1 = (struct func_00369510_ent *) ((((char *) arg0) + (t0 * 0xEC)) + 0x164);
  struct func_00369510_ent *v0 = (struct func_00369510_ent *) ((((char *) arg0) + (t1 * 0xEC)) + 0x164);
  f32 f = (v1->f20 + v0->f20) * 0x1.0p-1f;
  if (f < 0.0f)
  {
    f = -f;
  }
  f32 b;
  f32 prod = f * 0x1.89374Cp-7f;
  f32 c = 0x1.333332p-2f;
  f32 s = v1->f64 + v0->f64;
  f32 t = prod + c;
  f32 k = s * 0x1.999998p-3f;
  *arg1 = t;
  return k;
}
