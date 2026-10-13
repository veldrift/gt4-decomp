typedef int s32;
typedef long long s64;

struct Database;
extern Database D_006235A8;

extern "C" s64 func_00443E00(Database *db, int key, int type);
extern "C" s32 func_00444440(void *self, s64 v);

extern "C" s32 func_004443A8(void *arg0, int arg1) {
    s64 v = func_00443E00(&D_006235A8, arg1, 0);
    if (v == -1) {
        v = func_00443E00(&D_006235A8, arg1, 0x26);
        if (v == -1) {
            return 0;
        }
    }
    return func_00444440(arg0, v);
}
