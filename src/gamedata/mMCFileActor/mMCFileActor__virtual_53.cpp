#include "types.h"
struct Part { char pad[4]; s32 unk4; };
struct mMCFileActor_00173728 { char pad0[0x40]; Part sub40; };
struct D_0061850C_00173728 { char pad0[0x78]; s32 unk78; };
extern D_0061850C_00173728 D_0061850C;
struct CopyObj { s32 data[15]; };
extern "C" void pglPushAttrib(s32);
extern "C" CopyObj *func_00105378(CopyObj *, const CopyObj *);
extern "C" s32 func_00105528(void *);
extern "C" void func_00105AD8(void *, void *, s32, s32);
extern "C" void func_001056A0(void *);
extern "C" void func_004A53F8();
extern "C" void mMCFileActor__virtual_53(mMCFileActor_00173728 *self) {
    pglPushAttrib(1);
    CopyObj *obj = (CopyObj *)((char *)self + 0x40);
    CopyObj *record = (CopyObj *)((char *)&D_0061850C + D_0061850C.unk78 * 0x3C);
    func_00105378(obj, record);
    ((Part *)obj)->unk4 = 1;
    func_00105528(obj);
    func_00105AD8(obj, record, 0, 0);
    func_001056A0(obj);
    func_004A53F8();
}
