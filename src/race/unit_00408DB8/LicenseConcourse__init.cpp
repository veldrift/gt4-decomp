/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char p0[4]; int f4; int f8; int fC; int f10; };
struct LC {
    char p0[4];
    Sub *f4;
    char p8[0xC];
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    char p2C[0x10];
    char m3C[0x3C];
    int f78;
    int f7C;
    int f80;
};
struct Player { char p[0x10]; };
extern "C" int func_0034C190(int, int);
extern "C" unsigned short RaceCourse__getSectionStopCount(char *);
extern "C" void Concourse__init(LC *, int) throw();
extern "C" void func_00408268(LC *, int, const char *) throw();
extern "C" void LicenseConcourse__Camera__init(void *, int, int) throw();
extern "C" void func_00408DB8(LC *, int, char *, int) throw();
extern "C" void func_00408EE0(LC *, int) throw();
extern "C" void func_00408F38(LC *, float) throw();
extern "C" Player *func_00427820(Player *);
extern "C" void GT4_Motion__MotionSetPlayer__set(Player *, int, int);
extern "C" int GT4_Motion__MotionSetPlayer__getSkinningBufferSize(Player *);
extern "C" int func_00575E60(int, int);

extern "C" void LicenseConcourse__init(LC *self, int arg1, char *arg2) {
    Player pl;
    Concourse__init(self, 3);
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    LicenseConcourse__Camera__init(self->m3C, self->f4->f8, 0);
    self->f78 = 0;
    self->f7C = 0;
    int n = RaceCourse__getSectionStopCount(arg2);
    if (n > 0) {
        self->f18 = 1;
        if (n >= 2) {
            func_00408DB8(self, 1, arg2, func_0034C190(arg1, 0));
            self->f1C = 1;
        } else {
            func_00408DB8(self, 0, arg2, func_0034C190(arg1, 0));
        }
        func_00408F38(self, 0.94f);
        func_00408EE0(self, -1);
        func_00408268(self, 0, "license_stand_master");
        func_00408268(self, 1, "license_stand_staff_1");
        func_00408268(self, 2, "license_stand_staff_2");
        if (self->f80 == 0) {
            func_00427820(&pl);
            GT4_Motion__MotionSetPlayer__set(&pl, self->f4->fC, self->f4->f4);
            int a = GT4_Motion__MotionSetPlayer__getSkinningBufferSize(&pl);
            GT4_Motion__MotionSetPlayer__set(&pl, self->f4->f10, self->f4->f4);
            int b = GT4_Motion__MotionSetPlayer__getSkinningBufferSize(&pl);
            self->f80 = func_00575E60(0x40, b < a ? a : b);
        }
    }
}
