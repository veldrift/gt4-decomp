struct func_003B4F18_arg1;

struct Obj {
    char pad0[0x14];
    unsigned int unk14;
};

extern "C" void RaceEntryCar__setPlayerSpec(Obj *arg0, struct func_003B4F18_arg1 *arg1);
extern "C" void RaceBattleInformationT_2__addEnemy(Obj *arg0, int arg1);

extern "C" void RaceSplitBattleInformation__updateEntryCar(char *arg0, Obj *arg1) {
    unsigned int n = arg1->unk14;
    if (n < 2) {
        return RaceEntryCar__setPlayerSpec(arg1, (struct func_003B4F18_arg1 *)(arg0 + n * 0x190 + 0x130));
    }
    RaceBattleInformationT_2__addEnemy((Obj *)arg0, (int)n);
}
