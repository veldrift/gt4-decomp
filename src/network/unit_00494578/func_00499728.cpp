struct S {char pad[18];unsigned short count;};
extern "C" int func_004AA788(S *);
extern "C" int func_004AA650(unsigned,S *);
extern "C" void func_00498828(S *,int);
extern "C" void func_00499508(S *);
extern "C" void func_004A2038(int);
extern "C" void func_004A4910();
extern "C" int func_00499728(S *self){if(!self->count)return -1;int n=func_004AA788(self);if(n<0){n=func_004AA650(self->count<<6,self);if(n>=0){func_00498828(self,n);func_00499508(self);func_004A2038(1);func_004A4910();}}return n;}
