extern signed char D_00624030[8][6];extern "C" int func_0046A050(void*,int);
extern "C" int func_0046BB48(void*s,unsigned n){if(n>=8)n=6;int v=D_00624030[n][0];int i=0;if(v!=-1){signed char*p=D_00624030[n];do{if(func_0046A050(s,v))return v;++i;++p;if(i>=6)break;v=*p;}while(v!=-1);}return -1;}
