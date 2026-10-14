struct Packet { char b[0x26]; };
extern int D_0064A308,D_0064A350,D_0064A30C,D_008A01A4;
struct Event;
typedef void (*Callback)(Event *, int);
extern Callback D_008A03CC;
extern char D_006C1900[],D_006C1920[];
extern Packet D_008537D0;
extern "C" void func_0050AE58();
extern "C" int func_00506650();
extern "C" int func_00507070(void(*)(),int);
extern "C" int func_0050B460(int,int,int,Packet *) throw();
extern "C" int func_0057D9C0(const char *,...);
extern "C" int func_0050BCB8(Packet *p,Callback a,int b) {
 p->b[0x14]=0;
 p->b[0x25]=0;
 int state=D_0064A308;
 if(state!=1) return -15;
 func_0057D9C0(D_006C1900);
 if(D_0064A350==state && func_00506650()!=0) {
  func_0057D9C0(D_006C1920);
  return -15;
 }
 if(!D_0064A30C) return -16;
 D_008A03CC=a;
 D_008A01A4=b;
 func_0057D9C0(D_006C1900);
 if(D_0064A350==1) {
  D_008537D0=*p;
  if(func_00507070(func_0050AE58,0)==0)
   return func_0050B460(1,0x15,0x26,p)==0 ? 0 : -5;
  return -3;
 } else {
  return func_0050B460(1,0x15,0x26,p)==0 ? 0 : -5;
 }
}
