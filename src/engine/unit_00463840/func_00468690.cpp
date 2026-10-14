/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *,const void *,int) throw();
extern "C" const char *func_00468690(char *buf,const char *name) {
 int len=func_0057F260(name);
 const char *end=name+len;
 if(end[-2]=='2' && end[-1]=='4') {
  func_005A6AB0(buf,name,len-2);
  (buf+len)[-2]=0;
  return buf;
 }
 return name;
}
