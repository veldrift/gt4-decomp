
struct S8
{
  int w[2];
};
struct func_0045C718_rec
{
  char pad0[0x18];
  struct S8 dst;
  struct S8 src;
  char tail[0x1C];
};
extern void func_0045C718(char *a0)
{
  struct func_0045C718_rec *new_var;
  struct func_0045C718_rec *r = (struct func_0045C718_rec *) a0;
  int i;
  for (i = 7; i >= 0; i--)
  {
 new_var = r; do { } while (0);
    new_var->dst = new_var->src;
    r++;
  }

}
