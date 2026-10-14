/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char p[0x15]; char text[0x13]; int v28; short v2C,v2E; };
struct Obj { char p[0x40]; int v40; char p44[0x564]; Sub *s; char p5AC[0x54C]; char text[0x11]; };
extern "C" int func_004F0C88(Obj *) throw();
extern "C" void func_004F0CD0(Obj *,int) throw();
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern "C" void func_004F5318(Obj *o,int a,int b) {
 if (func_004F0C88(o)) {
  func_005A48D8(o->s,0,0x30);
  Sub *s=o->s;
  func_005A6AB0(s->text,o->text,0x11);
  s->v28=o->v40;
  if (b>=0x11) b=0x10;
  s->v2C=a;
  s->v2E=b;
  return func_004F0CD0(o,0x28);
 }
}
