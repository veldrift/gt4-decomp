/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,idx; void (*fn)(); };
struct Obj { int unk0; char *vt; };
struct Frame { char pad[0xb4]; int b4; int b8; int bc; char gap[0x50]; int images[8]; float x,y; };
extern "C" void mImageFace__virtual_70(Frame *,Obj *,int);
extern "C" void mWidget__getWindowSize(Frame *,float *,float *);
extern "C" void func_002979A8(Frame *,Obj *,int,float,float,float,float) throw();
static inline void call(Obj *o,int slot) {
 Entry *e=(Entry *)(o->vt+slot);
 ((void (*)(void *))e->fn)((char *)o+e->delta);
}
static inline void call1(Obj *o,int slot,int x) {
 Entry *e=(Entry *)(o->vt+slot);
 ((void (*)(void *,int))e->fn)((char *)o+e->delta,x);
}
extern "C" void mFrameImageFace__virtual_70(Frame *s,Obj *o,int flag) {
 float w,h;
 if(!flag) { mImageFace__virtual_70(s,o,flag); return; }
 call(o,0x1d0);
 call1(o,0x1c0,s->b4);
 mWidget__getWindowSize(s,&w,&h);
 { float y=s->y; float x=s->x; float hh=h-(y+y); float ww=w-(x+x); func_002979A8(s,o,s->bc,x,y,ww,hh); }
 func_002979A8(s,o,s->images[0],s->x,0.0f,w-(s->x+s->x),s->y);
 { float x=s->x; float ww=w-(x+x); float y=s->y; func_002979A8(s,o,s->images[1],x,h-y,ww,y); }
 func_002979A8(s,o,s->images[2],0.0f,s->y,s->x,h-(s->y+s->y));
 { float y=s->y; float hh=h-(y+y); float x=s->x; func_002979A8(s,o,s->images[3],w-x,y,x,hh); }
 func_002979A8(s,o,s->images[4],0.0f,0.0f,s->x,s->y);
 func_002979A8(s,o,s->images[5],w-s->x,0.0f,s->x,s->y);
 func_002979A8(s,o,s->images[6],0.0f,h-s->y,s->x,s->y);
 func_002979A8(s,o,s->images[7],w-s->x,h-s->y,s->x,s->y);
 call(o,0x1c8);
 call(o,0x1d8);
}
