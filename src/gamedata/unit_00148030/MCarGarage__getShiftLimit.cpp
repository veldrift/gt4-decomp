typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct VEntry {short delta,index;void (*fn)(Str*,void*);};
struct Obj {s32 unk0;char*vt;};
struct Tag {const char*name;};
union Temp {s32 ref[4];Str str;};
extern char D_0068F7A0[],D_0068F788[],PDISTD__UNIT_MANAGER[];
extern Rep D_00659FA8;
extern "C" void func_0013BDC0(void*,void*);
extern "C" void func_0013BD68(void*,s32);
extern "C" s32 func_00147D80(void*);
extern "C" s32 func_00441248(void*);
extern "C" void func_004413C8(s32,void*);
extern "C" char* func_004727B8(void*);
extern "C" s32 func_0057DA20(char*,const char*,...);
extern "C" s32 func_0057F260(const char*);
extern "C" char*func_005C2560(Rep*);
extern "C" void*func_005C2630(Str*,s32,s32,const char*,s32);
extern "C" void func_00314B20(void*,Str*);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void*,s32);
extern "C" Tag*func_005C11A8();
extern "C" void func_00326798(void*,s32,s32,const char*);
static inline char*c_str(Str*s){s32 len=((Rep*)s->p)[-1].len;if(!len)return D_0068F788;s->p[len]=0;return s->p;}
static inline void release(Str*s){Rep*q=(Rep*)(s->p-16);if(--q->ref==0){s32 size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}}
extern "C" void MCarGarage__getShiftLimit(s32*out,void*self,s32 argc,Obj**argv){
 Temp tmp;
 unsigned char data[0x600];
 char text[0x50];
 Str str;
 const char*fmt=D_0068F7A0;
 if(argc>0){Obj*o=*argv;VEntry*e=(VEntry*)(o->vt+0x18);e->fn(&tmp.str,(char*)o+e->delta);fmt=c_str(&tmp.str);release(&tmp.str);}
 func_0013BDC0(tmp.ref,self);
 s32 car=func_00147D80((void*)tmp.ref[0]);
 func_0013BD68(tmp.ref,2);
 func_004413C8(func_00441248((void*)car),data);
 s32 value=data[0xbe]*100;
 char*unit=func_004727B8(PDISTD__UNIT_MANAGER);
 char*pt=text;
 func_0057DA20(pt,fmt,value,unit);
 Str*ps=&str;
 Rep*r=&D_00659FA8;char*d;
 if(r->sel)d=func_005C2560(r);else{d=(char*)(r+1);r->ref++;}
 ps->p=d;
 func_005C2630(ps,0,-1,pt,func_0057F260(pt));
 func_00314B20(tmp.ref,ps);
 if(out!=tmp.ref){s32 v=tmp.ref[0];if(v)func_003285A8(v);s32 old=*out;if(old)func_003285F8(old);*out=v;}
 func_00312318(tmp.ref,2);release(ps);
}
