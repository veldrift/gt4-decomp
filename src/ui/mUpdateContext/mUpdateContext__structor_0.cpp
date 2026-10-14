/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next,*prev; int value; };
struct List { int allocator; Node *head; };
struct Type { const char *name; };
struct Obj { int ref; void *vt; char pad8[8]; List a,b; int state; int buttons[2]; int axis[2][4]; char e[0x20]; int c[2]; short d[2],f[2]; char g[4]; int h[4]; char k[4]; short m[2]; int n[2]; float scale; short delay,rate; int flags,time,count,color,zero; int left[2],right[2]; List events; int d4,d8,dc,e0,e4; char mutex[0x30]; float vec[4]; int last; };
extern char mUpdateContext__vtable[];
extern "C" void *hObject__structor_0(Obj *);
extern "C" Type *func_005DD7F0();
extern "C" Type *func_005DD830();
extern "C" Type *func_005DD870();
extern "C" void *func_00326750(unsigned,int,const char *);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void func_00574D78(void *);
extern "C" void func_00203148(float *,float,float,float,float);
static inline void init(List *p,const char *name) {
 p->head=(Node*)func_00326750(12,4,name);
 p->head->next=p->head; p->head->prev=p->head;
}
extern "C" void mUpdateContext__structor_0(Obj *self) {
 int spare[4];
 List *a=&self->a,*b=&self->b,*events=&self->events;
 hObject__structor_0(self);
 self->vt=mUpdateContext__vtable;
 init(a,func_005DD7F0()->name);
 init(b,func_005DD830()->name);
 self->state=0;
 func_005A48D8(self->buttons,0,8);
 func_005A48D8(self->axis,0,32);
 func_005A48D8(self->e,0,32);
 func_005A48D8(self->c,0,8);
 func_005A48D8(self->d,0,4);
 func_005A48D8(self->f,0,4);
 func_005A48D8(self->g,0,4);
 func_005A48D8(self->h,0,16);
 func_005A48D8(self->k,0,4);
 func_005A48D8(self->m,0,4);
 func_005A48D8(self->n,0,8);
 self->scale=1.0f;
 self->delay=20;
 self->rate=6;
 self->flags=0;
 self->time=12000;
 self->count=15;
 self->color=0xffffff;
 self->zero=0;
 func_005A48D8(self->left,0,8);
 func_005A48D8(self->right,0,8);
 init(events,func_005DD870()->name);
 self->d4=0; self->d8=0; self->dc=0; self->e0=0; self->e4=0;
 func_00574D78(self->mutex);
 func_00203148(self->vec,0.0f,0.0f,0.0f,0.0f);
 self->last=0;
 for(int i=0;i<2;i++) { self->left[i]=0; self->right[i]=0; }
}
