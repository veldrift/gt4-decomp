typedef int s32;
typedef long long s64;

struct Database;
extern Database D_006235A8;

extern "C" s64 func_00443E00(Database *db, int key, int type);
extern "C" s32 func_00448A58(s64 id, void *out);

extern "C" s32 func_004489B0(int arg0, void *arg1) {
    s64 v = func_00443E00(&D_006235A8, arg0, 0);
    if (v == -1) {
        v = func_00443E00(&D_006235A8, arg0, 0x26);
        if (v == -1) {
            return 0;
        }
    }
    return func_00448A58(v, arg1);
}
