/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Iter { void *node; char pad[12]; };
struct Tree { int allocator; void *header; Iter find(void *) __asm__("func_005F1CA0"); };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_00326F68(void *self,void *key) {
 func_00576788(self);
 Tree *t = (Tree *)((char *)self+0x30);
 Iter it = t->find(key);
 Iter end;
 end.node = t->header;
 int found = it.node != end.node;
 func_005767C0(self);
 return found;
}
