/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 {float x,y,z,w;};
extern "C" void func_0057D8A0(float *,float *,float);
extern "C" void func_0048AF70(Vec4 *a,float ang) {
    float sc[2];
    Vec4 r;
    func_0057D8A0(&sc[0],&sc[1],ang*0.5f);
    float x=a->x,z=a->z,w=a->w,y=a->y;
    float *px=&r.x,*py=&r.y,*pz=&r.z;
    *px=sc[1]*x+sc[0]*z;
    *py=sc[0]*w+sc[1]*y;
    *pz=-sc[0]*x+sc[1]*z;
    r.w=sc[1]*w-sc[0]*y;
    a->w=r.w;
    float rx=*px,ry=*py,rz=*pz;
    a->y=ry;
    a->z=rz;
    a->x=rx;
}
