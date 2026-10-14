struct Camera { virtual void dummy(); virtual void first(float); virtual void second(float); };
struct S { char pad[0x64]; char *vt; };
struct REntry { short delta,index; Camera *(*fn)(void *); };
extern "C" int func_003C75D8(void *) throw();
extern "C" int func_003405E8(int,float);
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" int func_003C7838(S *s) {
 float z=0.0f;
 REntry *r=(REntry *)(s->vt+0x4B0);
 Camera *p=r->fn((char *)s+r->delta);
 RaceEntryCar__update(1);
 func_004A53F8();
 func_004A7454();
 p->first(z);
 RaceEntryCar__update(0);
 func_004A53F8();
 func_004A7454();
 p->second(z);
 int ret=func_003405E8(func_003C75D8(s),z);
 func_004A5400();
 RaceEntryCar__update(1);
 func_004A5400();
 RaceEntryCar__update(0);
 return ret;
}
