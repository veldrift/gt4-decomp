struct State { int type, a, b; char pad[0x20]; unsigned short id; };
struct Obj { char p[0x84]; State *state; char q[0x3c]; unsigned short id; char r[2]; int flag; };
struct Callbacks { char p[0x24]; int (*set)(int,int,void*); char q[0x2c]; int (*get)(void*); };
extern Callbacks *D_0064B710;
extern "C" void func_00526040(void*,int*,unsigned short*);
extern "C" int func_0052D120(int);
extern "C" int func_0052D140(unsigned int*);
inline unsigned short sentinel() { return 0xfffe; }
extern "C" int func_005242C8(Obj *self, short *out) {
 char buf[0x40];
 unsigned short value=sentinel();
 int pos=0;
 unsigned int size;
 if (!out) return 2;
 *out=-2;
 if (!self) return 2;
 func_00526040(self,&pos,&value);
 if(pos) return 0xd4e7;
 State *s=self->state;
 s->id=self->id;
 *out=0;
 s->type=7;
 s->b=0;
 s->a=0;
 if(D_0064B710) {
  D_0064B710->get(buf);
  D_0064B710->set(-1,0,buf);
 }
 if(self->flag) {
  func_0052D140(&size);
  func_0052D120(size>>2);
 }
 return 0;
}
