struct Obj {
 char pad[0x19C]; int state; int value; char pad2[0x1B8-0x1A4]; int other;
};
extern short D_0064A164;
extern int D_0064A150;
extern int D_008A0174;
extern int D_008A013C;
extern "C" int func_00506278(char *,int);
extern "C" int func_00504AC8(void) throw();
extern "C" void func_00504728(void *) throw();
extern "C" int func_0052EAF8(signed char,int,int,int,int,int,void *);
extern "C" int func_00505D40(Obj *o,int a,int b) {
 func_00506278((char *)o,0x15);
 func_00506278((char *)o+0x15,0x40);
 func_00506278((char *)o+0x155,0x20);
 func_00506278((char *)o+0x55,0x100);
 o->state=func_00504AC8();
 short state=D_0064A164;
 if(state!=1) return -12;
 if(func_00504AC8()==state || func_00504AC8()==2) {
  func_00504728(&o->value);
 } else if(func_00504AC8()==0 || func_00504AC8()==4) {
  o->value=0;
  o->other=0;
 } else return -13;
 int r=func_0052EAF8(0x40,D_0064A150,0xFFFF,3,0xF,0x1D4,o);
 D_008A0174=a;
 D_008A013C=b;
 return r==0 ? 0 : -5;
}
