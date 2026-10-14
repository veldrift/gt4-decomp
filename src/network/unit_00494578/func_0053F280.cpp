extern "C" unsigned func_0057F260(const char*);
extern "C" char* func_005A6AB0(char*,const char*,unsigned);
extern "C" int func_0053F280(char* dst,unsigned* offset,const char* src) {
 unsigned n=func_0057F260(src)+1;
 unsigned old=*offset;
 if(old+n<256) {
 func_005A6AB0(dst+old,src,n);
 *offset+=n;
 return 1;
 }
 return 0;
}
