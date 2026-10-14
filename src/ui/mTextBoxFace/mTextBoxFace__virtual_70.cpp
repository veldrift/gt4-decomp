/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad1[0x124];
    int i124; int i128;
    char pad2[0x32C - 0x12C];
    signed char tab[0x80];
    int i3AC; int i3B0; float f3B4; int i3B8; float f3BC; int i3C0; int i3C4;
};
extern void *PDISTD__global_font_manager;
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" void func_002472B8(void *, void *);
extern "C" void func_00247428(void *);
extern "C" float mWidget__getWindowH(void *);
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" int func_002E57D8(O *, int *, int, int) throw();
extern "C" int func_002E5810(O *) throw();
extern "C" void func_002E5E68(O *) throw();
extern "C" void func_002E6008(O *, float) throw();
extern "C" float func_00490830(void *);
extern "C" void mTextBoxFace__virtual_70(O *o, void *a1, int a2)
{
    int sp0;
    mWidget__virtual_70(o, a1, 0);
    if (a2 != 0) {
        char *s5 = (char *)o + 0xC0;
        int s4 = func_002E5810(o);
        func_00231C10(a1);
        func_002472B8(s5, a1);
        sp0 = o->i124;
        int s0 = 0;
        if (sp0 != o->i128) {
            do {
                s0 += o->tab[sp0];
                func_002E57D8(o, &sp0, 0x80, 1);
            } while (sp0 != o->i128);
        }
        o->i3AC = s0;
        float f = mWidget__getWindowH(o);
        o->i3B0 = (int)(f / func_00490830(PDISTD__global_font_manager));
        float g = mWidget__getWindowH(o);
        o->f3B4 = g - (float)o->i3B0 * func_00490830(PDISTD__global_font_manager);
        switch (o->i3B8) {
        case 0:
            func_002E5E68(o);
            break;
        case 1:
            o->f3BC = o->f3BC + (float)s4;
            if (o->i3C4 != 0) {
                o->i3C0 = o->i3C0 + s4;
            }
            func_002E6008(o, mWidget__getWindowH(o));
            break;
        }
        func_00247428(s5);
        func_00231C48(a1);
    }
}
