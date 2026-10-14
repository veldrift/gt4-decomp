struct S {char pad[472];char a[12],b[12],c[12];};
extern "C" int func_005012A8(void*,int);
extern "C" void func_005019C8(S* s,int value) {
 if(!func_005012A8(s->a,value) && !func_005012A8(s->b,value))func_005012A8(s->c,value);
}
