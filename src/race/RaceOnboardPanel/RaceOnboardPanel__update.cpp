/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Indicator { char pad[0x40]; signed char enabled : 8; };
extern "C" void RaceShiftPositionDisplay__update(void *, float) throw();
extern "C" void RaceShiftTimingLampDisplay__update(void *, float) throw();
extern "C" void RaceSuggestedGearDisplay__virtual_10(void *, float) throw();
extern "C" void RaceDisplayObjectBase__update(void *);
extern "C" void RaceIndicator__virtual_09(void *, float) throw();
extern "C" void RaceOnboardPanel__update(signed char *self, float dt) {
    RaceShiftPositionDisplay__update(self + 0xA20, dt);
    RaceShiftTimingLampDisplay__update(self + 0xAD0, dt);
    RaceSuggestedGearDisplay__virtual_10(self + 0xA78, dt);
    RaceDisplayObjectBase__update(self + 0xB0C);
    Indicator *p = (Indicator *)(self + 0xB3C);
    signed char v_self2 = self[0x1E];
    p->enabled = v_self2;
    RaceIndicator__virtual_09(p, dt);
    Indicator *p2 = (Indicator *)(self + 0xB80);
    signed char v_self3 = self[0x22];
    p2->enabled = v_self3;
    RaceIndicator__virtual_09(p2, dt);
    Indicator *p3 = (Indicator *)(self + 0xBC4);
    signed char v_self = self[0x20];
    p3->enabled = v_self;
    RaceIndicator__virtual_09(p3, dt);
}
