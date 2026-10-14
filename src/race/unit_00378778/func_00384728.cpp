/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mat { char pad[0x44]; float x,y,z; char rest[0x30]; } __attribute__((aligned(8)));
extern "C" void func_003FB938(Mat *,void *,int);
extern "C" void func_00384728(void *p,void *arg1,Mat *src) {
 Mat tmp=*src;
 tmp.x=0x1.999998p-4f;
 tmp.y=500.0f;
 tmp.z=1.0f;
 func_003FB938(&tmp,arg1,1);
}
