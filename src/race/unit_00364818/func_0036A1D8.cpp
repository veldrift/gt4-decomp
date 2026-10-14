/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { unsigned char pad,n; char gap[0x12]; unsigned char indices[1];
 int count() { return n; }
 int index(int i) { return i < count() ? indices[i] : 0; }
};
struct Entry { float value; char pad[0x54]; };
struct Data { char pad[0x300]; Entry entries[1]; };
struct Table { char pad[12]; Data data; };
struct Obj { char pad[0x10]; Table *table; char gap[0x500]; float values[1]; };
extern "C" Info *func_00359510(Table *);
extern "C" int func_0036A1D8(Obj *p, int mask) {
 Table *table = p->table;
 Info *info = func_00359510(table);
 int bit = 1;
 for (int i = 0; i < info->count(); i++) {
  float value = p->values[i];
  int index = info->index(i);
  Data *data = &table->data;
  if (value < data->entries[index].value) mask |= bit;
  bit <<= 1;
 }
 return mask;
}
