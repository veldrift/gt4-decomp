struct Device { char pad[0x144]; int mode; char p2[0x10]; int state,pad2; unsigned handle; void *extra; };
struct Report { int size; struct Entry { Device *device; int status; } entries[4]; int error; };
extern Report D_00868820;
extern int D_0086A8C8[4],D_0064B4F0;
extern void *D_0064B4F4;
struct API { int (*op)(Device*,int); char pad[0x14]; int (*test)(Device*); };
struct APIA { char pad[0x24]; unsigned (*op)(unsigned,int); };
struct APIB { char pad[0x40]; int (*op)(void*); };
struct APIC { char pad[0x60]; int (*off)(void*,APIC*); int (*on)(void*,APIC*); };
struct APID { char pad[0x64]; int (*finish)(); };
extern API *D_0064B4AC;
extern APIA *D_0064B4A8;
extern APIB *D_0064B4B8;
extern APIC *D_0064B4BC;
extern APID *D_0064B4B0;
extern "C" Device *func_00535A18(unsigned);
extern "C" int func_00535780(unsigned);
extern "C" void *func_005A48D8(void*,int,unsigned);
inline void init(Report *r,unsigned size) { func_005A48D8(r,0,size); r->size=size; }
inline int modecall(int (*call)(void*,APIC*), void *data, APIC *api) { int e=0; if(call(data,api)) e=37; return e; }
extern "C" int func_00535010(int enable) {
 int err=0, result=0;
 func_005A48D8(D_0086A8C8,0,16);
 init(&D_00868820,40);
 if(D_0064B4F0) {
  if(enable) err=modecall(D_0064B4BC->on,D_0064B4F4,D_0064B4BC);
  else err=modecall(D_0064B4BC->off,D_0064B4F4,D_0064B4BC);
  if(err) { D_00868820.error=err; return err; }
 }
 for(unsigned char i=0;i<4;i++) {
  Device *d=func_00535A18(i);
  D_00868820.entries[i].device=d;
  D_00868820.entries[i].status=0;
  if(!d) continue;
  if((unsigned)(d->mode-1)<2) {
   if(d->state!=2) err=func_00535780(D_0064B4A8->op(d->handle,enable));
   if(d->extra && enable) { err=0; if(D_0064B4B8->op(d->extra)) err=37; }
   if(err) { D_00868820.entries[i].status=err; result=err; continue; }
   if(D_0086A8C8[i]) { D_00868820.entries[i].status=12; result=12; continue; }
  }
  if(D_0064B4AC && D_0064B4AC->test(d)) {
   err=D_0064B4AC->op(d,enable);
   if(err) { D_00868820.entries[i].status=err; result=err; }
  }
 }
 D_0064B4B0->finish();
 return result;
}
