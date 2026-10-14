/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad[0xC4]; int c4; char padC8[0x34]; int fc,f100,f104,f108,popup; };
extern "C" void mTextFace__virtual_68(Slider *, void *);
extern "C" void func_00231F60(void *, int);
extern "C" void mSliderBar__virtual_68(Slider *self, void *arg) {
 self->f100 = 0;
 self->fc = 0;
 self->c4 = 0;
 self->popup = 0;
 mTextFace__virtual_68(self, arg);
 func_00231F60(arg, 0);
}
