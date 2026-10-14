struct O { char pad[0x1c]; int status; int first; char pad2[0x14]; int second; };
extern short D_0064A164;
extern int D_0064A150, D_008A017C, D_008A0144;
extern "C" int func_00504728(void *) throw();
extern "C" int func_00504AC8(void) throw();
extern "C" int func_00506278(O *, int);
extern "C" int func_0052EAF8(int,int,int,int,int,int,O *);
extern "C" int func_00505F98(O *self, int arg1, int arg2) {
 func_00506278(self,0x15);
 if(self->status < 0) return -13;
 short mode = D_0064A164;
 if(mode != 1) return -12;
 if(func_00504AC8() == mode || func_00504AC8() == 2) {
  func_00504728(&self->first);
 } else if(func_00504AC8() == 0 || func_00504AC8() == 4) {
  self->first = 0; self->second = 0;
 } else return -13;
 int result = func_0052EAF8(0x40,D_0064A150,0xffff,3,0x14,0x50,self);
 D_008A017C = arg1; D_008A0144 = arg2;
 return result == 0 ? 0 : -5;
}
