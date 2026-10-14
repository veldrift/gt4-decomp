/* compiler: ee-gcc2.96-nogcse */
struct Vec { float x,y,z; };
extern "C" float func_00344AA8(void *,int,float);
extern "C" float func_00344C08(void *,int,float);
extern "C" float func_00344CE8(void *,int);
extern "C" int func_003CD620(Vec *out,float *angle,void *object,int index,int side) {
    float x,y,z,a;
    if(side==0) {
        y=0.0f;
        x=func_00344AA8(object,index,y);
        x=x-func_00344CE8(object,index)*0.5f;
        z=func_00344C08(object,index,y);
        a=0x1.921cacp+0f;
        out->x=x; out->y=y; out->z=z; *angle=a;
    } else {
        y=0.0f;
        x=func_00344AA8(object,index,y);
        x=x+func_00344CE8(object,index)*0.5f;
        z=func_00344C08(object,index,y);
        a=0x1.2d958p+2f;
        out->x=x; out->y=y; out->z=z; *angle=a;
    }
}
