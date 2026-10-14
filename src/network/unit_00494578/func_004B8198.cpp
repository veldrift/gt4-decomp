/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Group { int x; char pad[0x418]; };
struct S { int x,n; char pad[0x18]; Group groups[2]; int active; int spare; int busy; };
extern "C" void func_004B80A0(S*) throw();
extern "C" void func_004B5628(S*,int) throw();
extern "C" void *func_004B5CC0(void*) throw();
extern "C" void func_004B5E00(S*,void*,unsigned short*,int) throw();
extern "C" unsigned short *func_004B9678(unsigned short*,const unsigned char*);
extern "C" void *func_005C15B0(int);
extern "C" void func_005C1628(void*) throw();
extern "C" void func_004B8198(S *s,const unsigned char *src) {
 if(src && !s->busy) {
  func_004B80A0(s);
  int active=s->active;
  Group *g=&s->groups[1-active];
  if(g->x) { func_004B5628(s,active); g->x=0; }
  unsigned short *p=(unsigned short*)func_005C15B0(s->n*2);
  func_004B9678(p,src);
  g->x=0;
  func_004B5E00(s,func_004B5CC0(s),p,0);
  func_005C1628(p);
 }
}
