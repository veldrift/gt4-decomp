/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct State { u8 f[10]; char name[0x100]; char p10a[2]; int size; u8 option; char p111[3]; float x,y,z; };
struct Obj { char pad[0x30]; State state; };
struct Lock { void *p; char pad[12]; };
struct Args { int size,zero; char pad[8]; };
extern char D_0086C8D8[];
extern char D_006C8340[];
extern "C" void func_00574EB0(Obj *);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_005480F0(float);
extern "C" void func_00548060(float);
extern "C" void func_00547F78(float);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" char *func_005A609C(char *,const char *) throw();
extern "C" void *func_004AE370(void *,char *,Args *,int);
extern "C" void func_00547E10(char *,int);
extern "C" void func_00547F00();
extern "C" void func_00547F28();
extern "C" void func_00547F50();
extern "C" void func_00548178();
extern "C" void func_00547550(Obj *o) {
 State st;
 Lock lock;
 char path[0x100];
 char temp[0x20];
 Args args;
 void *mutex=D_0086C8D8;
 for(;;) {
 func_00574EB0(o);
 Lock *pl=&lock;
 pl->p=mutex;
 func_00576100(mutex);
 st=o->state;
 o->state.f[0]=0;
 o->state.f[1]=0;
 o->state.f[3]=0;
 o->state.f[4]=0;
 o->state.f[5]=0;
 o->state.f[6]=0;
 o->state.f[7]=0;
 o->state.f[8]=0;
 o->state.f[9]=0;
 func_00576140(pl->p);
 if(st.f[8]) func_005480F0(st.z);
 if(st.f[7]) func_00548060(st.y);
 if(st.f[6]) func_00547F78(st.x);
 if(st.f[1]) {
 if(st.size) {
 int len=func_0057F260(st.name);
 if(func_0057F238((char*)&st+len+6,D_006C8340)==0) {
 func_005A609C(path,st.name);
 char *pt=temp;
 path[len-1]='m';
 Args *pa=&args;
 pa->size=st.size;
 pa->zero=0;
 func_004AE370(pt,path,pa,1);
 }
 }
 func_00547E10(st.name,st.option!=0);
 void *p=D_0086C8D8;
 pl->p=p;
 func_00576100(p);
 if(o->state.f[1]==0) o->state.f[2]=1;
 func_00576140(p);
 }
 if(st.f[4]) func_00547F28();
 if(st.f[3]) func_00547F00();
 if(st.f[5]) func_00547F50();
 if(st.f[9]) func_00548178();
 }
}
extern "C" void func_005477C8(Obj *o) {func_00547550(o);}
