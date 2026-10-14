struct Blob { char bytes[0x66]; };
struct Frame { int id; int pad; char account[0x100]; char password[0x40]; char fmt[0x68]; };
extern int D_0064A308,D_0064A350,D_0064A30C,D_0064A354;
extern int D_008A03C8,D_008A01A0;
extern Blob D_00853768;
extern char D_006C1850[],D_006C1888[],D_006C1890[],D_006C18B0[];
extern "C" void func_0050AC90();
extern "C" int func_00506650(void);
extern "C" long func_00506DA8(void *,void (*)(),int) throw();
extern "C" int func_0050B460(int,int,int,void *) throw();
extern "C" int func_0057D9C0(const char *,...);
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" void func_005A6AB0(void *,const void *,int) throw();
static inline void copy(Blob *dst,const Blob *src) { *dst=*src; }
extern "C" long func_0050BA18(Blob *arg0,int arg1,int arg2) {
 Frame sp;
 arg0->bytes[0x14]=0;
 arg0->bytes[0x25]=0;
 arg0->bytes[0x45]=0;
 arg0->bytes[0x65]=0;
 int a0 = D_0064A308;
 if (a0 != 1) return -15;
 if (D_0064A350 == a0 && func_00506650() != 0) {
  func_0057D9C0(D_006C1850);
  return -15;
 }
 if (D_0064A30C == 0) return -16;
 D_008A03C8=arg1;
 D_008A01A0=arg2;
 int result;
 if (D_0064A350 == 1) {
  sp.id=D_0064A354;
  func_0057DA20(sp.fmt,D_006C1888,0);
  char *account=sp.account;
  func_005A6AB0(account,arg0->bytes+0x26,0x100);
  func_005A6AB0(sp.password,arg0->bytes+0x46,0x40);
  func_0057D9C0(D_006C1890);
  func_0057D9C0(D_006C18B0,account);
  copy(&D_00853768,arg0);
  long r=func_00506DA8(&sp,func_0050AC90,0);
  result= r==0 ? 0:-5;
 } else {
  int r=func_0050B460(1,7,0x66,arg0);
  result= r==0 ? 0:-5;
 }
 return result;
}
