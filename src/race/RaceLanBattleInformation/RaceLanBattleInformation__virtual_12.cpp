struct func_003B4F18_arg1;

struct Obj {
    char pad0[0x14];
    int unk14;
};

extern "C" void RaceEntryCar__setPlayerSpec(Obj *arg0, struct func_003B4F18_arg1 *arg1);
extern "C" void func_005F31C0(Obj *arg0, int arg1);

extern "C" void RaceLanBattleInformation__virtual_12(char *arg0, Obj *arg1) {
    int n = arg1->unk14;
    if (n >= 0 && n < *(int *)(arg0 + 0x118)) {
        return RaceEntryCar__setPlayerSpec(arg1, (struct func_003B4F18_arg1 *)(arg0 + n * 0x190 + 0x130));
    }
    func_005F31C0((Obj *)arg0, n);
}
