/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004BC818(unsigned short *, unsigned char *, int) throw();
extern "C" int func_004BD378(char *, int, int, int, int) throw();
extern "C" int func_004BE578(char *self, unsigned short id, int offset, unsigned short target) {
 unsigned short value;
 unsigned short count;
 int type = id & 0xff00;
 if(type == 0x200) {
  count = *(unsigned short *)(self+(id & 0xff)*16+0x48);
 } else {
  count = *(unsigned short *)(self+(id & 0xff)*16+0x58);
 }
 unsigned char *cursor;
 if(type == 0x200) cursor = (unsigned char *)(*(int *)(self+(id & 0xff)*16+0x40) + offset + 6);
 else cursor = (unsigned char *)(*(int *)(self+(id & 0xff)*16+0x50) + offset + 6);
 for(int i=1; i < count; i++) {
  func_004BC818(&value,cursor,2);
  cursor += 6;
  if(value == 0) break;
  if(value == target) {
   func_004BD378(self,id,offset,i,-1);
   return 0;
  }
 }
 return -1;
}
