/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vt { short delta, index; void *fn; };
struct Obj { unsigned int flags; char pad[16]; Vt *vt; };
struct Entry { Obj *p; short x,y,w,h; unsigned char a,b; };
struct Global { char pad[32]; int mode; };
extern Global D_006184D0;
extern "C" int func_003A18A8(char *,int) throw();
extern "C" void RaceDisplayObjectBase__setLocation(Obj *,short,short);
extern "C" void RaceMiniMap__virtual_07(Obj *,short,short);
extern "C" void *func_005A48D8(void *,int,unsigned int);
static inline void vc(Obj *p,int off,int a,int b) {
 Vt *v=(Vt *)((char *)p->vt+off);
 ((void (*)(void *,int,int))v->fn)((char *)p+v->delta,a,b);
}
extern "C" void RaceDisplay__init_panel(char *self,int arg1) {
 int mode=func_003A18A8(self,arg1);
 Obj *p0=(Obj *)(self+0x108), *p4=(Obj *)(self+0x39fc);
 Obj *p1=(Obj *)(self+0xd58), *p2=(Obj *)(self+0x228c), *p3=(Obj *)(self+0x23dc), *p6=(Obj *)(self+0x2da0);
 Entry a[]={ {p0,320,452,640,0,2,1}, {p2,320,348,0,0,2,1}, {p3,24,328,280,0,4,1}, {} };
 Entry b[]={ {p1,320,464,640,0,2,1}, {p2,320,430,240,0,2,1}, {p3,320,430,240,0,2,1}, {(Obj *)(self+0x10e4),320,450,85,85,2,2}, {} };
 Entry c[]={ {p1,320,463,640,0,2,1}, {p2,320,400,0,0,2,1}, {p6,0,480,640,42,0,1}, {} };
 Entry d[]={ {p4,617,459,406,42,1,1}, {p3,24,360,280,0,4,1}, {} };
 Entry e[]={ {} };
 Entry f[]={ {p1,213,464,426,0,6,1}, {p2,203,380,0,0,6,1}, {p3,203,410,240,0,6,1}, {} };
 Entry *p;
 switch(mode) {
 case 0: *(Obj **)(self+20)=p0; p=a; break;
 case 1: *(Obj **)(self+20)=p1; p=b; *(unsigned int *)((char *)p1+0x388)&=~255; break;
 case 2: *(Obj **)(self+20)=p1; p=c; break;
 case 3: *(Obj **)(self+20)=p1; p=f; *(unsigned int *)((char *)p1+0x388)=(*(unsigned int *)((char *)p1+0x388)&~255)|1; break;
 case 4: *(Obj **)(self+20)=p4; p=d; break;
 case 5: *(Obj **)(self+20)=p1; p=e; break;
 default: *(Obj **)(self+20)=0; return;
 }
 for(;p->p;p++) {
 vc(p->p,0x48,p->a,p->b);
 vc(p->p,0x40,p->w,p->h);
 vc(p->p,0x38,p->x,p->y);
 p->p->flags=(p->p->flags&~255)|1;
 }
 RaceDisplayObjectBase__setLocation(p6,D_006184D0.mode ? -107:0,480);
 RaceMiniMap__virtual_07(p6,D_006184D0.mode ? 854:640,42);
}
