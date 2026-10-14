/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0x48]; virtual ~Base(); };
struct Elem : Base {
 Elem() __asm__("func_00500DD8");
 virtual ~Elem();
};
struct Holder { Elem a[8]; };
extern Holder D_00649548;
inline void *operator new(unsigned int,void *p) { return p; }
extern "C" void func_00503390(int init,int prio) {
 if(prio==0xFFFF) {
  if(init==1) new (&D_00649548) Holder;
 }
 if(prio==0xFFFF && init==0) D_00649548.~Holder();
}
