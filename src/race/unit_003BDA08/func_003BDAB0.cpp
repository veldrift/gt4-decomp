struct Pair { int a,b; };
struct Obj { Pair items[18]; };
extern int D_0062023C;
extern "C" unsigned int func_005724B0(void *, unsigned int, unsigned int);
extern "C" int func_005725A8(void *,int,int);
extern "C" void func_003BDAB0(char *o,unsigned int start,unsigned int size) {
 int off=0x80;
 char *second=o+4;
 func_005724B0(o,start,size);
 for (int i=0;i<2;i++,off+=8) {
 *(int *)(o+off)=func_005725A8(o,D_0062023C,0x10);
 *(int *)(second+off)=func_005725A8(o,0x53d0,0x10);
 }
}
