/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x14]; unsigned short *a; unsigned char *b; unsigned short *c; };
extern "C" void func_004C39F0(Obj *p, int *out1, int *out2) {
 if(out1) *out1=*p->c*8;
 if(out2) {
 if(*p->b==1) *out2=(0x1fff-*p->a)*8;
 else *out2=(0x2000-*p->a)*8;
 }
}
