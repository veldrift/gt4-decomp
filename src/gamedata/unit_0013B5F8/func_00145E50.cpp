typedef int s32;
extern "C" s32 func_00441248(s32);
extern "C" s32 func_00445EB0(s32);
extern "C" s32 func_00145EF0(void*);
extern "C" void func_00490A40(s32, s32, s32, s32);
extern "C" char D_0068F4F0[];
extern "C" s32 D_00624984;
struct Car { char pad[0x14]; s32 db; };
extern "C" void func_00145E50(Car *self, s32 arg1, s32 arg2) {
  s32 handle=func_00441248(self->db);
  s32 rc=func_00445EB0(handle);
  if (rc == 0) {
    func_00490A40(D_00624984,arg2,arg1,(s32)D_0068F4F0);
    return;
  }
  func_00490A40(D_00624984,arg2,arg1,func_00145EF0(self));
}
