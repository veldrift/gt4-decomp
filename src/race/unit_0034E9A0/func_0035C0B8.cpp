/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
#define U(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define I(p,o) (*(unsigned *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern "C" int DynamicsConductor__getCourseType(void *);
extern "C" u8 *func_00359538(void *);
extern "C" void func_0035BF08(void *,int,int,int,int) throw();
extern "C" long func_0035C6D8(void *,u8,int,u8);
extern "C" void func_00361570(void *,void *,int,int);
extern "C" void func_00361798(void *,int,int);
extern "C" void func_00362E58(void *,int);
extern "C" void func_003F3B68(void *,void *,int,int,int,void *);
extern "C" void func_004441B8(void *,void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *,int);
extern "C" void func_004468F8(void *,long);
extern u8 D_0069F6C0[];
inline bool positive(u8 *info,int i,s8 *sign) { if(i>=info[1]) return false; return *sign>0; }
inline bool negative(u8 *info,int i,s8 *sign) { if(i>=info[1]) return false; return *sign<0; }
extern "C" void func_0035C0B8(u8 *self) {
 u8 buf[0x600];
 u8 equipment[0x180];
 u8 *s=self+0x104;
 unsigned state=I(s,0x4b8);
 if((state&0xffff0010)==0x02d10010) {
  if(H(s,0x64c)>0) { if(--H(s,0x64c)==0) func_0035BF08(self,0xfe,0xfe,0xfe,0xff); }
 } else if((state&0xffff0100)!=0x005a0100) {
  int mode=0;
  if(U(s,0x4b8)&0x40) mode=1;
  if(U(s,0x4b8)&0x80) mode|=2;
  U(s,0x4ba)--;
  if(mode) {
   int change=0;
   if(s[0x64e]<0xfe || s[0x64f]<0xfe) change=1;
   u8 *conductor=P(self,4);
   int index=s[0x440];
   if(U(s,0x4ba)==0x285) {
    if(s[0x64e]==0xfe) conductor[index*8+0xda20]=conductor[index*2+0xfb20];
    if(s[0x64f]==0xfe) conductor[index*8+0xda21]=conductor[index*2+0xfb21];
   }
   if(U(s,0x4ba)==0x285 && change) {
    u8 *data=P(self,0x10);
    u8 *eq=equipment;
    func_004441B8(eq,P(P(P(P(self,0),0x60),8),index*4)+0x20);
    if(s[0x64e]!=0xff) {
     int a=s[0x64e];
     long reg=func_0035C6D8(conductor,index,0,a);
     if(reg!=-1) { func_004468F8(eq,reg); conductor[index*8+0xda20]=a; conductor[index*2+0xfb20]=a; }
    }
    if(s[0x64f]!=0xff) {
     int a=s[0x64f];
     long reg=func_0035C6D8(conductor,index,1,a);
     if(reg!=-1) { func_004468F8(eq,reg); conductor[index*8+0xda21]=a; conductor[index*2+0xfb21]=a; }
    }
    func_003F3B68(buf,eq,0,DynamicsConductor__getCourseType(P(self,4)),0,D_0069F6C0);
    func_00361570(data,buf,mode,0);
    SPEC_DATABASE__CarEquipments__setVariationOrder(eq,2);
   }
   if(U(s,0x4ba)==0x284 && change) {
    func_00361798(P(self,0x10),mode,0);
    s[0x64e]=0xff; s[0x64f]=0xff;
   }
   if(U(s,0x4ba)==0x3c) {
    int i=0;
    u8 *info=func_00359538(self);
    for(;i<(int)info[1];i++) {
     s8 *sign=(s8 *)info+0x3c+i;
     bool yes=false;
     if(positive(info,i,sign)) { if(U(s,0x4b8)&0x40) yes=true; }
     else if(negative(info,i,sign)) { if(U(s,0x4b8)&0x80) yes=true; }
     else { if(U(s,0x4b8)&0xc0) yes=true; }
     if(yes) func_00362E58(self,i);
     }
    U(s,0x4b8)&=0xff3f;
   }
  }
  if(U(s,0x4ba)==0x3b) U(s,0x4b8)|=0x200;
 }
}
