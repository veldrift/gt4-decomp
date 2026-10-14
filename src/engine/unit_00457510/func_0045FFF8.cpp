/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { int a; char *name; char pad[16]; };
struct Pair { Item *a; unsigned b; Pair(Item *x,unsigned y):a(x),b(y){} Pair(const Pair &o):a(o.a),b(o.b){} };
extern "C" Pair func_0045FF50(int) throw();
extern "C" void func_0045FFC0(float) throw();
extern "C" void func_00460168();
extern "C" unsigned func_00461F88();
extern "C" char *func_004624F0();
extern "C" void func_00547860(char *,int,int *);
extern "C" int func_0057DA20(int,int,...);
extern "C" char *func_005A5DC8(void *,void *);
extern char D_006AB3F0[],D_006AB3E0[],D_006AB3F8[];
extern int *D_0062399C;
extern int D_006239A0;
extern "C" void func_0045FFF8(int index,unsigned select,int mode,float volume) {
 func_00460168();
 Pair pair = func_0045FF50(index);
 char path[0x70];
 if (pair.b != 0) {
  int special=0;
  if (select == ~0U) select=func_00461F88()%pair.b;
  if (select&0x1000) {special=1;select&=~0x1000;}
  Item *item=pair.a+select%pair.b;
  func_0057DA20((int)path,(int)D_006AB3F0,D_006AB3E0,func_004624F0());
  if(special) func_005A5DC8(path,D_006AB3F8);
  func_005A5DC8(path,item->name);
  int *p=D_0062399C;
  if(p) {*p=0;D_006239A0=0;}
  func_0045FFC0(volume);
  func_00547860(path,mode,D_0062399C);
 }
}
