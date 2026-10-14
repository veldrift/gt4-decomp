struct Config { char name[0x6C]; unsigned int key; unsigned short a,b,c,d; };
extern Config D_0064A178;
extern int D_0064A1F4,D_0064A1F8,D_0064A2EC,D_0064A2E8,D_00853538;
extern char D_00853550[];
extern char D_006C1350[],D_006C1358[],D_006C1360[],D_006C1368[],D_006C13A0[],D_006C13C0[];
extern "C" int func_0050FD78();
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" int func_00538BF8(int *,unsigned long);
extern "C" int func_00539788(void *);
extern "C" int func_0050EF88(int,int);
extern "C" int func_0050F678(int,int);
extern "C" void func_0057D9C0(const char *,...);
extern "C" int func_00506668() {
 char *name=D_0064A178.name;
 func_0050FD78();
 if(!func_0057F238(name,D_006C1350)) D_0064A1F8=1;
 else if(!func_0057F238(name,D_006C1358)) {D_0064A1F4=1; D_0064A1F8=2;}
 else if(!func_0057F238(name,D_006C1360)) {D_0064A1F4=1; D_0064A1F8=3;}
 else if(!func_0057F238(name,D_006C1368)) {D_0064A1F4=1; D_0064A1F8=4;}
 unsigned int key=D_0064A178.key;
 D_0064A2EC=0;
 if(key) {
  if(func_00538BF8(&D_0064A2E8,(unsigned long)key)) return -4;
  if(func_00539788(D_00853550)) return -11;
 }
 if(func_0050EF88(D_0064A178.a,D_0064A178.b)) {
  func_0057D9C0(D_006C13A0); return -13;
 }
 int r=func_0050F678(D_0064A178.c,D_0064A178.d);
 if(r) { func_0057D9C0(D_006C13C0); return -13; }
 D_00853538=1;
 return r;
}
