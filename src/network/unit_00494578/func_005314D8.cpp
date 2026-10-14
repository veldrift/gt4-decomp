struct Self { char pad[0x158]; int state; int pad15c; int f160,f164; };
struct TableA { char pad[0x58]; int (*f58)(int); int (*f5c)(int,int); };
struct TableB { char pad[0x28]; int (*f28)(int); };
extern TableA *D_0064B4A8;
extern TableB *D_0064B4B8;
extern "C" int func_00535780(int);
extern "C" int func_005314D8(Self *self,int unused,int arg) {
 if(self->state==2) {
  if(D_0064B4B8->f28(self->f164)) return 37;
 } else {
  int r=func_00535780(D_0064B4A8->f58(self->f160));
  if(r) return r;
  r=func_00535780(D_0064B4A8->f5c(self->f160,arg));
  if(r) return r;
 }
 return 0;
}
