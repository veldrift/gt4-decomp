/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta,index; void (*fn)(void *); };
struct Obj { int word; VE *vt; };
extern "C" void func_004523B0(float,float,float);
extern "C" void func_004523E8(float,float,float,float);
extern "C" void func_00452408(float);
struct Rot { float x,y,z,w; void apply() const { func_004523E8(x,y,z,w); } };
extern "C" void func_00156768(Obj *self,char *arg) {
    float *pos = (float *)(arg+0x18);
    func_004523B0(-pos[0],-pos[1],-pos[2]);
    ((Rot *)(arg+0x58))->apply();
    func_00452408(1.0f);
    VE *e = self->vt + 0x38;
    e->fn((char *)self+e->delta);
}
