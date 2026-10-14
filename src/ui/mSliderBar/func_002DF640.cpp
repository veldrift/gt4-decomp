/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad[0xE8]; int step; char padEC[0x18]; int vertical; };
struct Event { char pad[0x20]; int key; };
extern "C" int func_002DF9D8(Slider *, int);
extern "C" int func_002DF9F0(Slider *, int);
extern "C" void func_002DF3A0(Slider *, void *, int) throw();
extern "C" int func_002DF640(Slider *self, void *arg, Event *ev) {
 int changed = 0;
 int key = ev->key;
 if (self->vertical == 0) {
  if (key == 0xFF51 || key == 0xFF96) changed = func_002DF9F0(self, self->step);
  else if (key == 0xFF53 || key == 0xFF98) changed = func_002DF9D8(self, self->step);
  if (changed) func_002DF3A0(self, arg, 1);
 } else {
  if (key == 0xFF52 || key == 0xFF97) changed = func_002DF9F0(self, self->step);
  else if (key == 0xFF54 || key == 0xFF99) changed = func_002DF9D8(self, self->step);
  if (changed) func_002DF3A0(self, arg, 1);
 }
 return 1;
}
