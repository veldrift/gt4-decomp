struct Token { double value; } __attribute__((packed));
struct Obj { char pad[0x14c]; int count; };
struct Ops { char pad[0x70]; int (*test)(double); };
struct Hook { char pad[0x10]; int (*enable)(Obj*,int); int (*disable)(Obj*,int); int (*test)(Obj*); };
struct Config { char pad[0x68]; int first,second; };
extern Ops *D_0064B4B0;
extern Hook *D_0064B4AC;
extern Config *D_0064B47C;
extern "C" void func_005319A8(Obj*,int,double,int) throw();
extern "C" void func_00532628(Obj*,int) throw();
extern "C" void func_005327B0(Obj *self,int index,Token token,int flag) {
 if(D_0064B4B0->test(token.value)==0) {
 if(flag) {
 self->count++;
 Hook **hooks=&D_0064B4AC;
 if(!*hooks || !(*hooks)->test(self) || !(*hooks)->enable(self,index)) {
 int mode=D_0064B47C->first;
 if(!mode) mode=D_0064B47C->second;
 func_005319A8(self,index,token.value,mode);
 }
 } else {
 Hook **hooks=&D_0064B4AC;
 if(!*hooks || !(*hooks)->test(self) || !(*hooks)->disable(self,index)) {
 func_00532628(self,index);
 }
 }
 }
}
