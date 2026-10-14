/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { float x,y; };
struct Face { char pad[0xc0]; int count; Pair data[256]; };
static inline void copy(Pair *dst,float *src,int offset) {
 int count=255;
 do {
  float x=*src;
  float *py=src+offset;
  count--;
  src+=2;
  dst->x=x;
  dst->y=*py;
  dst++;
 } while(count!=-1);
}
extern "C" void func_0029F798(Face *self,int *source) {
 float *src=(float *)(source+1);
 Pair *dst=self->data;
 self->count=*source;
 copy(dst,src,1);
}
