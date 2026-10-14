/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode, next; char pad8[8]; unsigned short str[256]; int count, pad214; char recs[0x200]; int current; };
struct Obj { char pad[0x20]; State state[2]; int index, pad85c, busy; };
struct Rec { char status, pad; short n, first, last; };
extern "C" Rec *func_004B5CC0(Obj *) throw();
extern "C" void func_004B4320(Rec *,int,int) throw();
extern "C" int func_004B4138(int,int) throw();
extern "C" unsigned short *func_004B48D0(unsigned short *,int,int) throw();
extern "C" void func_004B5E00(Obj *,Rec *,unsigned short *,int) throw();
extern "C" void func_0057D9C0(const char *,...);
extern char D_006B0458[];
extern "C" int func_004B7788(Obj *self) {
    if (self->busy) return 1;
    State *s = &self->state[1 - self->index];
    switch (s->mode) {
    case 0: return 0;
    case 1: return 0;
    case 2: {
        Rec *r = func_004B5CC0(self);
        r->status = 3;
        func_004B4320(r,-1,s->count);
        int v = func_004B4138(s->current-1,r->n);
        if (v < 0) func_0057D9C0(D_006B0458,v&0xff,v&0x7f00);
        unsigned short *text = func_004B48D0(s->str,256,r->n);
        func_004B5E00(self,r,text,r->last-r->first);
        break;
    }
    }
    return 1;
}
