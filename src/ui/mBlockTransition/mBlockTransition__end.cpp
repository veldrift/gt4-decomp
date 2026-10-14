/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { short delta,index; void (*fn)(void *,int); };
struct Obj { int f0; E *vt; char pad8[16]; int state; };
extern "C" int func_0024D1B0(Obj *,Obj *);
extern "C" void func_0024D2D8(Obj *);
extern "C" int func_0027B090(Obj *) throw();
extern "C" void func_0027B138(Obj *,Obj *) throw();
static inline void call0(Obj *o,int off) {
    struct E0 { short delta,index; void (*fn)(void *); };
    E0 *e=(E0 *)((char *)o->vt+off);
    e->fn((char *)o+e->delta);
}
extern "C" void mBlockTransition__end(Obj *self,Obj *other) {
    if (func_0024D1B0(self,other)) {
        switch(self->state) {
        case 0:
            func_0024D2D8(self);
            break;
        case 1:
            break;
        case 2:
            if (func_0027B090(self)) {
                call0(other,0x230);
                func_0024D2D8(self);
            }
            break;
        case 3:
            return;
        default:
            break;
        }
        E *e=(E *)((char *)other->vt+0x1C0);
        e->fn((char *)other+e->delta,0);
        call0(other,0x238);
        func_0027B138(self,other);
    }
}
