/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { unsigned short v0,v2,prev,next; };
struct Table { char p0[16]; Entry *entries; unsigned short *count; char p18[8]; unsigned short *flag; };
extern "C" int func_004C3A88(Table *, unsigned short) throw();
extern "C" int func_004C3DA0(Table *t, unsigned short index) {
 if ((unsigned short)(index-1) >= 0x1fff) return -1;
 Entry *e = t->entries + index;
 if (e->prev == 0xffff) return -1;
 *t->flag = 0;
 Entry *prev = t->entries + e->prev;
 prev->next = e->next;
 if (e->next != 0xffff) {
  Entry *next = t->entries + e->next;
  next->prev = e->prev;
 }
 *t->count = *t->count + e->v2 + 1;
 func_004C3A88(t,index);
 return 0;
}
