/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { const char *name; int x; };
struct Node;
extern Entry D_006238C0[];
extern Node *D_00623998;
extern void *D_0062399C;
extern int D_006239A0;
extern char D_00846640[];
extern char D_006AB3D8[], D_006AB3E0[], D_006AB3E8[];
extern "C" void *func_004624F0();
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" int func_004AE230(void *,const char *,int);
extern "C" void func_00460488(Node *,void (*)(void *),int);
extern "C" unsigned long func_00485BA0(const char *);
extern "C" int func_004859F0(void *,unsigned long,long);
extern "C" void *func_004AC430(int,int);
extern "C" void func_0045FDF8() {
 char path[0x70];
 struct Loader { char pad[0x10]; Node *node; char pad14[0xc]; } loader;
 if(D_00623998==0) {
  unsigned i=0;
  func_0057DA20(path,D_006AB3D8,D_006AB3E0,func_004624F0(),D_006AB3E8);
  func_004AE230(&loader,path,1);
  Node *node=loader.node;
  func_00460488(node,0,0);
  D_00623998=node;
  for(;i<27;i++) {
   unsigned long key=func_00485BA0(D_006238C0[i].name);
   func_004859F0(D_00846640,key,(long)i);
  }
  void **buffer=&D_0062399C;
  *buffer=func_004AC430(0x2000,1);
  D_006239A0=0;
 }
}
