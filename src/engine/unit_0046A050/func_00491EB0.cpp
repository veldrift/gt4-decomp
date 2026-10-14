struct S {char pad[28];float width,height;char pad2[92];void* callback;};
extern "C" S* PDISTD__global_font_manager;extern "C" float D_0062498C,D_00624990;
extern "C" int D_006D6184,D_006D6188,D_006D618C;
extern "C" void func_004A1638(int);extern "C" void func_004A2808(int,float);extern "C" void func_004A4550(int,int);
extern "C" void func_004998A8(void*,int*,int*,int*);
extern "C" void func_004A7CE0(int*,int*,int*,int*);
extern "C" void func_00491EB0() {
 D_006D618C=0;func_004A1638(6);func_004A2808(68,1.0f);func_004A4550(3,1);func_004A4550(2,1);
 D_006D6184=0;D_006D6188=0;
 int a[4];void* p=PDISTD__global_font_manager->callback;
 if(p){func_004998A8(p,a+1,a+2,a+3);return;}
 func_004A7CE0(a,a+1,a+2,a+3);
 S* s=PDISTD__global_font_manager;
 D_0062498C=(float)a[2]/s->width;D_00624990=(float)a[3]/s->height;
}
