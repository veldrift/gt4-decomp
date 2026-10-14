/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
struct Vec { float x,y,z; };
static inline float radians(float a) { return a*0x1.921fb4p+1f/180.0f; }
extern "C" void func_00398438(Vec *o, float a, float b) {
 float yaw=b;
 float pitch=-a;
 float sn=func_0057D2B8(radians(pitch));
 float cs=func_0057D1F0(radians(pitch));
 sn=-sn;
 yaw=-yaw;
 float x=func_0057D2B8(radians(yaw));
 float z=func_0057D1F0(radians(yaw));
 o->x=x*cs; o->y=sn; o->z=z*cs;
}
