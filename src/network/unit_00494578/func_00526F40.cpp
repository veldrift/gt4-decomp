typedef unsigned char u8; typedef unsigned short u16;
struct Entry { char pad[0x2e]; u16 seq[4]; char tail[14]; };
struct Group { Entry **list; Entry *other[3]; int pad; int mode; };
struct Context { struct Part { u8 *data; int size; } parts[8]; int total, count; Context() { count=0; total=0; } void add(u8 *data,int size) { parts[count].data=data; parts[count].size=size; count=count+1; total=total+size; } };
struct Obj { char pad[0x84]; Entry *entries; Group *groups; char p2[0x40]; void (*call)(u16,u8,unsigned,u8,u16,u8*,int,int); char p3[0x18]; int user; };
extern "C" int func_00538F98(u8*,u16*);
extern "C" int func_00538EE8(u8*,u8*);
extern "C" void func_00527510(Obj*,Entry**,int,u16,Context*);
extern "C" int func_00526F40(Obj *o,int id,u8 *data,int size) {
 struct Header { u16 pad,seq,index; u8 group,pad2; u16 kind; } h;
 Entry *out[3]; Context c; u8 flags;
 id &= 0xffff;
 int n=0; int channel=1;
 c.add(data,size);
 func_00538F98(data+2,&h.seq); func_00538F98(data+4,&h.index);
 func_00538EE8(data+6,&h.group);
 unsigned chan=h.group>>6; h.group &= 0x3f;
 func_00538EE8(data+7,&flags); data+=8; size-=8;
 h.kind=flags&15; flags=(flags&0xf0)>>4;
 if(o->groups) {
  Entry *entries=o->entries; Group *g=o->groups+h.group;
  if(g->list[id]!=entries+id) return 0;
  int mode=g->mode;
  if(mode==channel) {
   channel=chan*2;
   u16 *old=(u16*)(channel+(h.index*0x44+(int)entries)+0x2e);
   if((short)(*old-h.seq)>=0) {
    if(*old<0x7fff && (short)h.seq<0) *old=h.seq;
    else return 0;
   }
   for(unsigned i=0;i<3;i++) {
    Entry *e=g->other[i];
    if(e!=entries+id && e!=entries+h.index && e) { out[n++]=e; }
   }
   if(n) func_00527510(o,out,n,h.kind,&c);
  }
  o->call(h.index,h.group,chan,flags,h.seq,data,size,o->user);
  channel=chan*2;
  *(u16*)(channel+(h.index*0x44+(int)o->entries)+0x2e)=h.seq;
 }
 return 0;
}
