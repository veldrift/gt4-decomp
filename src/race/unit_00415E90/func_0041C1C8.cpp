/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { volatile float x,y,z; };
struct S {
 volatile float m[5][4];
 volatile float f50,f54,f58,f5C,f60,f64,f68,f6C,f70,f74,f78,f7C,f80;
 char pad84[12]; V3 v90; int pad9C;
 int n0[2],pA8,pAC,n1[2],pB8,pBC,pC0,pC4,pC8,pCC,pD0,pD4;
};
extern "C" void func_0041C1C8(S *a) {
 *(int *)&a->f50=0;
 float zero=a->f50;
 a->f54=zero; a->f58=zero; a->f5C=zero;
 a->f60=0.5f; a->f64=zero; a->f68=1.0f; a->f6C=zero;
 a->f70=1.0f; a->f74=1.0f; a->f78=zero; a->f7C=zero; a->f80=zero;
 V3 *v=&a->v90; v->z=zero; v->y=1.0f; v->x=zero;
 a->pA8=1; a->pAC=0; a->pB8=1; a->pBC=1; a->pC0=1; a->pC4=1;
 a->pC8=0; a->pCC=0; a->pD0=0; a->pD4=0;
 int one=1;
 char *pb=(char *)a+8, *pa=(char *)a;
 for (int i=0;i<2;i++,pa+=4,pb+=4) {
  *(volatile float *)(pa+0)=0.5f; *(volatile float *)(pb+0)=0.5f;
  *(volatile int *)(pa+0x10)=0; *(volatile int *)(pb+0x10)=0;
  *(volatile float *)(pa+0x20)=0.5f; *(volatile int *)(pb+0x20)=0;
  *(volatile float *)(pa+0x30)=0.5f; *(volatile int *)(pb+0x30)=0;
  *(volatile int *)(pa+0x40)=0; *(volatile int *)(pb+0x40)=0;
  *(volatile int *)(pa+0xA0)=0; *(volatile int *)(pa+0xB0)=one;
 }
}
