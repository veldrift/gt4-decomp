struct Node {char pad[0xC];int c;};
struct Obj {struct Node *f0;int f4;char pad8[0x1C];char sub[4];};
struct Tmp {char pad[8];int a;char pad2[4];int b;};
extern "C" void func_004AE230(void*,const char*,int);
extern "C" int func_00449168(void*);
extern "C" void func_004490F8(void*,void*);
extern "C" void func_0044A6E0(void*,int,int);
extern "C" int func_00448FF8(struct Obj*self,const char*path){struct Tmp t;func_004AE230(&t,path,1);self->f0=(struct Node*)t.b;self->f4=t.a;if(func_00449168(self)==0)return -1;func_004490F8(self,self->f0);func_0044A6E0(self->sub,self->f0->c,3);return self->f4;}
