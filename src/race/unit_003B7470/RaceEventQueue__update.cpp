/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short id; unsigned short time; int value; };
struct Table { int lock[2]; Entry entries[256]; unsigned char refs[0x1c]; int count; };
struct Row { int pad[2]; Entry entry; };
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void RaceEventQueue__remove(void *,int) throw();
extern "C" void RaceEventQueue__update(Table *t) {
 func_00576100(t);
 for(int i=0;i<t->count;i++) {
  Row *p=(Row *)((char *)t+i*8);
  unsigned short old=p->entry.time;
  if(old) {
   if(--p->entry.time==0) {
    RaceEventQueue__remove(t,i--);
   }
  }
 }
 func_00576140(t);
}
