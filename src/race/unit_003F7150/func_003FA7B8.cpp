/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct E { char pad0[0x89]; u8 type; char pad8a[0x4e]; float value; u8 state; };
extern "C" float func_003FA7B8(char *base, int i) {
 E *p = (E *)(base + i * 0xec + 0x164);
 u8 t = p->type;
 if (t == 1 || t == 10 || t == 11) return 0.0f;
 if ((t == 2 || (t == 3 || (t == 4 || (t == 6 || t == 13)))) || t == 14) return 0.0f;
 float v = 0.0f;
 if (p->state == 2) {
   v = -p->value;
   if (v < 0.5f) v = 0.0f;
   else if (v > 1.0f) v = 1.0f;
 }
 return v;
}
