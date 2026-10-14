/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[12]; float angle; };
extern "C" float func_0057D380(float);
extern "C" void func_00378F18(void *,float,float,float);
extern "C" void func_00400CB8(Obj *o) {
 float *p=&o->angle;
 float t;
 float half;
 float rad;
 float one=1.0f;
 float x=*p;
 if(x<45.0f) x=45.0f;
 half=0.5f;
 rad=0x1.1df468p-6f;
 t=(one/func_0057D380(x*half*rad))*0x1.66819ap-1f;
 func_00378F18(o,t,one,one/func_0057D380(*p*half*rad));
}
