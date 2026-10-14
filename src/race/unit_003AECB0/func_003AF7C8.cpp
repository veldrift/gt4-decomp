/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Point { float x,y; };
struct Vertex { float x,y; int z; };
extern "C" Point *func_003AFCE8(int,int);
extern "C" void func_0049FD50(int,void*,void*,void*,int,int);
extern "C" void RaceEntryCar__update(int);
extern "C" void *func_004A5B70(int);
extern "C" void func_004A7550(float*);
extern "C" unsigned pglGetColor1ui();
extern "C" void func_004A7CE0(int*,int*,int*,int*);
extern "C" void func_003AF7C8(int n,float x0,float y0,float x1,float y1,float u0,float v0,float u1,float v1) {
 int viewport[4]; float matrix[16];
 Point *p=func_003AFCE8(n,0);
 if(p) {
 unsigned color=pglGetColor1ui();
 float alpha=(float)((color>>24)&255);
 color=(color>>1)&0x7f7f7f;
 Vertex *verts=(Vertex*)func_004A5B70(n*18-6);
 float *uv=(float*)func_004A5B70(n*12-4);
 unsigned *colors=(unsigned*)func_004A5B70(n*6-2);
 RaceEntryCar__update(1);
 func_004A7CE0(&viewport[0],&viewport[1],&viewport[2],&viewport[3]);
 func_004A7550(matrix);
 float sx=matrix[0]*(float)viewport[2];
 float sy=matrix[5]*(float)viewport[3];
 RaceEntryCar__update(0);
 volatile Vertex *a=verts;volatile float *b=uv;volatile unsigned *c=colors;
 int i=0;
 float dx=p->x*sx,dy=p->y*sy;
 float lx=x0+dx,ty=y0+dy,rx=x1+dx,by=y1+dy;
 for(;;) {
 float index=(float)i; ++i;
 a[0].x=lx;a[0].y=ty;a[0].z=0;
 a[1].x=rx;a[1].y=ty;a[1].z=0;
 a[2].x=lx;a[2].y=by;a[2].z=0;
 a[3].x=rx;a[3].y=by;a[3].z=0;
 b[0]=u0;b[1]=v0;b[2]=u1;b[3]=v0;
 b[4]=u0;b[5]=v1;b[6]=u1;b[7]=v1;
 unsigned col=((int)(alpha/(index+1.0f))<<24)|color;
 c[0]=col;c[1]=col;c[2]=col;c[3]=col;
 if(i>=n) break;
 float dx=p[1].x*sx;float dy=p[1].y*sy;++p;
 a[4].x=rx;a[4].y=by;a[4].z=0;
 lx=x0+dx;ty=y0+dy;rx=x1+dx;by=y1+dy;
 a[5].x=lx;a[5].y=ty;a[5].z=0;a+=6;
 b[8]=0;b[9]=0;b[10]=0;b[11]=0;b+=12;
 c[4]=0;c[5]=0;c+=6;
 }
 func_0049FD50(n*6-2,verts,uv,colors,0,0);
 }
}
