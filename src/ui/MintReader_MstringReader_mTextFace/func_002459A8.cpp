/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_002459A8(char *s) {
 int n=func_0057F260(s);
 int i=0;
 char *p;
 if(n>0) {
 int c=*s;
 p=s;
 if(c==32) {
 do {
 ++i;
 p=s+i;
 if(i>=n) break;
 } while(*p==32);
 }
 } else p=s;
 return p;
}
