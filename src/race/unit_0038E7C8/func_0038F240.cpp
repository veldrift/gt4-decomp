struct Geometry {char pad[0x38];float mass;char gap[0xA60-0x3C];float x,y,z,w;};
struct Obj {char pad[0x23C];Geometry *geometry;float a,b;};
extern "C" float func_003983E0(Geometry *,float,float);
extern "C" void func_004523E8(float,float,float,float);
extern "C" void func_00452408(float);
extern "C" void func_0038F240(Obj *self) {
    float result=func_003983E0(self->geometry,self->a,self->b);
    Geometry *geometry=self->geometry;
    float inverse=1.0f/geometry->mass;
    func_004523E8(geometry->x*inverse,geometry->y*inverse,geometry->z*inverse,geometry->w);
    func_00452408(result);
}
