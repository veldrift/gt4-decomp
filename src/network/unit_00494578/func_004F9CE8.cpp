inline int bits(int value,int mask){return value&mask;}
struct Obj { int a,b; };
struct S { char pad[0xee0]; int count;int indices[33];int mask; };
extern "C" void func_00576100(Obj*);
extern void func_00576140(Obj*);
extern int func_004F68C8(char*);
extern int func_004F8B28(void*,int*);
extern "C" void func_004F9CE8(S* s) {
 func_00576100((Obj*)s);
 if(s->mask>=0) {s->count=func_004F8B28((char*)s+0xcd8,s->indices);}
 else if(func_004F68C8((char*)s)==0) {
 int n=0,i=0;int one=1;int* p=s->indices;
 do { if(bits(s->mask,one<<i)){*p=i;++p;++n;} ++i;}while(i<16);
 s->count=n;
 }
 func_00576140((Obj*)s);
}
