/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 { float x,y; };
struct Obj { float mass, inertia; char pad8[0x424]; char *p42c; char pad430[0x18]; float f448; char pad44c[4]; int p450; };
extern "C" float func_0045C0C8(void) throw() __attribute__((const));
extern "C" void func_00350530(int, int, char *, float);
extern "C" void func_0045E768(Obj *self,V2 *out,V2 *vel,V2 *normal,V2 *r) {
    float c=func_0045C0C8();
    float nx=normal->x, ny=normal->y;
    float cross=r->x*ny-r->y*nx;
    float d=self->mass+cross*cross*self->inertia;
    float j=d!=0.0f ? (-(c+1.0f)*(vel->x*nx+vel->y*ny))/d : 0.0f;
    out->x=j*nx;
    out->y=j*normal->y;
    float mag=j;
    if(mag<0.0f) mag=-mag;
    self->f448=self->f448+mag/100000.0f;
    func_00350530(self->p450,0,self->p42c+8,mag);
}
