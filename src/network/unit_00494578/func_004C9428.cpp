extern "C" void func_004C4070(int*,const int*,int);
extern "C" void func_004C9428(int*out,int*a,int*b){if(!a){func_004C4070(out,b,40);return;}if(!b){func_004C4070(out,a,40);return;}for(int i=9;i!=-1;--i){int x=*a++;int y=*b++;*out++=x&y;}}
