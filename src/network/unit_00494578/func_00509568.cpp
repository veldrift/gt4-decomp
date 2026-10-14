/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned func_0050FB30();
extern "C" int func_0050A5D8(int *);
extern "C" int func_0050A560(int *,unsigned);
extern "C" int func_0050FD00(int,unsigned,int *);
extern "C" void func_00509D80();
extern "C" int func_0053B310(void *,int *);
extern int D_0064A24C,D_0064A250,D_0064A254;
extern char D_00853548[];
extern "C" int func_00509568(int *a,int *b,int *c) {
 int tmp;
 unsigned size=func_0050FB30();
 func_0050A5D8(&D_0064A24C);
 D_0064A250=0;D_0064A254=0;
 if(func_0050A560(&D_0064A24C,size)) return -4;
 D_0064A250=size;
 if(!size) { *b=0;*a=0;*c=0;return -8; }
 func_0050FD00(D_0064A24C,size,&D_0064A254);
 if(!D_0064A24C) { *b=0;*a=0;*c=0;return -8; }
 func_00509D80();
 func_0053B310(D_00853548,&tmp);
 *a=D_0064A24C;*b=D_0064A254;*c=tmp;
 return 0;
}
