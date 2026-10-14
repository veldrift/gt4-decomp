extern char D_006AF5D0[];
extern void func_00497838(void*,void*,void*,int,float,float,float);
extern "C" void func_00497F98(void* a,void* b,float x,float y,float z,float scale) {
 scale*=0.5f;
 return func_00497838(a,b,D_006AF5D0,0,x*scale,y*scale,z*scale);
}
