/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect {
 float x,y,z,w;
 Rect() {}
 Rect(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
 Rect(const Rect &r) {x=r.x;y=r.y;z=r.z;w=r.w;}
 Rect &operator=(const Rect &r) {if(this!=&r) {x=r.x;y=r.y;z=r.z;w=r.w;} return *this;}
 void translate(float a,float b) {x+=a;y+=b;z+=a;w+=b;}
 Rect intersect(const Rect &r) const {
 float a=x<r.x?r.x:x,b=y<r.y?r.y:y,c=z<r.z?z:r.z,d=w<r.w?w:r.w;
 if(c<=a || d<=b) {c=a;d=b;}
 return Rect(a,b,c,d);
 }
};
struct Widget;
struct Entry {short delta,index; int (*fn)(void *);};
struct Widget {int a; Entry *vt;};
struct Elem {Widget *widget; int depth; Rect p,q; int flags;
 Elem(Widget *a,int b,const Rect &c,const Rect &d):widget(a),depth(b),p(c),q(d),flags(0) {}
};
struct Vector {int alloc; Elem *begin,*end,*cap;};
struct RectVector {int alloc; Rect *begin,*end,*cap;};
struct Obj {int mode; char pad[0x14]; Rect p,q; Widget *selected,*root; RectVector clip; int depth;};
extern "C" Widget *func_00206868(Widget *);
extern "C" int func_00206880(Widget *);
extern "C" float mWidget__getWindowX(Widget *);
extern "C" float mWidget__getWindowY(Widget *);
extern "C" void mWidget__getWindowSize(Widget *,float *,float *);
extern "C" Widget *func_0025C300(Widget *);
extern "C" int func_00265DC8(Widget *);
extern "C" int func_00265EA8(Widget *);
extern "C" int func_002661C8(Widget *);
extern "C" Rect func_00267F70(Widget *);
extern "C" Rect func_00268228(Widget *);
extern "C" void func_0026F790(Obj *,Rect *,Rect *) throw();
extern "C" bool func_0026F7E8(Obj *,Rect *) throw();
extern "C" void func_0026F868(Obj *,Rect *) throw();
extern "C" void func_0026F9C8(Obj *) throw();
extern "C" void func_005DF950(RectVector *,Rect *,const Rect &);
extern "C" void func_005DFB88(Vector *,Elem *,const Elem &);
inline void *operator new(unsigned int,void *p) throw() {return p;}
static inline int vcall(Widget *w,int off) {Entry *e=(Entry *)((char *)w->vt+off);return e->fn((char *)w+e->delta);}
static inline void push(Vector *v,const Elem &e) {if(v->end!=v->cap) {new(v->end) Elem(e);++v->end;} else func_005DFB88(v,v->end,e);}
static inline void push(RectVector *v,const Rect &r) {if(v->end!=v->cap) {new(v->end) Rect(r);++v->end;} else func_005DF950(v,v->end,r);}
static inline void pop(RectVector *v) {--v->end;}
extern "C" int func_0026F9E0(Obj *o,Vector *v,Widget *w,float x,float y,int index) {
 int result=0;
 if(func_00265EA8(w)) {
 float a,b; mWidget__getWindowSize(w,&a,&b);
 Rect r(x,y,x+a,y+b);
 Rect p=func_00267F70(w);p.translate(x,y);
 Rect q=func_00268228(w);q.translate(x,y);
 Rect clip(0.0f,0.0f,0.0f,0.0f);
 if(func_0026F7E8(o,&clip)) {
 r=r.intersect(clip);p=p.intersect(clip);q=q.intersect(clip);
 if(r.z-r.x>0.0f && r.w-r.y>0.0f) result=1;
 } else result=1;
 if(result) {
 func_0026F790(o,&p,&q);
 push(v,Elem(w,o->depth,p,q));
 if(w==o->selected) {o->p=p;o->q=q;}
 }
 }
 if(!result && vcall(w,0x1b0) && func_00265DC8(w) && !func_002661C8(w) && func_00206880(w)>0) {
 if(!o->mode) {
 if(w==o->root) {float a,b;mWidget__getWindowSize(w,&a,&b);push(&o->clip,Rect(x,y,x+a,y+b));++o->depth;}
 if(vcall(w,0x1a8)) {float a,b;mWidget__getWindowSize(w,&a,&b);Rect r(x,y,x+a,y+b);func_0026F868(o,&r);}
 }
 int i=0;
 for(Widget *c=func_00206868(w);c;c=func_0025C300(c)) {
 float cx=mWidget__getWindowX(c)+x;float cy=mWidget__getWindowY(c)+y;
 if(func_0026F9E0(o,v,c,cx,cy,i)) result=1;
 ++i;
 }
 if(!o->mode) {
 if(vcall(w,0x1a8)) func_0026F9C8(o);
 if(w==o->root) {pop(&o->clip);--o->depth;}
 }
 }
 return result;
}
