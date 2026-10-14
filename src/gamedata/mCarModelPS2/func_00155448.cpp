/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a,b; };
struct VE { short delta,index; void (*fn)(void *); };
struct Handle { char pad[0x4C]; void *f4C; char p50[0x1C]; int f6C; int f70; int f74; char p78[0x30]; VE *vt; };
struct Obj { char pad[0xA8]; char a8[0x30]; Pair d8; char pe0[8]; Handle *e8; char pec[0x64]; int f150,f154; };
extern "C" Handle *func_004AE1F8(int,int);
extern "C" int func_00155448(Obj *self,int arg1,int arg2,int arg3) {
    int result = 0;
    self->e8 = func_004AE1F8(0,arg1);
    if (self->e8) {
        Pair zero;
        zero.a = 0;
        zero.b = 0;
        self->f150 = 1;
        self->d8 = zero;
        self->e8->f74 = 0;
        self->e8->f4C = self->a8;
        Handle *fields = self->e8;
        fields->f6C = arg2;
        fields->f70 = arg3;
        Handle *h = self->e8;
        VE *e = h->vt + 2;
        e->fn((char *)h+e->delta);
        self->f154 = 1;
        result = 1;
    }
    return result;
}
