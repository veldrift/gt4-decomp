struct Dst { char pad[0x38CC0]; char c[3]; };
struct Buf { int a; int b; int c; };
extern "C" void func_00472528(Buf *, int);
extern Buf PDISTD__UNIT_MANAGER;
extern int PDISTD__LOCALE;
extern Dst *D_00622F4C;
static inline void put(char *p, int v) { *p = (char)(v & 0xFF) ; }
extern "C" void func_004361D0() {
    func_00472528(&PDISTD__UNIT_MANAGER, PDISTD__LOCALE);
    put(&D_00622F4C->c[0], PDISTD__UNIT_MANAGER.a);
    put(&D_00622F4C->c[1], PDISTD__UNIT_MANAGER.b);
    put(&D_00622F4C->c[2], PDISTD__UNIT_MANAGER.c);
}
