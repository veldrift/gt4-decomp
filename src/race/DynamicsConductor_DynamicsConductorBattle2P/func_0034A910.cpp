
typedef int s32;
typedef unsigned char u8;
struct Obj0034A910
{
  char pad[0x730];
  u8 unk730;
};
struct Ret0034A910
{
  char pad0;
  u8 unk1;
};
extern void *func_00359538(struct Obj0034A910 *arg0);
extern s32 func_0034A910(struct Obj0034A910 *arg0, s32 *arg1, s32 *arg2)
{
  s32 ret = 0;
  u8 temp = arg0->unk730;
  if (temp != 0)
  {
    s32 *out = arg2;
    *arg1 = temp;
    u8 v = ((struct Ret0034A910 *) func_00359538(arg0))->unk1;
 do { } while (0);
    ret = 1;
    *out = v;
  }
  return ret;
}
