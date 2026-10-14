/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry {
    char pad0[0x10];
    Entry *next;
    s32 idx;
};

struct Sub {
    char pad0[0x14];
    Entry *head;
};

extern "C" void RaceEntryBase__sortByRank(Sub *);
extern "C" void ResultArcade__setPlayerRank(void *, s32) throw();
extern "C" void ResultArcade__setCarName(void *, s32, Entry *);
extern "C" void ResultArcade__setCarIconNumber(void *, s32, s32);

extern "C" void func_003DFAE0(void *arg0, void *arg1) {
    char *self = (char *)arg0;
    s32 var_s3;
    Entry *var_s0 = (Entry *)arg1;
    char *var_s2;
    if (*(s32 *)(self + 0x48) == 0) {
        if (*(s32 *)self != 0) {
            var_s3 = 0;
            RaceEntryBase__sortByRank(*(Sub **)((char *)var_s0 + 0x60));
            var_s0 = (*(Sub **)((char *)var_s0 + 0x60))->head;
            if (var_s0 != 0) {
                s32 *s4 = (s32 *)(self + 4);
                var_s2 = self + 0x68;
                do {
                    s32 a2 = var_s0->idx;
                    if (*(s32 *)((char *)(s4 + a2) + 0x10) == 0) {
                        if (*(s32 *)var_s2 != a2) {
                            ResultArcade__setCarIconNumber(arg0, var_s3, a2);
                            ResultArcade__setCarName(arg0, var_s3, var_s0);
                        }
                        if (var_s0->idx == *s4) {
                            ResultArcade__setPlayerRank(arg0, var_s3);
                        }
                    }
                    var_s0 = var_s0->next;
                    var_s2 += 0xC0;
                    var_s3 += 1;
                } while (var_s0 != 0);
            }
        }
    }
}
