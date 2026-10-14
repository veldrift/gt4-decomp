/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int w[25]; };
struct Input { int a,b; char text[256]; char name[64]; Blob data; };
struct Packet { int id; unsigned char c4,c5; char pad[2]; int a,b; char text[256]; char name[64]; Blob data; };
extern int D_00853538;
extern int D_0064A1F8,D_0064A214,D_0064A2C8;
extern char D_0064A200[];
extern "C" void func_00506FB8();
extern void (*D_0064A2F8)();
extern "C" int func_0050A968();
extern "C" int func_0050A958();
extern "C" int func_0050B460(int,int,int,void *);
extern "C" int func_005A6AB0(void *,void *,int) throw();
extern "C" int func_00506DA8(Input *s,int arg1,int arg2) {
 int mode;
 if(D_00853538==0 || (mode=func_0050A968())!=1) return -5;
 if(func_0050A958()==0) return -6;
 D_0064A214=s->a;
 char *text=s->text;
 func_005A6AB0(D_0064A200,text,20);
 int count=D_0064A1F8;
 D_0064A2C8=arg1;
 D_0064A2F8=func_00506FB8;
 D_0064A200[19]=0;
 if(count<5) {
  if(count>0) {
   Packet p;
   p.c4=mode;p.c5=mode;p.a=s->a;p.b=s->b;p.id=arg2;
   func_005A6AB0(p.text,text,256);
   p.text[255]=0;
   func_005A6AB0(p.name,s->name,64);
   p.name[63]=0;
   p.data=s->data;
   return func_0050B460(1,0xde,0x1b4,&p)==0 ? 0 : -7;
  }
 }
 return 0;
}
