/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { volatile int value; volatile unsigned size; };
struct Table { Entry entries[4096]; unsigned capacity, used; };
extern "C" int func_00538BF8(int *, unsigned long);
extern "C" int func_00541208(Table *table, int *out, unsigned size) {
 if (table->capacity >= table->used + size) {
  for (unsigned i=0; i<4096; ++i) {
   Entry *e = &table->entries[i];
   if (!e->value) {
    int result = func_00538BF8(out,size);
    if (result) return 100;
    int value = *out;
    if (!value) return 100;
    e->size=size;
    e->value=value;
    table->used += size;
    return result;
   }
  }
 }
 return 100;
}
