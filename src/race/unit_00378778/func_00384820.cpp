/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x100]; char m[0x84]; float x,y,z,scale; };
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A7550(void *);
extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A7890(float,float,float);
extern "C" void func_004A7988(float);
extern "C" int func_00384820(Obj *p) {
 float one=1.0f;
 float s=p->scale;
 func_004A0690();
 func_004A53F8();
 func_004A7454();
 func_004A7890(s,s,one);
 func_004A7988(90.0f);
 func_004A7844(-p->x,-p->y,-p->z);
 func_004A7890(one,0.0f,one);
 func_004A7550(p->m);
 func_004A5400();
 func_004A06F0();
 return 1;
}
