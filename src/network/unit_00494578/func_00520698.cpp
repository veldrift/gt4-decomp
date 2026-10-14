struct S{int pad;void*data;};
extern "C" int func_00538D50(S*,int,unsigned short);
extern "C" void*func_005A48D8(void*,int,int);
extern "C" void func_005ADF20(int);
extern "C" void func_005B1508(void*,int,void*,int,int);
extern "C" int func_00520698(int a,int b,S*s){if(!s)return 2;if(func_00538D50(s,b,64)!=0)return 100;if(!s->data)return 100;char local[28];func_005A48D8(local,0,28);func_005ADF20(0);func_005B1508(local,a,s->data,b,0);func_005ADF20(0);return 0;}
