/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {float x,y,z;char pad[0x498];float t;};
extern "C" int func_0046B480(void *,int,int,float *,float *,float *,int *,int *,float);
extern "C" int func_0046B7B8(void *,int,int,float,float *,float *,float *,int *,int *);
extern "C" float func_00464868(void *ctx,Obj *obj,int key,int start,float *ox,float *oy,float t) {
 float x=obj->x,y=obj->y,z=obj->z;
 float dx,dy;
 for(int i=0;i<10;i++) {
  float at=obj->t+t;
  if(key!=4)func_0046B480(ctx,key,start,&x,&y,&z,0,0,at);
  else func_0046B7B8(ctx,4,start,at,&x,&y,&z,0,0);
  dx=x-obj->x;dy=y-obj->y;
  float len=dx*dx+dy*dy;
  __asm__("sqrt.s %0, %1" : "=f"(len):"f"(len));
  if(len>=5.0f)break;
  if(i<9)t+=1.0f;
 }
 *ox=dx;*oy=dy;
 return t;
}
