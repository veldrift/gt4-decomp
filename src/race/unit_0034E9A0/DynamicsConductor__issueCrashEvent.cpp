struct Cfg { char p[0x48]; float m48; };
struct W { char p[0x466]; signed char m466; unsigned char m467; char p1[0x4B2 - 0x468]; unsigned char m4B2; char p2[0x62E - 0x4B3]; unsigned char m62E; };
struct Car { char p[0x10]; Cfg *cfg; char p1[0x104 - 0x14]; W w; };
struct Self { char p[0xF860]; unsigned char mF860, mF861, mF862; };
extern "C" int func_0035FBC8(unsigned);
extern "C" int func_0035FC10(int, float);
extern "C" void AutomobileSetCrashPenalty(W *, int);
extern "C" unsigned short AutomobileGetCrashPenalty(W *);
extern "C" void DynamicsConductor__issueCrashEvent(Self *self, Car *car, int k, unsigned a3, float f)
{
    W *w = &car->w;
    if (w->m466 == 0 && w->m467 == 0 && w->m4B2 == 0) {
        unsigned char p = self->mF862;
        if (p != 0) {
            if (p == 0xFF) {
                if (w->m62E) return;
            } else if (AutomobileGetCrashPenalty(w) != 0) {
                return;
            }
            int r = 0;
            switch (k) {
            case 0:
                if (func_0035FBC8(a3) < 3)
                    r = func_0035FC10(self->mF861, f / car->cfg->m48);
                break;
            case 1:
                if (func_0035FBC8(a3) < 3)
                    r = func_0035FC10(self->mF860, f * 100.0f);
                break;
            case 2:
                break;
            }
            if (r) {
                if (p == 0xFF) {
                    w->m62E = 1;
                    return;
                }
                return AutomobileSetCrashPenalty(w, p);
            }
        }
    }
}
