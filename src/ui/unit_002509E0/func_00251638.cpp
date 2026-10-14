/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char pad[0x60]; float value[2]; };
struct Obj { char pad[0xc]; Sub sub; short dx[2],dy[2]; };
static inline short delta(short d,short *p) {
 if(d) {
  short old=d;
  if(*p) { d+=*p; *p=old; }
  else *p=d;
 }
 return d;
}
extern "C" void func_00251638(Obj *p,int i,short x,short y,short oldx,short oldy,float *outx,float *outy) {
 float nx=(float)x/32767.0f;
 float ny=(float)y/32767.0f;
 float sum=nx*nx+ny*ny;
 float len; __asm__ volatile("sqrt.s %0, %1":"=f"(len):"f"(sum));
 if(len>0.0f) { nx/=len; ny/=len; }
 short old; short *h;
 x-=oldx;
 if (x) {
  old=x; h=&((Obj*)(i*2+(int)p))->dx[0];
  if (*h) { x+=*h; *h=old; } else *h=x;
 }
 y-=oldy;
 if (y) {
  old=y; h=&((Obj*)(i*2+(int)p))->dy[0];
  if (*h) { y+=*h; *h=old; } else *h=y;
 }
 float value=p->sub.value[i];
 if(value<0.25f && x==0 && y==0) value-=0x1.47ae14p-7f;
 else value=len*len;
 if(value<0.0f) value=0.0f;
 if(value>1.0f) value=1.0f;
 p->sub.value[i]=value;
 *outx=nx*10.0f*value;
 *outy=ny*10.0f*value;
}
