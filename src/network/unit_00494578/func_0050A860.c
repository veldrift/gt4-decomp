extern int func_005063A8(int);
extern int func_005063E8();
extern void func_0057D9C0(const char*,...);
extern void* func_005A4724(void*,const void*,unsigned);
extern char* D_0064A2E8;
extern unsigned D_0064A2EC;
extern char D_006C1528[];
extern unsigned func_0050A860(int id,void* out,unsigned size){
 unsigned copied=0;
 char** buffer;
 if(func_005063A8(id))func_0057D9C0(D_006C1528);
 buffer=&D_0064A2E8;
 if(*buffer){
  unsigned* count=&D_0064A2EC;
  unsigned n=*count;
  if(n){
   int all=size>=n;
   copied=size<n?size:n;
   func_005A4724(out,*buffer,copied);
   if(all){*count=0;}
   else {
    unsigned left=*count-size;
    if(left<*count){
     func_005A4724(*buffer,*buffer+size,left);
     *count=left;
    }
   }
  }
 }
 if(func_005063E8())func_0057D9C0(D_006C1528);
 return copied;
}
