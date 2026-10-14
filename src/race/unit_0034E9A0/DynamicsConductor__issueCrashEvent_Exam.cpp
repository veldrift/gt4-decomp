struct Cfg { char p[0x48]; float m48; };
struct W { char p[0x466]; signed char m466; unsigned char m467; char p1[0x4B2 - 0x468]; unsigned char m4B2; unsigned char m4B3; };
struct Car { char p[0x10]; Cfg *cfg; char p1[0x104 - 0x14]; W w; };
struct Self { char p[0xF860]; unsigned char mF860, mF861; };
extern "C" int DynamicsConductor__GetNumberOfPylonsToBeTouched(Self *);
extern "C" void func_0035DF28(Self *);
extern "C" int func_0035FBC8(int);
extern "C" int func_0035FC10(int, float);
extern "C" void DynamicsConductor__issueCrashEvent_Exam(Self *self, Car *car, int k, int a3, float f)
{
    W *w = &car->w;
    if (w->m466 == 0 && w->m467 == 0 && w->m4B2 == 0) {
        int r = 0;
        switch (k) {
        case 0:
            r = func_0035FC10(self->mF861, f / car->cfg->m48);
            break;
        case 1:
            if (func_0035FBC8(a3) < 3)
                r = func_0035FC10(self->mF860, f * 100.0f);
            break;
        case 2:
            if (DynamicsConductor__GetNumberOfPylonsToBeTouched(self) > 0)
                func_0035DF28(self);
            else
                r = 1;
            break;
        }
        if (r) w->m4B3 |= 1;
    }
}
