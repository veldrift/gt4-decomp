/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table { unsigned char pad; unsigned char count; char pad2[0x12]; unsigned char ids[1]; };
struct Entry { char pad[0xc]; float c; float base; char pad2[0x58-0x14]; };
struct Data { char pad[0x2c4]; float a[6]; float b[6]; char pad2[0x14]; Entry entries[1]; };
struct Obj { char pad[0x10]; Data *p; };
extern "C" Table *func_00359510(Data *);
extern "C" float func_003696C8(Obj *self, int i) {
    Data *data = self->p;
    Table *t = func_00359510(data);
    unsigned char k = 0;
    if (i < t->count) k = t->ids[i];
    Entry *e = &data->entries[k];
    return (-e->base - (data->a[k] - data->b[k])) + e->c;
}
