/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0x1c]; virtual ~Base(); };
struct Elem : Base {
 int extra;
 Elem() __asm__("func_004628C8");
 virtual ~Elem();
};
struct One { Elem a[1]; };
struct Five { Elem a[5]; };
extern One D_00623A50;
extern Five D_008485C0;
inline void *operator new(unsigned int, void *p) { return p; }
static inline void initOne(int init) { if(init == 1) new (&D_00623A50) One; }
static inline void initFive(int init) { if(init == 1) new (&D_008485C0) Five; }
extern "C" void func_00463600(int init, int prio) {
 if(prio == 0xFFFF) {
  initOne(init);
  initFive(init);
 }
 if(prio == 0xFFFF && init == 0) D_008485C0.~Five();
 if(prio == 0xFFFF && init == 0) D_00623A50.~One();
}
