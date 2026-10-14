/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int w[5]; };
extern Blk D_0069F788;
struct Elem { char pad[0x128]; unsigned char id; };
struct Arg { Elem *e; };
extern "C" int func_00364E28(Arg *a) {
 Elem *e = a->e;
 Blk b = D_0069F788;
 return b.w[e->id];
}
