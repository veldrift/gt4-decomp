struct S { char pad[0x8c1c]; int a; char gap[12]; int b; };
extern "C" int func_005411B0(S *p, int a, int b) {
 S *q=p;
 int result=2;
 if (p) { p=0; q->a=a; result=(int)p; q->b=b; }
 return result;
}
