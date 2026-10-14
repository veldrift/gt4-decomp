/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b,w,h,x,y,dx,dy; char pad[0x20]; };
extern "C" {
void func_00105280(void *,int); int func_001052E0(void *,int,int,int); void func_00105338(void *,void *,int);
void func_001056A0(void *);void func_00105728(void *);int func_00105818(void *);int GSBuffer__getBufferWidth(void *);
void *func_00105AD8(void *,void *,int,int);
void func_004A1638(int);void func_004A2808(int,float);void func_004A2980(int);void func_004A29A8(int);void func_004A4550(int,int);void func_004A4810(int,int,int);
void func_004A6498(int,int,int,int,int,int,int,int);void func_004AA1D8(float,float,float,float);void func_004AB040(int);
float func_0057D488(float);
}
extern "C" void func_001D56B0(Buf *arg,float alpha,float count,float sigma) {
 Buf a,b; float weights[32];
 int i=0;
 func_001052E0(&a,0,GSBuffer__getBufferWidth(arg)/2,arg->h/2);
 Buf *pb=&b;
 func_00105338(pb,&a,0);
 func_00105AD8(&a,arg,1,1);
 int w=a.w; int h=func_00105818(&a);
 for(;i<count;i++) weights[i]=func_0057D488((float)(-i*i)/(2.0f*sigma*sigma));
 float sum=0.0f;
 func_004A1638(6);func_004AB040(5);func_004A29A8(0);func_004A2980(0xffffff);
 func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
 func_00105728(&a);func_001056A0(pb);
 for(i=0;i<count;i++) { float v=weights[i];sum+=v;func_004A2808(100,v/sum);func_004A6498(i,0,w,h,0,0,w-i,h); }
 for(i=1;i<count;i++) { float v=weights[i];sum+=v;func_004A2808(100,v/sum);func_004A6498(0,0,w-i,h,i,0,w,h); }
 sum=0.0f;
 func_00105728(pb);func_001056A0(&a);
 for(i=0;i<count;i++) { float v=weights[i];sum+=v;func_004A2808(100,v/sum);func_004A6498(0,i,w,h,0,0,w,h-i); }
 for(i=1;i<count;i++) { float v=weights[i];sum+=v;func_004A2808(100,v/sum);func_004A6498(0,0,w,h-i,0,i,w,h); }
 func_00105728(&a);func_001056A0(arg);
 func_004A4810(0,0,a.x+a.dx-2);func_004A4810(1,0,a.y+a.dy-2);
 func_004A4550(3,1);func_004A4550(2,1);func_004A4550(4,2);func_004A4550(5,2);
 func_004A2808(100,alpha);
 int width=arg->w;func_004A6498(0,0,width,func_00105818(arg),0,0,w,h);
 func_00105280(pb,2);func_00105280(&a,2);
}
