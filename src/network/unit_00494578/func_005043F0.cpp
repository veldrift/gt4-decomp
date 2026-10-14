/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { void *ptr; int size; };
struct Packet { Entry entries[8]; int size,count; Packet(){size=0;count=0;} void add(void *p,int n){entries[count].ptr=p;entries[count].size=n;size+=n;count++;} };
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" int func_00529770(void*,void*,unsigned,void*);
struct Guard { int handle; Guard(int h){handle=h;func_00576788(h);} ~Guard(){func_005767C0(handle);} };
struct Inner { char pad[12]; void *c; void *d; };
struct Self { int semaphore; Inner *inner; };
extern "C" int func_005043F0(Self *s,void *p,int n) {
 Inner *inner=s->inner;
 Guard guard(s->semaphore);
 Packet packet;
 packet.add(p,n);
 return func_00529770(inner->c,inner->d,0x7000,&packet)==0;
}
