/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x38c]; float t,x,y,z,angle,end,nx,ny,nz,na,dx,dy,dz,da,vx,vy,vz,va; char gap[0x108]; float scale; };
extern "C" void func_0045C898(Obj *);
extern "C" void func_0045C7E8(Obj *);
extern "C" void func_0045C5A8(Obj *p) {
    float dt = (p->end - p->t) * p->scale;
    float dx = p->vx * dt;
    float dy = p->vy * dt;
    float dz = p->vz * dt;
    float da = p->va * dt;
    float nx = p->x + dx;
    float ny = p->y + dy;
    float nz = p->z + dz;
    float na = p->angle + da;
    p->dx = dx;
    p->dy = dy;
    p->dz = dz;
    p->da = da;
    p->nx = nx;
    p->ny = ny;
    p->nz = nz;
    p->na = na;
    func_0045C898(p);
    func_0045C7E8(p);
}
