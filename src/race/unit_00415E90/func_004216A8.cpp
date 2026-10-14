/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float v[3]; };
struct V4 { float v[4]; };
extern "C" V3 *func_00421C28(V3 *, V4 *);
extern "C" float func_00421BF8(V4 *, float);
extern "C" float func_00421AE8(V3 *, float);
extern "C" void func_004216A8(V4 *out, V4 *in) {
 V3 tmp;
 float k;
 float t=0.0f;
 float *last=&out->v[3];
 func_00421C28(&tmp,in);
 out->v[0]=func_00421BF8(in,t);
 k=0x1.555554p-2f;
 out->v[1]=out->v[0]+func_00421AE8(&tmp,t)*k;
 float one=1.0f;
 *last=func_00421BF8(in,one);
 out->v[2]=*last-func_00421AE8(&tmp,one)*k;
}
