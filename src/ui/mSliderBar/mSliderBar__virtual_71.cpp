/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad[0xC0]; int c0; int c4; char padC8[0x44]; int popup; };
struct Event { char pad[0x20]; int key; };
extern "C" int func_002DF540(Slider *, void *, Event *) throw();
extern "C" int func_002DF640(Slider *, void *, Event *) throw();
extern "C" void func_002DF738(Slider *, void *) throw();
extern "C" void func_002DF7B0(Slider *, void *, int) throw();
extern "C" int mWidget__onKeyPress(Slider *, void *, Event *);
extern "C" int mSliderBar__virtual_71(Slider *self, void *arg, Event *ev) {
 if (self->c0) {
  if (ev->key == 0xFF0D) {
   if (self->popup == 0) func_002DF738(self, arg);
   else func_002DF7B0(self, arg, 0);
   return 1;
  }
  if (ev->key == 0xFF1B && self->popup) { func_002DF7B0(self, arg, 1); return 1; }
 }
 if (self->c0 == 0) return func_002DF540(self, arg, ev);
 if (self->c4 && self->popup) return func_002DF640(self, arg, ev);
 return mWidget__onKeyPress(self, arg, ev);
}
