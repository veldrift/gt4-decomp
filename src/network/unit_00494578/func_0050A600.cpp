struct B20 { char b[20]; };
struct B384 { char b[384]; };
struct Packet { short size; char zero[4]; B20 header; char pad[2]; int a, b; unsigned short total, count; short index; unsigned short len; B384 data; };
extern int D_00853538;
extern B20 D_0064A200;
extern void *D_0064A2F0;
extern char D_006C15F8[];
extern "C" void func_005072B8();
extern "C" int func_0050A958();
extern "C" int func_0050A968();
extern "C" void func_0057D9C0(const char *,...);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_0050B460(int,int,int,void *);
extern "C" int func_0050A600(int unused,char *p,unsigned n) {
 unsigned remain=n;
 if (!D_00853538 || func_0050A968()!=1) return -5;
 int i=0;
 func_0050A958();
 func_0057D9C0(D_006C15F8,n);
 D_0064A2F0=(void *)func_005072B8;
 int count=n/384 + (n%384 !=0);
 if(count>0) {
 for(;i<count;i++) {
 int index=count-i-1;
 Packet q;
 q.size=0x1ac;
 func_005A48D8(q.zero,0,4);
 q.header=D_0064A200;
 q.a=0; q.b=1; q.total=n; q.count=count; q.index=index;
 if(q.index) { q.len=384; remain-=384; }
 else { q.len=remain; remain=0; }
 q.data=*((B384 *)p+i);
 if(func_0050B460(1,0xe8,q.size,&q)) return 0;

 }
 }
 return n;
}
