/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[0x10]; Node *next; int id; };
struct Owner { int count; char pad[0x10]; Node *head; };
struct Arg { char pad[0x60]; Owner *owner; };
struct Elem { char pad[8]; int acc; char gap[0x17c]; };
struct Self { char pad[0x2f0]; Elem elems[6]; };
extern "C" void RaceEntryBase__sortByRank(Owner*);
extern "C" signed char func_00447598(char *,int);
extern "C" void func_003EEFE0(char *self,Arg *arg) {
 Owner *owner=arg->owner;
 int n=owner->count;
 RaceEntryBase__sortByRank(owner);
 Node *node=owner->head;
 for(int i=0;i<n;i++) {
  int id=node->id;
  int value=func_00447598(self,i);
  int off=id*0x188+0x2f0;
  Elem *e=(Elem *)(self+off);
  e->acc+=value;
  node=node->next;
 }
}
