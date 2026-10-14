typedef unsigned int u32;
typedef unsigned short u16;
struct Req { void *obj; int handle; int id; int user; };
struct Req2 { void *obj; int handle; int id; int result; int user; };
struct Obj { char pad0[0x104]; int kind; char pad108[0x60]; int (*notify)(Req2 *); int userN; int (*accept)(Req *); int userA; };
struct Entry { int w0; int handle; int kind; };
struct Ctx { char pad0[0x118]; int current; };
struct Event { char value; char pad1; u16 id; char state; char pad5[11]; };
struct Frame { Event event; Req req; Req2 req2; };
extern Ctx *D_0064B4B4;
extern "C" Entry *func_00515DD8(u32) throw();
extern "C" void func_00516030(int,int,u32) throw();
extern "C" int func_00536568(int);
extern "C" int func_00532588(Obj *,int,int,int,Event *);
extern "C" void *func_005A48D8(void *,int,u32);
extern "C" int func_0051A5D0(Obj *obj,int unused,int handle,u16 *input) {
 Frame sp;
 Ctx **gp = &D_0064B4B4;
 if ((int)obj != (*gp)->current) return -1;
 u32 id = *input;
 Entry *entry = func_00515DD8(id);
 if (entry == 0) return -1;
 if (obj == 0) return -1;
 if (entry->kind == obj->kind) {
 if (entry->handle == -1) {
  if (obj->accept == 0) {
   entry->handle = handle;
   func_00516030(handle,id,-2);
   sp.event.value = func_00536568(handle);
   sp.event.id = id;
   sp.event.state = 1;
   func_00532588(obj,-1,12,6,&sp.event);
  } else {
  Req *args = &sp.req;
  func_005A48D8(args,0,16);
  Obj *owner = (Obj *)(*gp)->current;
  int user = obj->userA;
  sp.req.user = user;
  sp.req.obj = owner;
  sp.req.handle = handle;
  sp.req.id = id;
  sp.event.value = func_00536568(handle);
  sp.event.id = id;
  int result = obj->accept((Req *)args);
  if (result == 1) {
   entry->handle = handle;
   if (obj->notify == 0) {
    func_00516030(handle,id,-2);
   } else {
    Req2 *args2 = &sp.req2;
    func_005A48D8(args2,0,20);
    Obj *owner2 = (Obj *)(*gp)->current;
    int handle2 = entry->handle;
    int user2 = obj->userN;
    sp.req2.obj = owner2;
    sp.req2.handle = handle2;
    sp.req2.id = id;
    sp.req2.user = user2;
    sp.req2.result = result;
    obj->notify(args2);
   }
   sp.event.state = result;
   func_00532588(obj,-1,12,6,&sp.event);
  } else {
   sp.event.state = 2;
   func_00532588(obj,handle,12,6,&sp.event);
  }
  }
 } else {
  sp.event.value = func_00536568(handle);
  sp.event.id = id;
  sp.event.state = 3;
  func_00532588(obj,handle,12,6,&sp.event);
 }
 }
 return 2;
}
