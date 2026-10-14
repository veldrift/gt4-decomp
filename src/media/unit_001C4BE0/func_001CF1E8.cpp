/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { long id; char rest[0xE0]; };
struct Obj { char pad[0x68]; Blob data; };
extern "C" void func_004481B8(long, char*);
extern "C" void func_001CF1E8(Obj *o, const Blob *b) {
 o->data=*b;
 func_004481B8(o->data.id,(char*)o+0xF8);
}
