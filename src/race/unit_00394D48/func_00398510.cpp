/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
extern "C" float func_0057D118(float,float);
static inline float root(float a) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(a)); return r; }
extern "C" void func_00398510(Vec *v,float *pitch,float *yaw) {
 float x = v->x;
 float z = v->z;
 float d = root(x*x+z*z);
 *yaw = -func_0057D118(x,z)*0x1.ca5dc2p+5f;
 *pitch = func_0057D118(v->y,d)*0x1.ca5dc2p+5f;
}
