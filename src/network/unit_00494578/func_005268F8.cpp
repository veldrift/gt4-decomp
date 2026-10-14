struct Entry { char p[0x1c]; int flag; char q[0x24]; };
struct Obj { char p[0x84]; Entry *entries; char q[0x54]; int (*cb)(int,int,void*); char r[8]; void *ctx; };
extern "C" void func_00526040(void*,int*,unsigned short*) throw();
inline unsigned short sentinel() { return 0xfffe; }
extern "C" int func_005268F8(Obj *self, unsigned short id) {
 unsigned short value=sentinel();
 int pos=0;
 func_00526040(self,&pos,&value);
 if((unsigned)(pos-6)<2) self->cb(id,0,self->ctx);
 else self->entries[id].flag=1;
 return 0;
}
