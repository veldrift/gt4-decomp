struct B { char data[8]; };
struct E { int x, first, second; char pad[20]; B value; int extra; char tail[24]; };
struct O { void *handle; char pad[128]; E *entries; };
extern "C" int func_00529320(void *, void *, B *, int *);
extern "C" int func_00525FE0(O *, int);
extern "C" void func_00527710(O *, int, int, int);
extern "C" void func_00529650(void *, int);
extern "C" void func_00525D20(O *self, int n, int arg) {
 B b; int extra;
 if (func_00529320(self->handle, (void *)n, &b, &extra) == 0) {
  int index = func_00525FE0(self,n);
  if (index == 0xfffe) { func_00529650(self->handle,n); }
  else {
   E *e = (E *)(index * 68 + (int)self->entries);
   int first = e->first;
   if (n == first) {
    e->value=b;
    int second = *(volatile int *)&e->second;
    e->extra=*(volatile int *)&extra;
    if(second != 0) { func_00529650(self->handle,n); self->entries[index].first=0; }
    else func_00527710(self,n,2,arg);
   } else if(n==e->second) {
    e->value=b; e->extra=extra;
    if(first == 0) func_00527710(self,n,2,arg);
    else { func_00529650(self->handle,n); self->entries[index].second=0; }
   }
  }
 }
}
