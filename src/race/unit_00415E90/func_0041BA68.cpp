/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int u128 __attribute__((mode(TI)));
struct Vec4 {
 union { struct {float x,y,z,w;}; u128 q; };
 Vec4() {}
 Vec4(const Vec4 &o) { q=o.q; }
};
struct Obj;
struct Angle { float x; Angle(float a):x(a) {} };
extern "C" Vec4 func_0041B9E0(Obj *) throw();
extern "C" void func_00487830(float *,const float *,float);
extern "C" void func_0041BA68(Obj *self,const float *angle) {
 float *dest=(float *)((char *)self+0x10);
 Vec4 v=func_0041B9E0(self);
 Angle a(*angle);
 func_00487830(dest,&v.x,a.x);
}
