/* compiler: ee-gcc2.96-nogcse */
struct Obj { char pad[0x94]; unsigned short count; unsigned short items[512]; };
extern "C" int func_00528790(void *,Obj *) throw();
extern "C" int func_00528820(void *p,Obj *o,unsigned short value) {
 unsigned short n=o->count;
 unsigned i=0;
 if (n) {
  unsigned limit=n;
  unsigned short *data=o->items;
  do {
   if (*data++==value) return 0;
   i++;
  } while(i<limit);
 }
 if(o->count<512) {
  o->items[n]=value;
  o->count++;
 } else {
  return func_00528790(p,o);
 }
 return 0;
}
