/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { unsigned short *table; char *data; };
extern "C" int func_004C4CB8(unsigned short);
extern "C" int func_004C33A0(S *s,unsigned short *code,char **out1,char **out2) {
 unsigned int a=func_004C4CB8(code[0]);
 if(a-1>=84) return 0x8000112e;
 unsigned int b=func_004C4CB8(code[1]);
 if(b>=85) return 0x8000112e;
 int offset=(a*85+b)*2-170;
 unsigned short *p=(unsigned short*)((char*)s->table+offset);
 *out1=s->data+p[0]*7;
 *out2=s->data+p[1]*7;
 return 0;
}
