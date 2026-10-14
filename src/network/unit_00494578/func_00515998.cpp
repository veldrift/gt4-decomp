struct Ops { char pad[0x28]; int (*call)(int); };
extern Ops *D_0064B4B4;
extern "C" int func_00535780(unsigned);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);
static inline int unlock() { return func_00535780(func_00536D38()); }
extern "C" int func_00515998(int *out,int arg) {
 int r=func_00535780(func_00536CF8());
 if(r) return r;
 if(!out) return 23;
 *out=D_0064B4B4->call(arg);
 return unlock();
}
