struct Target { char pad[0x18]; int mode; };
struct Obj { char pad[0x14]; Target *target; };
inline void setMode(Target *p, unsigned mode) {
 switch(mode) {
 case 0: p->mode=0; return;
 case 1: p->mode=mode; return;
 default: return;
 }
}
extern "C" void mEyetoyPS2__virtual_60(Obj *o,unsigned mode) {
 Target *p=o->target;
 if(p) setMode(p,mode);
}
