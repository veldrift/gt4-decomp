
typedef int s32;
struct func_004B5C58_arg0
{
  char pad0[0x858];
  s32 unk858;
};
struct func_004B5C58_temp
{
  char pad0[0x234];
  s32 unk234;
};
extern s32 func_004B5C58(void *arg0, char *arg1)
{
  char *temp;
  s32 count;
  s32 i;
  char *p;
  temp = ((char *) arg0) + ((1 - ((struct func_004B5C58_arg0 *) arg0)->unk858) * 0x41C);
  count = ((struct func_004B5C58_temp *) temp)->unk234;
  i = 0;
  if (count > 0)
  {
    s32 limit = count;
    if (1)
    {
      p = temp + 0x238;
      do
      {
        s32 v = i;
        count = p == arg1;
        i++;
        if (count)
        {
          return v;
        }
        p += 8;
      }
      while (i < limit);
    }
  }
  return -1;
}
