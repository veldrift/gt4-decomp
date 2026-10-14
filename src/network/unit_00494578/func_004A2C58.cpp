struct E{float x,y;};extern E* D_00629FF0[];extern "C" void func_004A2B10(float,float) throw();
extern "C" void func_004A2C58(int n,int i,float f){if(n>0){if(n<17){E*p=D_00629FF0[n];if(p)func_004A2B10(p[i].x*f,p[i].y*f);}}}
