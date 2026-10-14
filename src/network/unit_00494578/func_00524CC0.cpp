struct Entry { char pad[0x14]; unsigned int value; };
struct Obj { char p[0x88]; Entry *entries; char q[0x30]; unsigned int count; };
struct Message { unsigned short code; unsigned char index; unsigned char pad; unsigned int value; };
struct Part { void *ptr; int len; };
struct Request {
 Part parts[8]; int size, count;

 void add(void * const p,const int n) { parts[count].ptr=p; parts[count].len=n; size+=n; ++count; }
};
extern "C" int func_00525648(int,int);
extern "C" void func_00526040(Obj*,int*,unsigned short*);
extern "C" int func_00527510(Obj*,int,int,int,Request*);
inline unsigned short sentinel() { return 0xfffe; }
inline int send(Obj *o,Request *r) { return func_00527510(o,0,0,0xf000,r); }
extern "C" int func_00524CC0(Obj *o, unsigned char index, unsigned int value) {
 Message msg;
 Request req;
 unsigned short id=sentinel();
 int state=0;
 if (!o) return 2;
 if (index>=o->count) return 2;
 if (!o->entries) return 3;
 func_00526040(o,&state,&id);
 if (state!=7) return 0xd4ed;
 if (value<2) {
  o->entries[index].value=value;
  msg.code=func_00525648(5,8);
  msg.index=index;
  msg.value=value;
  req.count=0; req.size=0;
  req.add(&msg,8);
  return send(o,&req);
 }
 return 2;
}
