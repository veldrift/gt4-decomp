struct Block { int v[25]; };
struct Item { int a,b; Block text; void *data; unsigned size; };
struct Request { char pad[8]; volatile int kind; int a,b; Block text; short size; char data[1]; };
struct Packed { int value; } __attribute__((packed));
extern Item *D_0064A218;
extern Item **D_0064A274;
extern unsigned D_0064A27C;
extern void (*D_0064A2C4)(int, Item **, int);
extern char D_006C13E0[], D_006C1438[];
extern "C" int func_0050A0E8(Item **, int);
extern "C" int func_0050A268(Item **, int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" void func_005A2E98(const char *, int, const char *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A6AB0(void *, void *, int) throw();
extern "C" void func_00506A98(int, int, int, Request *r) {
 struct { int token; Item *item; } local; *(volatile int *)&local.token=0;
 switch(r->kind) {
 case 1:
  if(D_0064A2C4) {
   *(Packed *)&local.token=*((Packed *)((char *)r+2));
   if(!D_0064A218 && func_0050A0E8(&D_0064A218,r->size)==-4) {
    D_0064A2C4(4,0,local.token); return;
   }
   int a=r->a; int b=r->b;
   D_0064A218->a=a;
   D_0064A218->b=b;
   D_0064A218->text=r->text;
   func_005A4724(D_0064A218->data,r->data,D_0064A218->size);
   local.item=D_0064A218;
   D_0064A2C4(0,&local.item,local.token);
  }
  return;
 case 2:
  for(unsigned i=0;i<D_0064A27C;i++) {
   if(func_0057F238((char *)&D_0064A274[i]->text,(char *)&r->text)==0) return;
  }
  if(D_0064A27C>=256) func_005A2E98(D_006C13E0,0x297,D_006C1438);
  if(D_0064A27C<256) {
   if(func_0050A268(D_0064A274+D_0064A27C,r->size)!=-4) {
    func_005A6AB0(&D_0064A274[D_0064A27C]->text,&r->text,100);
    func_005A6AB0(D_0064A274[D_0064A27C]->data,r->data,r->size);
    D_0064A274[D_0064A27C]->size=r->size;
    D_0064A27C++;
   }
  }
  break;
 }
}
