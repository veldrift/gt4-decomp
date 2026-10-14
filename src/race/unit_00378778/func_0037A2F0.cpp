/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { char pad[12]; float fov; char pad10[0x68]; float target; };
struct Mat { char pad[0x44]; float x,y,z; char rest[0x30]; } __attribute__((aligned(8)));
extern "C" float func_0057D380(float);
extern "C" void func_003FB4C0(Mat *,int);
extern "C" void func_00379AA8(Cam *,float) throw();
extern "C" void func_0037A2F0(Cam *self,Mat *src,float a) {
 Mat tmp;
 float t = self->fov + (self->target-self->fov)*a;
 tmp=*src;
 float z = 1.0f/func_0057D380(t*0.5f*0x1.1df468p-6f);
 tmp.x=src->x;
 tmp.y=src->y;
 tmp.z=z;
 func_003FB4C0(&tmp,1);
 func_00379AA8(self,t);
}
