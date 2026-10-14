struct Node {char pad[0xC];int c;};
struct Obj {struct Node *f0;int f4;char pad8[0x1C];char sub[4];};
extern "C" void func_004AE268(void*,void*,void*,int,int);
extern "C" int func_00449168(void*);
extern "C" void func_004490F8(void*,void*);
extern "C" void func_0044A6E0(void*,int,int);
extern "C" int func_00449070(struct Obj*self,void*u,struct Node*n,int v){char buf[0x20];func_004AE268(buf,u,n,v,1);self->f0=n;self->f4=v;if(func_00449168(self)==0)return -1;func_004490F8(self,self->f0);func_0044A6E0(self->sub,self->f0->c,3);return self->f4;}
