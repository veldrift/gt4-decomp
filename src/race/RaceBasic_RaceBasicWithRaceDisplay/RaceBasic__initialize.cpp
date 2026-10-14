/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cars { int x[2]; int *data; };
struct Course { int x; void *data; };
struct Ctrl { char pad[0x60]; Cars *cars; char gap[0x1c]; Course *course; };
struct Part { char *vt; };
struct Part8 { char pad[8]; char *vt; };
struct PartC { char pad[12]; char *vt; };
struct Obj { char pad[0x64]; char *vt; char gap[4]; Ctrl *ctrl; char gap70[0xe390]; Part8 *p400,*p404; int p408; void *p40c; int p410; void *p414; int value; PartC *p41c; Part *p420; void *p424; };
struct E0 { short delta,index; int (*fn)(void*); };
struct E1 { short delta,index; void (*fn)(void*,int); };
struct EP { short delta,index; void (*fn)(void*,Ctrl*); };
struct E2 { short delta,index; void (*fn)(void*,Ctrl*,int); };
struct EV { short delta,index; void (*fn)(void*); };
static inline int get(Obj *p,int off) { E0 *e=(E0*)(p->vt+off); return e->fn((char*)p+e->delta); }
static inline void callp(Part *p,int off,Ctrl *ctrl) { EP *e=(EP*)(p->vt+off); e->fn((char*)p+e->delta,ctrl); }
static inline void call1(Part *p,int off,int arg) { E1 *e=(E1*)(p->vt+off); e->fn((char*)p+e->delta,arg); }
static inline void init8(Part8 *p) { EV *e=(EV*)(p->vt+0x10); e->fn((char*)p+e->delta); }
static inline void initc(PartC *p,Ctrl *ctrl,int arg) { E2 *e=(E2*)(p->vt+0x10); e->fn((char*)p+e->delta,ctrl,arg); }
static inline bool ge3(const int &v) { return v>=3; }
extern "C" int RacePS2Base__initialize(Obj*,int);
extern "C" void func_003D8518(void*,Ctrl*,int);
extern "C" void func_003DCC50(void*,int,int);
extern "C" void func_003BABC8(void*,Ctrl*,int);
extern "C" void CourseData__setPause(void*,int);
extern "C" void RaceBasic__initialize(Obj *self,int arg) {
    RacePS2Base__initialize(self,arg);
    if(self->p420) {
        callp(self->p420,0x28,self->ctrl);
        call1(self->p420,0x40,arg);
        int index=get(self,0x310);
        call1(self->p420,0x50,index);
    }
    if(self->p400) init8(self->p400);
    if(self->p404) init8(self->p404);
    PartC *p=self->p41c;
    self->value=0;
    if(p) initc(p,self->ctrl,arg);
    if(self->p424) func_003D8518(self->p424,self->ctrl,arg);
    if(self->p40c) {
        Ctrl *ctrl=self->ctrl;
        int index=get(self,0x310);
        int car=ctrl->cars->data[index];
        int value=get(self,0x2f8);
        func_003DCC50(self->p40c,car,ge3(value)&&value<19);
    }
    if(self->p414) func_003BABC8(self->p414,self->ctrl,arg);
    CourseData__setPause(self->ctrl->course->data,0);
}
