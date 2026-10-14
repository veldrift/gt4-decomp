/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { short delta,index; void (*fn)(void *); };
struct Obj { int f0; E *vt; char pad8[0x28]; int n30,n34; };
extern "C" void *BlockUnit__initialize(Obj *,int,int) throw();
extern "C" void func_0027A1E8(void *,Obj *) throw();
extern "C" void func_0027B138(Obj *self,Obj *other) {
    int i=0;
    E *e=(E *)((char *)other->vt+0x238);
    e->fn((char *)other+e->delta);
    if(self->n34>0) {
        do {
            int j=0;
            if(self->n30>0) {
                do {
                    int cur=j;
                    j+=1;
                    func_0027A1E8(BlockUnit__initialize(self,cur,i),other);
                } while(j<self->n30);
            }
            i+=1;
        } while(i<self->n34);
    }
}
