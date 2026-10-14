struct S { int a,b,c,d,e,f; };
extern void func_0052E120(S*) throw();
extern "C" void func_0052D550(S* s) {
 if(s && s->e && s->f && s->c) {
 s->a=0;s->b=0;s->d=0;
 return func_0052E120(s);
 }
}
