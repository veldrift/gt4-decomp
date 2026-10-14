struct Entry { int off; char pad[8]; int type; };
struct Buffer { char pad[0x20]; Entry *entries[64]; int addresses[64]; };
struct Out { int x, count; Buffer data; };
struct Table { int x, count; char pad[0x20]; Entry *entries[64]; };
extern char *D_0064B4B4;
extern "C" void func_0051B448(Out *out, Table *tab, int base) {
 if (out && tab) {
  int i = 0;
  if (tab->count > 0) {
   do {
    Entry *e = tab->entries[i];
    int type = e->type;
    if (type >= 16) {
     if (out->count >= 64) break;
     func_0051B448(out, (Table *)(D_0064B4B4 + type * 0x228 + 0x6078), base + e->off);
    } else {
     out->data.addresses[out->count] = base + e->off;
     int n = out->count;
     out->count = n + 1;
     out->data.entries[n] = e;
    }
    ++i;
   } while (i < tab->count);
  }
 }
}
