/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int m0; char pad[0x90]; int m94; };
struct B { int m0,m4; };
extern "C" int func_004EF730(O *, int, int, void *, int);
extern "C" int func_004EEAB0(O *o, B *buf) {
 if (o->m0 == 0) return 0;
 if (func_004EF730(o, o->m94, 9, buf, 16) < 0) return 0;
 return buf->m4 != 0;
}
