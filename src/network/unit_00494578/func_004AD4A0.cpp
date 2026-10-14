/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { char p[0x80]; int state; char p84[0x1c]; int x,y; };
struct Node { Item *item; Node *prev,*next; };
struct List { Node *head,*tail; int count; };
struct Obj { char p[0x58]; List list; char sem[4]; };
extern "C" void func_00576788(Item *);
extern "C" void func_005767C0(Item *);
extern "C" void func_0057CB28(List *, Node *, void *);
extern "C" void func_00574EE8(void *);
static inline bool less(int x,int y,Item *b) {
    if (x < b->x) return true;
    if (b->x < x) return false;
    return y < b->y;
}
extern "C" void func_004AD4A0(Obj *o,Item *item) {
    List *l = &o->list;
    Node *n = l->head;
    int x = item->x, y = item->y;
    Item *b; int bx, by;
    while (n && (b=n->item, bx=b->x, by=b->y, x >= bx && (bx < x || y >= by))) n = n->next;
    func_00576788(item);
    item->state = 2;
    func_0057CB28(l,n,(char *)item+0x3c);
    func_005767C0(item);
    func_00574EE8(o->sem);
}
