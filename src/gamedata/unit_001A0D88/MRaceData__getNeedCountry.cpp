/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; };
struct Handle { void *p; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_00692808[],D_00692810[],D_00692818[],D_00692820[],D_00692828[],D_00692830[],D_00692838[],D_00692840[],D_00692848[],D_00692850[];
extern "C" void func_001A0B50(void *,void *) throw();
extern "C" void func_001A0AF8(void *,int) throw();
extern "C" void func_002EFBF0(void *);
extern "C" void func_002ED5C0(void *,int);
extern "C" void *func_002EEEB0(void *,void *,void *);
extern "C" void func_00309378(void *,int);
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
struct SlotH { Handle h; char pad[12]; };
struct SlotS { Str s; char pad[12]; };
struct Frame { SlotH data,list,out,v; SlotS s1; SlotH v2; SlotS s2; SlotH v3; SlotS s3; SlotH v4; SlotS s4,s5,s6,s7; };
extern "C" void MRaceData__getNeedCountry(Handle *ret,void *arg) {
 Frame f;
 func_001A0B50(&f.data.h,arg);
 char *data=(char*)f.data.h.p+16;
 Handle *list=&f.list.h;
 func_002EFBF0(list);
 switch((unsigned char)data[0x96]) {
 case 0: break;
 case 1: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692808;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 2: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s2.s;
 const char *src=D_00692810;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v2.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 3: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s3.s;
 const char *src=D_00692818;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v3.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 4: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s4.s;
 const char *src=D_00692820;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v4.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 5: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s5.s;
 const char *src=D_00692828;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 6: {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s6.s;
 const char *src=D_00692830;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 } break;
 case 7:
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s7.s;
 const char *src=D_00692830;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692838;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692840;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692828;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692820;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692818;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692848;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 {
 Handle *out=&f.out.h;
 void *obj=list->p;
 Str *s=&f.s1.s;
 const char *src=D_00692850;
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r); else { d=(char*)(r+1); r->ref++; }
 s->p=d;
 func_005C2630(s,0,-1,src,func_0057F260(src));
 Handle *v=&f.v.h;
 func_00314B20(v,s);
 func_002EEEB0(out,obj,v);
 func_00309378(out,2);
 func_00312318(v,2);
 Rep *q=(Rep*)(s->p-16);
 if(--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); }
 }
 break;
 }
 if(ret!=list) { void *p=list->p; if(p)func_003285A8(p); if(ret->p)func_003285F8(ret->p); ret->p=p; }
 func_002ED5C0(list,2);
 func_001A0AF8(&f.data.h,2);
}
