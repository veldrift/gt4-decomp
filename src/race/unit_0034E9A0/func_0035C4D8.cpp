typedef unsigned char u8;typedef unsigned long long u64;
struct Self;struct CarData;
struct Buf {u64 key;void* data;int count;void* table;Buf() asm("func_00449D58");~Buf() asm("func_00449D78");};
extern u64 func_004454C0(CarData*);
extern int func_00449E10(Buf*,u64);
extern int func_004462E0(CarData*);
extern int func_00446320(CarData*);
extern u64 func_0044A048(Buf*,int,int);
extern void func_0044A2A8(Buf*);
extern u8 D_00620860[],D_00620870[];
inline int firstOf(int i){return D_00620860[i];}
inline int lastOf(int i){return D_00620870[i];}
extern "C" void func_0035C4D8(Self*s){
 int index=0;Buf buf;
 if(*(int*)((u8*)s+0xF8A0)>0){
 int off2=0xF968;u8*bounds=(u8*)s+0xF92B;u8*ids=(u8*)s+0xFB21;int off1=0xF940;
 do {
  u8*root=*(u8**)s;u8*list=*(u8**)(root+0x60);u8**cars=*(u8***)(list+8);
  CarData*car=(CarData*)(cars[index]+0x20);
  func_00449E10(&buf,func_004454C0(car));
  int a=func_004462E0(car),b=func_00446320(car);
  ids[-1]=a;ids[0]=b;
  u8 low=firstOf(a),high=lastOf(a);
  bounds[-3]=low;bounds[-2]=high;int first=low,last=high;
  if(first<=last){u64*out=(u64*)(((index<<4)+off1)+(unsigned)s);
  do {*out++=func_0044A048(&buf,0x19,first++);}while(first<=last);}
  low=firstOf(b);high=lastOf(b);
  bounds[-1]=low;bounds[0]=high;first=low;last=high;
  if(first<=last){u64*out=(u64*)(((index<<4)+off2)+(unsigned)s);
  do {*out++=func_0044A048(&buf,0x1A,first++);}while(first<=last);}
  func_0044A2A8(&buf);
 ++index;bounds+=4;ids+=2;off1+=0x40;off2+=0x40;
 }while(index<*(int*)((u8*)s+0xF8A0));
 }
}
