/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 {float x,y,z,w;};
extern "C" void func_0057D8A0(float *,float *,float);
extern "C" void func_0048AE50(Vec4 *a,float ang) {
    float sc[2];
    Vec4 r;
    func_0057D8A0(&sc[0],&sc[1],ang*0.5f);
    float w=a->w,x=a->x,y=a->y,z=a->z;
    float *px=&r.x,*py=&r.y,*pz=&r.z;
    *px=sc[0]*w+sc[1]*x;
    *py=sc[1]*y-sc[0]*z;
    *pz=sc[0]*y+sc[1]*z;
    r.w=sc[1]*w-sc[0]*x;
    a->w=r.w;
    float rx=*px,ry=*py,rz=*pz;
    a->y=ry;
    a->z=rz;
    a->x=rx;
}
