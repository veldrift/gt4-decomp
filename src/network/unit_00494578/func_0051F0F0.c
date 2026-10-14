/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;
struct Resource { int handle; u8 *data; char pad[8]; };
struct Api { char pad[100]; int (*f64)(u32,u32,u8*,int); int (*f68)(u32,u32,u8*); int (*f6c)(u8*,u32,u32,u32,u8*,int); int (*f70)(u8*,u32,u32,u32,u8*); };
extern struct Api *D_0064B710;
extern char D_0064AE24[];
extern char D_006C2778[],D_006C2780[],D_006C2788[],D_006C2790[],D_006C2798[],D_006C27A0[];
extern void func_00520298();
extern int func_005390A0(u8*,u32*);
extern void func_00539068(u8*,u32);
extern int func_0051E158(void*,u32,int,const void*,u32,int);
extern void *func_005A4724(void*,const void*,u32);
extern void *func_005A48D8(void*,int,u32);
extern int func_005202F0(u32*);
extern int func_00520490(u32*);
extern int func_00520518(u32*);
extern int func_005205B0(u32,u8*,u32,u32*);
extern int func_00520698(u32,u32,struct Resource*);
extern int func_00520738(struct Resource*);
extern int func_00520758(const char*,const char*,u32*);
extern int func_005208F8(u8*,u32);
static inline u32 limit(u32 a,u32 b) { return a<b?a:b; }
extern int func_0051F0F0(void *self,int unused,u8 *p,u32 size) {
 u8 buffer[512]; struct Resource res;
 u32 first, address, count, result;
 u32 type,length,index;
 u8 *start,*out;
 int convert=0; u32 max=499;
 if(size<13) return 0;
 type=*p++;
 func_005390A0(p,&first); p+=4;
 func_005390A0(p,&address); p+=4;
 func_005390A0(p,&count); p+=4; size-=13;
 start=buffer+3;
 out=start;
 *out++=type;
 result=0;
 *(u32*)out=first; out+=4;
 *(u32*)out=address; out+=4;
 length=9;
 index=0;
 *(u32*)out=16;
 switch(type) {
 case 0:
  count=limit(count,499);
  *(u32*)out=count;
  func_005A4724(out+4,(void*)address,count);
  length=13+count; break;
 case 1: D_0064B710->f64(address,count,out+4,16); length=29; break;
 case 2: D_0064B710->f68(address,count,out+4); length=29; break;
 case 3: func_00520490(&result); *(u32*)out=result; length=13; break;
 case 4: func_00520518(&result); *(u32*)out=result; length=13; break;
 case 5: D_0064B710->f6c(p,size,address,count,out+4,16); length=29; break;
 case 6: D_0064B710->f70(p,size,address,count,out+4); length=29; break;
 case 8: *(u32*)out=4; *(u32*)(out+4)=(u32)D_0064AE24; length=17; break;
 case 9: *(u32*)out=4; *(u32*)(out+4)=(u32)func_00520298; length=17; break;
 case 10: func_005202F0(&result); *(u32*)out=result; length=13; break;
 case 11: func_005205B0(address,out+4,499,&result); *(u32*)out=result; length=result+13; break;
 case 12: {
  u32 i=0,j=0; u8 *found=0;
  *(u32*)out=4; out+=4;
  for(;i<count && j<size;i++,j++) {
   if(((u8*)address)[i]!=p[j]) {j=0;found=0;}
   else { found=found?found:(u8*)address+i; }
  }
  *(u32*)out=(u32)found; length=17; break;
 }
 case 18:
  func_00520758(D_006C2778,(char*)p,&address);
  func_00520758(D_006C2780,(char*)p,&count); convert=1;
 case 13:
  count=max>count?count:max; func_00539068(out,count); out+=4;
  func_00520698(address,count,&res);
  if(res.data) { if(convert)func_005208F8(res.data,count); func_005A4724(out,res.data,count); func_00520738(&res); }
  else func_005A48D8(out,0,count);
  length=count+13; break;
 case 19:
  func_00520758(D_006C2778,(char*)p,&address);
  func_00520758(D_006C2780,(char*)p,&count); convert=1;
 case 14:
  func_00539068(out,16); out+=4;
  func_00520698(address,count,&res);
  if(res.data) { if(convert)func_005208F8(res.data,count); D_0064B710->f64((u32)res.data,count,out,16); func_00520738(&res); }
  else func_005A48D8(out,0,16);
  length=29; break;
 case 20:
  func_00520758(D_006C2778,(char*)p,&address);
  func_00520758(D_006C2780,(char*)p,&count); convert=1;
 case 15:
  func_00539068(out,16); out+=4;
  func_00520698(address,count,&res);
  if(res.data) { if(convert)func_005208F8(res.data,count); D_0064B710->f68((u32)res.data,count,out); func_00520738(&res); }
  else func_005A48D8(out,0,16);
  length=29; break;
 case 21:
  func_00520758(D_006C2778,(char*)p,&address);
  func_00520758(D_006C2780,(char*)p,&count);
  while(p[index]) { index++; if(index>=size) { func_005A48D8(out,0,16); length+=16; break; } }
  index++; convert=1;
 case 16:
  func_00539068(out,16); out+=4; length+=4;
  func_00520698(address,count,&res);
  if(res.data) { if(convert)func_005208F8(res.data,count); D_0064B710->f6c(p+index,size-index,(u32)res.data,count,out,16); func_00520738(&res); }
  else func_005A48D8(out,0,16);
  length+=16; break;
 case 22:
  func_00520758(D_006C2778,(char*)p,&address);
  func_00520758(D_006C2780,(char*)p,&count);
  while(p[index]) { index++; if(index>=size) { func_005A48D8(out,0,16); length+=16; break; } }
  index++; convert=1;
 case 17:
  func_00539068(out,16); out+=4; length+=4;
  func_00520698(address,count,&res);
  if(res.data) { if(convert)func_005208F8(res.data,count); D_0064B710->f70(p+index,size-index,(u32)res.data,count,out); func_00520738(&res); }
  else func_005A48D8(out,0,16);
  length+=16; break;
 case 23: func_00520758(D_006C2788,0,&result); func_00539068(out,result); length=13; break;
 case 24: func_00520758(D_006C2778,(char*)p,&result); func_00539068(out,result); length=13; break;
 case 25: func_00520758(D_006C2780,(char*)p,&result); func_00539068(out,result); length=13; break;
 case 26: func_00520758(D_006C2790,0,&result); func_00539068(out,result); length=13; break;
 case 27: func_00520758(D_006C2798,0,&result); func_00539068(out,result); length=13; break;
 case 28: func_00520758(D_006C27A0,0,&result); func_00539068(out,result); length=13; break;
 default: *(u32*)out=0; length=13; break;
 }
 func_0051E158(self,29,65535,start,length,0);
 return 0;
}
