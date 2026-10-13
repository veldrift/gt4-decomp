
typedef int s32;
typedef unsigned short u16;
extern u16 func_00603A28(void **arg0, s32 arg1)
{
  s32 *b = (s32 *) (*arg0);
  char *p = ((char *) b) + 0x10;
  int new_var;
  s32 *e = (s32 *) (p + (arg1 * 8));
  s32 n = b[1];
  new_var = 8;
  return *((u16 *) ((p + (n * new_var)) + (*e)));
}
