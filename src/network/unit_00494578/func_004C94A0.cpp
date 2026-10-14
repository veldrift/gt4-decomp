extern "C" void func_004C4070(void*,const void*,int);
extern "C" void func_004C94A0(unsigned*out,const unsigned*a,const unsigned*b){if(!a){func_004C4070(out,b,40);return;}if(!b){func_004C4070(out,a,40);return;}for(int i=9;i!=-1;--i){unsigned x=*a++;unsigned y=*b++;*out++=x|y;}}
