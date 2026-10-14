struct Status { char pad[0xC]; int type; };
struct Self { char pad[0x100]; Status *status; int id; };
struct Record { int pad; unsigned a,b,c,d,e; char data[12]; };
struct Context { char pad[0x48]; Record *(*get)(Self *,int); char pad2[0x118-0x4C]; int handle; };
struct Request { char id; char pad[7]; unsigned short a,b,c,d,e; char pad2[4]; char data[12]; };
extern Context *D_0064B4B4;
extern "C" int func_00536568(int);
extern "C" int func_005A6AB0(void *,void *,int) throw();
extern "C" int func_00532588(int,int,int,int,void *);
extern "C" int func_0051BAE0(Self *o,int index) {
 Request req;
 Record *r=0;
 if((unsigned)(index+1)>=0x41) return 0x17;
 if(o==0) return 8;
 Status *status=o->status;
 if(status==0) return 8;
 Context **ctx=&D_0064B4B4;
 if(*ctx) r=(*ctx)->get(o,o->id);
 if(r!=0) {
 if(*ctx!=0) {
 if((unsigned)(status->type-4)<2) {
 req.id=func_00536568(o->id);
 req.a=r->a;
 req.b=r->b;
 req.c=r->c;
 req.d=r->d;
 req.e=r->e;
 func_005A6AB0(req.data,r->data,12);
 func_00532588((*ctx)->handle,index,15,0x24,&req);
 return 0;
 }
 return 0x15;
 }
 return 0x15;
 }
 return 0x15;
}
