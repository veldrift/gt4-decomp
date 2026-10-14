/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char pad[4]; short first,last; };
struct State { int mode; char pad[0x214]; Rec rec; char tail[0x41c-0x220]; };
struct Obj { char pad[0x858]; int index, unused,busy; };
extern "C" Rec *func_004B5CC0(Obj *) throw();
extern "C" void func_004B5F50(Obj *,Rec *) throw();
extern "C" void func_004B66F0(Obj *,int) throw();
extern "C" void func_004B54E8(Obj *) throw();
extern "C" int func_004B4220() throw();
extern "C" void func_0057D9C0(const char *,...);
extern char D_006B0458[];
extern "C" int func_004B7078(Obj *self) {
    if(self->busy) return 1;
    char *block=(char *)self+(1-self->index)*0x41c;
    State *s=(State *)(block+0x20);
    switch(s->mode) {
    case 0: case 1: {
        Rec *r=func_004B5CC0(self);
        if(r->last-r->first>0) {
            func_004B5F50(self,r);
            func_004B66F0(self,-1);
            return 1;
        } else {
            func_004B5F50(self,(Rec *)(block+0x238));
            return 1;
        }
    }
    case 2: {
        func_004B54E8(self);
        int v=func_004B4220();
        if(v<0) func_0057D9C0(D_006B0458,v&255,v&0x7f00);
        s->mode=1;
        break;
    }
    }
    return 1;
}
