struct Node { Node *next, *prev; char pad[8]; int id, value, state; char rest[20]; };
struct Global {Node *head; char neg[128]; char pos[128]; char all[128];};
extern Global *D_0064B70C;
extern "C" int func_00538988(int);
extern "C" int func_00538B08(void *, int);
extern "C" int func_00543008(int, int, int);
extern "C" int func_00543180(int, char *);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_00542EB8(int id, int value, int arg2) {
 struct {Node *p; char pad[12];} temp;
 if (func_00538988(id) == 0) {
  func_00538B08(&temp,48);
  Node *n = temp.p;
  func_005A48D8(n,0,48);
  if (!n) return -1;
  n->id=id; n->value=value; n->state=0;
  Global *g = D_0064B70C;
  Node *h=g->head;
  if (h) {Node *p=h->next; n->next=p; p->prev=n;}
  else g->head=n;
  Global *g2=D_0064B70C;
  g2->head->next=n;
  n->prev=g2->head;
  if (id == -1) func_00543180(-1,g2->all);
  else if (id < 0) func_00543180(id,g2->neg);
  else func_00543180(id,g2->pos);
  if (value != 0xFFFF && id != -1) func_00543008(id,0xFFFF,arg2);
 }
 return 0;
}
