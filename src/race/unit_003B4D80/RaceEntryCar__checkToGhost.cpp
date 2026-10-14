extern "C" void RaceEntryCar__copyVehicleModel(void*,void*);
extern "C" int RaceEntryCar__checkToGhost(char*s){void*p=*(void**)(s+0x2884);if(!p)return 0;RaceEntryCar__copyVehicleModel(s,p);*(int*)(s+0x2888)=1;*(void**)(s+0x2884)=0;return 1;}
