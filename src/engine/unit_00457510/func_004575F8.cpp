/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x,y,z,a,b,c; };
struct Shape { signed char count; char pad[3]; Pt pts[24]; };
extern float D_006AB060;
extern "C" void func_004A7AA8(float *,float *);
extern "C" float func_004575F8(Shape *s) {
 float out[4], in[4];
 int i=0;
 float max=D_006AB060;
 if (s->count>0) {
 float *v=in;
 Pt *p=s->pts;
 do {
   in[0]=p->x;
   in[1]=p->y;
   in[2]=p->z;
   in[3]=1.0f;
   func_004A7AA8(out,v);
   if (max<out[2]) max=out[2];
   i++; p++;
 } while (i<s->count);
 }
 return -max;
}
