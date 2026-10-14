/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cubic {
 float c0,c1,c2,c3;
 Cubic(const Cubic *p, float t) {
  float t2=t*t;
  float a=p->c0,b=p->c1,c=p->c2,d=p->c3;
  float triple=d*3.0f;
  c0=a-b*t+c*t2-d*(t2*t);
  c1=b-2.0f*c*t+triple*t2;
  c2=c-triple;
  c3=d;
 }
};
extern "C" Cubic func_00421B48(const Cubic *p,float t) {
 return Cubic(p,t);
}
