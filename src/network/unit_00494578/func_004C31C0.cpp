/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned short func_004C4D08(unsigned int);
extern "C" void func_004C31C0(int kind,unsigned char *base,unsigned char *data,unsigned short *out) {
 unsigned char *p;
 int count;
 if(kind==1) { p=base; count=(data[3]&15)-2; }
 else if(kind==2) {
  unsigned int v=(data[0]<<24)|(data[1]<<16)|(data[2]<<8);
  count=data[3];
  p=base+((long)((((unsigned long)v)|data[3])<<24)>>32);
 } else return;
 while(count>0) {
  unsigned int c=*p++;
  --count;
  *out++=func_004C4D08(c);
 }
 *out=0;
}
