/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { short state, pad; };
union Word { int i; char *p; };
extern char D_00845370[];
extern "C" void func_003B0898(void *,const float *) throw();
extern "C" void func_003B1070(char *,char *) throw();
extern "C" void func_003B11A8(char *) throw();
extern "C" void func_003B1248(char *,char *,void *) throw();
extern "C" int func_003B1850();
extern "C" void func_00418A58(void *,void *);
extern "C" void ModelSet2__begin(void *,void *);
extern "C" void ModelSet2__end(void *);
extern "C" int ModelSet2___render(void *,int,void *);
extern "C" void func_004567E0(int);
extern "C" float func_00486600(float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7698(void *);
extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);
extern "C" void func_004A7B60(char *,int);
extern "C" void func_003B12E8(char *self,char *matrices) {
 float a[16],b[16];
 if (*(int *)(self+0x6bc)==0) return;
 if (*(void **)self==0) return;
 char *sub=self+0x10;
 int state=*(int *)(sub+0x690);
 if(state==3) return;
 char *g=D_00845370;
 ((union Word *)(g+4))->i=state;
 char *p=*(char **)(self+0x6b0);
 if(p) *(char **)(p+0x14)=g;
 if(*(int *)(self+0x7b4)) {
 func_004A53F8();
 func_004A7844(*(float *)(self+0x7c4),*(float *)(self+0x7c8),*(float *)(self+0x7cc));
 func_004A79B0(*(float *)(self+0x7d4)*180.0f*0x1.45f306p-2f);
 func_004A7988(*(float *)(self+0x7d0)*180.0f*0x1.45f306p-2f);
 func_004A79D8(*(float *)(self+0x7d8)*180.0f*0x1.45f306p-2f);
 }
 func_004567E0(0);ModelSet2__begin(*(void **)self,0);func_003B1070(self,matrices);
 int *index=(int *)(self+0x6c4);
 if(*(int *)(self+0x6b4)) {
 if(((Header *)index)[-1].state>=0) func_003B0898(self+0x6c0,(float *)(matrices+(*index<<6)));
 func_003B11A8(self);
 }
 if(*(int *)(self+0x6b8)) {
 func_00418A58(sub,a);
 int i=0;
 float *ap=a;
 func_00486600(b,b+1,b+2,b+3,b+4,b+5,b+6,b+7,b+8,b+9,b+10,b+11,b+12,b+13,b+14,b+15,ap[0],ap[1],ap[2],ap[3],ap[4],ap[5],ap[6],ap[7],ap[8],ap[9],ap[10],ap[11],ap[12],ap[13],ap[14],ap[15]);
 func_003B1248(self,matrices,b);func_004A7B60(matrices,func_003B1850());func_004A53F8();func_004A7698(ap);
 for(;i<*(short *)(self+0x762);i++) ModelSet2___render(*(void **)self,*(short *)(self+0x760)+i,*(void **)(self+0x6b0));
 func_004A5400();
 }
 ModelSet2__end(*(void **)self);func_004567E0(1);
 if(*(int *)(self+0x7b4)) func_004A5400();
}
