struct S{char pad[0x160];unsigned char a,b;char pad2[3];unsigned char active,dirty;};
struct R{long key;char pad[0x40];int id;char pad2[0x14];int value;};
extern "C" void func_00444440(S*,long);
extern "C" void func_00445880(S*,int);
extern "C" void func_003D6350(S*,R*);
extern "C" void func_003D63A8(S*self,R*r){func_00444440(self,r->key);func_00445880(self,r->id);self->dirty=1;int value=r->value;if(value>=0){self->a=value;unsigned char low=*(unsigned char*)&r->value;self->active=1;self->b=low;}func_003D6350(self,r);}
