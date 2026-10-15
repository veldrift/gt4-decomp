struct N { char pad[0x150]; int size; };
struct G { char pad0[0x30]; int (*call)(int *, N *); char pad1[0x118-0x34]; N *node; };
struct R { unsigned values[100]; unsigned count; int index; char lock[4]; };
extern G *D_0064B4B4;
extern "C" int func_005312F8(int *, int) throw();
extern "C" void func_005316E8(unsigned) throw();
extern "C" int func_00531CC8(void) throw();
extern "C" R *func_00535970(int);
extern "C" void func_0053A878(void *);
extern "C" void func_00534A50(int arg0, int arg1, unsigned input, int base, N *node, int index) {
 int next;
 int value;
 R *r;
 int buf[2];
 if (D_0064B4B4 && node == D_0064B4B4->node && index < node->size && arg0 == 0) {
  buf[0] = 0x100;
  r = func_00535970(index);
  if(r) {
   next = r->index;
   value = input >> 1;
   r->values[next]=value;
   next++;
   if(r->count < 100) r->count++;
   D_0064B4B4->call(buf,node);
   if(index == buf[0] && base != 0) {
    func_00531CC8();
    func_005312F8(buf+1,index);
    if(buf[1] >= value) func_005316E8(base+value);
   }
   if(next >= 100) next=0;
   r->index = next;
   func_0053A878(r->lock);
  }
 }
}
