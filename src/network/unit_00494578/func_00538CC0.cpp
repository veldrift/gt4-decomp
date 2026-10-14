extern "C" int func_00538B08(unsigned*,unsigned long) throw();
extern "C" int func_00538E38(unsigned*,unsigned,unsigned short);
extern "C" int func_00538CC0(unsigned *self, unsigned size, unsigned short align) {
 if(!self || !size) return 0x64;
 self[0]=0;
 self[1]=0;
 if(align>=2) {
  size += align-1;
  size += align-size%align;
 }
 int result=func_00538B08(self,(unsigned)size);
 if(result==0) result=func_00538E38(self+1,self[0],align);
 return result;
}
