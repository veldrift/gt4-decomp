/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { unsigned short a,b; int c; float data[16]; };
extern "C" int func_003B0848(int arg0,int arg1) {
 int i=0;
 char *dst=(char *)(arg0+8), *src=(char *)(arg1+8);
 do {
 int offset=i*4;
 ++i;
 *(float *)(dst+offset)=*(float *)(src+offset);
 } while(i<16);
 ((Obj*)arg0)->c=((Obj*)arg1)->c;
 ((Obj*)arg0)->a=((Obj*)arg1)->a;
 ((Obj*)arg0)->b=((Obj*)arg1)->b;
 return arg0;
}
