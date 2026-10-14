/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { unsigned char enabled,b1,b2,b3; short x,y,w,h; float alpha; void *tex; };
struct Self { char b[12]; float alpha; char p10[9]; unsigned char show,boost,b1b,offset; char p1d[31]; short boostx; };
extern "C" {
void RaceDigitalSpeedmeter__render_main(Obj *) throw();
void RaceOdometer__render_main(Obj *) throw();
void RaceTexturePanel__render_main(Obj *) throw();
void RaceTireWearDisplay__render_main(Obj *,int) throw();
int RaceIndicator__render_main(Obj *) throw();
void RaceShiftPositionDisplay__render_main(Obj *) throw();
void RaceSuggestedGearDisplay__render_main(Obj *) throw();
void RaceShiftTimingLampDisplay__render_main(Obj *) throw();
void func_003A8968(Self *);
void RaceOnboardPanel__init_texset(Self *);
void RaceSideGravityMeter__render_main(Obj *);
void RaceDisplayObjectBase__setLocation(Obj *,int,int);
void RaceRoundMeterBase__virtual_05(Obj *,int);
void RaceRoundMeterBase__virtual_15(Obj *);
void RaceOnboardTachometer__virtual_05(Obj *,int);
void RaceOnboardTachometer__virtual_15(Obj *);
void RaceBoostmeter__virtual_05(Obj *,int);
}
extern "C" void RaceOnboardPanel__render_main(Self *o,int frame) {
 Obj *panel=(Obj *)((char *)o+0x50);
 if (!panel->tex) RaceOnboardPanel__init_texset(o);
 Obj *odo=(Obj *)((char *)o+0x9c0);
 Obj *round=(Obj *)((char *)o+0x6c);
 Obj *tach=(Obj *)((char *)o+0xc8);
 panel->alpha=o->alpha;
 Obj *boost=(Obj *)((char *)o+0x964);
 Obj *speed=(Obj *)((char *)o+0x9e8);
 Obj *gear=(Obj *)((char *)o+0xa20);
 Obj *tires=(Obj *)((char *)o+0xb0c);
 Obj *suggest=(Obj *)((char *)o+0xa78);
 Obj *lamp=(Obj *)((char *)o+0xad0);
 Obj *gravity=(Obj *)((char *)o+0xc24);
 Obj *ind1=(Obj *)((char *)o+0xb3c);
 round->alpha=o->alpha;
 Obj *ind2=(Obj *)((char *)o+0xb80);
 Obj *ind3=(Obj *)((char *)o+0xbc4);
 Obj *last=(Obj *)((char *)o+0xc08);
 tach->alpha=o->alpha;
 boost->alpha=o->alpha;
 odo->alpha=o->alpha;
 speed->alpha=o->alpha;
 gear->alpha=o->alpha;
 suggest->alpha=o->alpha;
 lamp->alpha=o->alpha;
 tires->alpha=o->alpha;
 ind1->alpha=o->alpha;
 ind2->alpha=o->alpha;
 ind3->alpha=o->alpha;
 last->alpha=o->alpha;
 gravity->alpha=o->alpha;
 RaceTexturePanel__render_main(panel);
 RaceRoundMeterBase__virtual_05(round,frame);
 RaceOnboardTachometer__virtual_05(tach,frame);
 if (o->show) RaceOdometer__render_main(odo);
 RaceShiftTimingLampDisplay__render_main(lamp);
 RaceRoundMeterBase__virtual_15(round);
 RaceOnboardTachometer__virtual_15(tach);
 if (o->boost) {
  int x=o->boostx;
  if (o->offset) x+=8;
  RaceDisplayObjectBase__setLocation(boost,x,boost->y);
  RaceBoostmeter__virtual_05(boost,frame);
  RaceRoundMeterBase__virtual_15(boost);
 }
 RaceShiftPositionDisplay__render_main(gear);
 if (suggest->enabled) RaceSuggestedGearDisplay__render_main(suggest);
 RaceDigitalSpeedmeter__render_main(speed);
 if (o->show) {
  RaceTireWearDisplay__render_main(tires,frame);
  RaceIndicator__render_main(ind3);
  RaceIndicator__render_main(ind1);
  RaceIndicator__render_main(ind2);
 }
 RaceTexturePanel__render_main(last);
 if (gravity->enabled) RaceSideGravityMeter__render_main(gravity);
 func_003A8968(o);
}
