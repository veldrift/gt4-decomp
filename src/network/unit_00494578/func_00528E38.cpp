struct Item { int flag; char pad4[0x10]; char sub14[0x18]; char sub2c[0x470]; };
struct Obj { int flag; Item *items; char pad8[4]; char subc[0x18]; char sub24[0x10]; int f34; char pad38[0x18]; unsigned count; };
struct Hooks { char pad[0x5c]; void (*a)(int); void (*b)(int); };
extern Hooks *D_0064B710;
extern "C" int func_0052D068(Obj *);
extern "C" void func_0052D4E0(void *);
extern "C" int func_00538C68(void *);
extern "C" void func_00528E38(Obj *o) {
 unsigned i = 0;
 if (o) {
  if (o->flag) func_0052D068(o);
  Hooks **h = &D_0064B710;
  if (*h) { (*h)->a(-1); (*h)->b(-1); }
  if (o->items) {
   Item *p = o->items;
   while (i < o->count) {
    if (p->flag) {
     func_0052D4E0(p->sub14);
     func_0052D4E0(p->sub2c);
     p->flag = 0;
    }
    i++;
    p++;
   }
   func_00538C68(&o->items);
  }
  if (o->f34) func_0052D4E0(o->sub24);
  func_0052D4E0(o->subc);
  func_00538C68(&o);
 }
}
