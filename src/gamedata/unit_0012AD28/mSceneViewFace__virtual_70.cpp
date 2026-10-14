/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta,pad; void *fn; };
struct Vtable { char p[0x28]; Ent e28,e30,e38; };
struct Root { char p[0x64]; Vtable *vt; char pad[0xC6C]; int cd4; char p2[8]; int ce0; };
struct Obj { char p[0xA0]; int a0,a4,a8,ac,b0; float b4,b8; };
struct Dim { char p[0x1C]; float w,h; };
struct View { int a,b,c; char p[0x30]; };
struct Views { View views[2]; int current; };
extern Root *D_00618840;
extern int D_00618844;
extern Dim *PDISTD__global_font_manager;
extern Views D_0061850C;
extern char D_00821D18[];
extern "C" void mWidget__virtual_70(Obj *,void *,int);
extern "C" void pglPushAttrib(int);
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A5688();
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0012BFE0(Obj *);
extern "C" void func_0012C0C0(Obj *);
extern "C" void func_001056A0(View *);
extern "C" int func_00105818(View *);
extern "C" void func_004AB040(int);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A6140(int,int,int,int);
static inline void call(Root *r,Ent *e) { ((void (*)(void *))e->fn)((char *)r+e->delta); }
static inline bool nonzero(int n) { return n != 0; }
static inline void setDim(Dim *d,float w,float h) { d->w = w; d->h = h; }
static inline View *current(Views *v) { return &v->views[v->current]; }
extern "C" void mSceneViewFace__virtual_70(Obj *self, void *arg, int enabled) {
    mWidget__virtual_70(self,arg,enabled);
    if (enabled) {
        pglPushAttrib(0x8C7);
        RaceEntryCar__update(1);
        func_004A53F8();
        RaceEntryCar__update(0);
        func_004A53F8();
        if (D_00618840 && self->a0 == 0) {
            if (self->b0 == 0) {
                call(D_00618840,&D_00618840->vt->e28);
                call(D_00618840,&D_00618840->vt->e38);
                if (D_00618840->ce0) { self->b0 = 2; self->b4 = 1.0f; }
            } else if (self->b8 >= 1.0f) {
                if (--self->b0 == 0) {
                    func_00576100(D_00821D18);
                    self->a0 = 1;
                    self->a8 = 0;
                    func_00576140(D_00821D18);
                }
            }
            if (D_00618840->cd4) {
                if (nonzero(D_00618844) && D_00618844 == 1) func_0012BFE0(self);
                else func_0012C0C0(self);
                setDim(PDISTD__global_font_manager,640.0f,480.0f);
            }
        }
        if (self->b8 != 0.0f) {
            View *v = current(&D_0061850C);
            func_001056A0(v);
            func_004AB040(5);
            func_004AB040(4);
            func_004AB040(3);
            func_004AB040(2);
            func_004AB040(8);
            func_004A1638(6);
            func_004A2808(0x44,1.0f);
            func_004AA1D8(0.0f,0.0f,0.0f,self->b8);
            int c = v->c;
            func_004A6140(0,0,c,func_00105818(v));
        }
        func_004A5688();
        RaceEntryCar__update(1);
        func_004A5400();
        RaceEntryCar__update(0);
        func_004A5400();
    }
}
