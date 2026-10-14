struct Entry { char flag; char pad[0x43]; };
struct G { char pad[0x110]; Entry *entries; };
extern G D_00854038;
extern "C" char *func_005316F8(unsigned int);
extern "C" Entry *func_00515EE8(unsigned int index) {
 if (index < 512) {
  if (!D_00854038.entries) {
   D_00854038.entries = (Entry *)func_005316F8(0x8800);
   if (!D_00854038.entries) return 0;
   for (unsigned int i = 0; i < 512; i++) D_00854038.entries[i].flag = 0;
  }
  return D_00854038.entries + index;
 }
 return 0;
}
