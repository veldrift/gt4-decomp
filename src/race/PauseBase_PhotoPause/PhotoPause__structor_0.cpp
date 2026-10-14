struct Base { int x,y; void* vt; Base() __asm__("func_003C6520"); };
struct Sub { char pad[0x118]; int a,b[2],c,d,e; char tail[0x1c]; Sub() __asm__("func_00333400"); };
struct Handle { char bytes[16]; Handle() __asm__("func_00330860"); };
struct Obj { int x,y; void* vt; int a,b,c; char pad18[8]; char subbytes[0x16c]; char hbytes[16]; int x19c,x1a0,x1a4; Obj(char*) __asm__("func_003C3C20"); };
inline void* operator new(unsigned int,void* p){return p;}
extern char PhotoPause__vtable[];
extern void PhotoPause__init(Obj*);
extern void func_00333560(Sub*,char*,int,int,int,int,int,float);
extern void func_003C4640(Obj*,char*);
Obj::Obj(char* data) {
 new(this) Base;
 vt=PhotoPause__vtable;a=0;b=0;c=0;
 Sub& sub=*(new(subbytes) Sub);
 new(hbytes) Handle;
 x19c=0;x1a0=0;x1a4=0;
 PhotoPause__init(this);
 func_00333560(&sub,data,640,480,2,2,0,1.3333333f);
 sub.a=32;sub.c=1;sub.d=0;sub.e=0;
 func_003C4640(this,data+0xe350);
}
