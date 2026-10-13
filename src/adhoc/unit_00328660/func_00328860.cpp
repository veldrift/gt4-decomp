
struct Node
{
  char pad0[8];
  struct Node *next;
};
struct Obj
{
  char pad0[0x30];
  struct Node *head;
};
extern void func_00328A00(struct Obj *arg0);
extern void func_00574DA8(void *arg0, int arg1);
extern void free(int arg0);
extern void func_005C1628(int arg0);
extern void func_00328860(struct Obj *arg0, int arg1)
{
  struct Node *cur = arg0->head;
  struct Node *new_var;
  if (cur != 0)
  {
    do
    {
      new_var = cur;
      cur = new_var->next;
      if (new_var != 0)
      {
        free((int) new_var);
      }
      cur = cur;
    }
    while (cur != 0);
  }
  func_00328A00(arg0);
  func_00574DA8(arg0, 2);
  if (arg1 & 1)
  {
    return func_005C1628((int) arg0);
  }
}
