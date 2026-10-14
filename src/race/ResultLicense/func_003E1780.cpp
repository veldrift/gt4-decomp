/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_006A38E0[];
extern "C" void func_004A1638(int);
extern "C" void func_004A5BF8(int,int,void *);
extern "C" void func_004A5CC0(int,void *);
extern "C" void func_004AB040(int);
struct Vec { float x,y,z,w;
 Vec(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
 void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
};
extern "C" void func_003E1780(void) {
 func_004A5CC0(0,D_006A38E0);
 Vec v(0.3f,0.3f,0.3f,1.0f);
 func_004A5BF8(102,0,&v);
 v.set(0.5f,0.5f,0.5f,0.5f); func_004A5BF8(102,1,&v);
 v.set(0.5f,0.5f,0.5f,0.5f); func_004A5BF8(102,4,&v);
 v.set(0.0f,1.0f,0.0f,0.0f); func_004A5BF8(102,13,&v);
 func_004AB040(101); func_004A1638(102); func_004AB040(103); func_004AB040(104); func_004AB040(8);
}
