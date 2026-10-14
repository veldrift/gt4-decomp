struct H2 { char b[2]; };
struct W4 { char b[4]; };
struct B100 { char b[100]; };
struct Packet { H2 h0; W4 w2; char pad6[2]; W4 w8; W4 wc; W4 w10; B100 data; H2 len; char payload[400]; unsigned char tail; char pad; };
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern int (*D_0064A2F4)(int,int,int,void *);
extern "C" short func_005148D0(int a0,int a1,int a2,char *src) {
 Packet l;
 func_005A48D8(&l,0,0x20c);
 char *p=src;
 l.h0=*(H2 *)p; p+=2;
 l.w2=*(W4 *)p; p+=4;
 l.w8=*(W4 *)p; p+=4;
 l.wc=*(W4 *)p; p+=4;
 l.w10=*(W4 *)p; p+=4;
 l.data=*(B100 *)p; p+=100;
 l.len=*(H2 *)p; p+=2;
 func_005A4724(l.payload,p,*(short *)&l.len);
 p+=*(short *)&l.len;
 l.tail=*(unsigned char *)p;
 if (D_0064A2F4) D_0064A2F4(a0,a1,a2,&l);
 return *(short *)src;
}
