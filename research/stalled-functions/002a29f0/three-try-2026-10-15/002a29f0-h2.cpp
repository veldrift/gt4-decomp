/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef char undefined;
typedef unsigned char undefined1;
typedef int undefined4;
typedef unsigned int undefined8;
typedef unsigned int uint;
typedef unsigned int u32;
typedef int s32;
typedef signed char s8;
union PtrF32 { void *p; float f; };
struct ReaderCallback { void *vtable; void *value; };
struct VecScratch {
    union {
        struct { PtrF32 x, y; } words;
        struct { float x, y; } floats;
        ReaderCallback callback;
    };
};
struct Rep { u32 len, res, ref, selfish; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern s32 D_00659FB0, D_00659FB4;
extern char D_00659FB8[];
extern char D_00666CF0[], D_00666D50[], D_0066CC48[];
extern char D_0069B770[], D_0069B790[], D_0069B798[], D_0069B7A8[];
extern char D_0069B7F0[], D_0069B800[], D_0069B810[];
extern "C" s32 mColorFace__virtual_61(void *, void *);
extern "C" s32 func_0020FD38(void *, void *, void *);
extern "C" void func_0020FCE0(void *, s32);
extern "C" void *func_0020FE28(void *, void *, void *);
extern "C" s32 MVectorReader__structor_0(void *, s32);
extern "C" void MVectorReader__structor_1(void *, s32);
extern "C" void func_002A35F8(void *, void *);
extern "C" void func_002A39F0(void *, s32, s32);
extern "C" void func_002A3A30(void *, s32, s32);
extern "C" void func_00326798(void *, u32, u32, const char *);
extern "C" void func_00575DA0(void *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(Rep *r) { deallocate(r, sizeof(Rep) + r->res); }
static inline void release(Rep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(void *p) { release((Rep *)p - 1); }

s32 func_002A29F0(void *param_1, void *param_2)

{
  int iVar1;
  const char **puVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined *puVar7;
  undefined *apuStack_110 [4];
  struct Header { undefined *tag; int *begin; undefined4 *end; undefined4 capacity; } header;
  ReaderCallback cb_string;
  int aiStack_e0 [4];
  int aiStack_d0 [4];
  VecScratch vec_c0bc;
  struct ListCallback { undefined *tag; undefined **value; } listCallback;
  VecScratch vec_a0_9c;
  undefined1 auStack_90 [16];
  undefined *apuStack_80 [4];
  undefined1 auStack_70 [16];
  undefined4 *puStack_60;
  
  lVar4 = mColorFace__virtual_61(param_1, param_2);
  if (lVar4 == 0) {
    if (D_00659FB4 == 0) {
      apuStack_110[0] = D_00659FB8;
      D_00659FB0 = D_00659FB0 + 1;
    }
    else {
      apuStack_110[0] = (undefined *)func_005C2560(&D_00659FA8);
    }
    if (D_00659FB4 == 0) {
      header.tag = D_00659FB8;
      D_00659FB0 = D_00659FB0 + 1;
    }
    else {
      header.tag = (undefined *)func_005C2560(&D_00659FA8);
    }
    uVar5 = func_0057F260(D_0069B770);
    func_005C2630(&header.tag,0,0xffffffffffffffff,D_0069B770,uVar5);
    cb_string.vtable = D_00666CF0;
    cb_string.value = apuStack_110;
    lVar4 = func_0020FD38(param_2,&header.tag,&cb_string);
    cb_string.vtable = D_00666CF0;
    func_0020FCE0(&cb_string,0);
    destroy(header.tag);
    if (lVar4 == 0) {
      if (D_00659FB4 == 0) {
        header.tag = D_00659FB8;
        D_00659FB0 = D_00659FB0 + 1;
      }
      else {
        header.tag = (undefined *)func_005C2560(&D_00659FA8);
      }
      uVar5 = func_0057F260(D_0069B790);
      func_005C2630(&header.tag,0,0xffffffffffffffff,D_0069B790,uVar5);
      vec_c0bc.words.y.p = aiStack_d0;
      vec_c0bc.words.x.p = D_00666D50;
      lVar4 = func_0020FD38(param_2,&header.tag,&vec_c0bc.callback);
      vec_c0bc.words.x.p = D_00666D50;
      func_0020FCE0(&vec_c0bc.callback,0);
      destroy(header.tag);
      iVar3 = (int)param_1;
      if (lVar4 == 0) {
        if (D_00659FB4 == 0) {
          vec_c0bc.words.x.p = D_00659FB8;
          D_00659FB0 = D_00659FB0 + 1;
        }
        else {
          vec_c0bc.words.x.p = (undefined *)func_005C2560(&D_00659FA8);
        }
        uVar5 = func_0057F260(D_0069B798);
        func_005C2630(&vec_c0bc.callback,0,0xffffffffffffffff,D_0069B798,uVar5);
        header.tag = D_00666D50;
        header.begin = aiStack_d0;
        lVar4 = func_0020FD38(param_2,&vec_c0bc.callback,&header.tag);
        header.tag = D_00666D50;
        func_0020FCE0(&header.tag,0);
        destroy(vec_c0bc.words.x.p);
        if (lVar4 == 0) {
          if (D_00659FB4 == 0) {
            vec_c0bc.words.x.p = D_00659FB8;
            D_00659FB0 = D_00659FB0 + 1;
          }
          else {
            vec_c0bc.words.x.p = (undefined *)func_005C2560(&D_00659FA8);
          }
          uVar5 = func_0057F260(D_0069B7A8);
          func_005C2630(&vec_c0bc.callback,0,0xffffffffffffffff,D_0069B7A8,uVar5);
          header.tag = D_00666D50;
          header.begin = aiStack_d0;
          lVar4 = func_0020FD38(param_2,&vec_c0bc.callback,&header.tag);
          header.tag = D_00666D50;
          func_0020FCE0(&header.tag,0);
          destroy(vec_c0bc.words.x.p);
          if (lVar4 == 0) {
            header.begin = (undefined4 *)0x0;
            header.end = (undefined4 *)0x0;
            header.capacity = 0;
            if (D_00659FB4 == 0) {
              vec_c0bc.words.x.p = D_00659FB8;
              D_00659FB0 = D_00659FB0 + 1;
            }
            else {
              vec_c0bc.words.x.p = (undefined *)func_005C2560(&D_00659FA8);
            }
            uVar5 = func_0057F260(D_0069B7F0);
            func_005C2630(&vec_c0bc.callback,0,0xffffffffffffffff,D_0069B7F0,uVar5);
            listCallback.tag = D_0066CC48;
            listCallback.value = &header.tag;
            lVar4 = func_0020FD38(param_2,&vec_c0bc.callback,&listCallback.tag);
            listCallback.tag = D_0066CC48;
            func_0020FCE0(&listCallback.tag,0);
            destroy(vec_c0bc.words.x.p);
            if (lVar4 == 0) {
              if (D_00659FB4 == 0) {
                vec_a0_9c.words.x.p = D_00659FB8;
                D_00659FB0 = D_00659FB0 + 1;
              }
              else {
                vec_a0_9c.words.x.p = (undefined *)func_005C2560(&D_00659FA8);
              }
              uVar5 = func_0057F260(D_0069B800);
              func_005C2630(&vec_a0_9c.callback,0,0xffffffffffffffff,D_0069B800,uVar5);
              MVectorReader__structor_0(auStack_90,(s32)&vec_c0bc.floats.x);
              lVar4 = func_0020FD38(param_2,&vec_a0_9c.callback,auStack_90);
              MVectorReader__structor_1(auStack_90,2);
              destroy(vec_a0_9c.words.x.p);
              if (lVar4 == 0) {
                if (D_00659FB4 == 0) {
                  apuStack_80[0] = D_00659FB8;
                  D_00659FB0 = D_00659FB0 + 1;
                }
                else {
                  apuStack_80[0] = (undefined *)func_005C2560(&D_00659FA8);
                }
                uVar5 = func_0057F260(D_0069B810);
                func_005C2630(apuStack_80,0,0xffffffffffffffff,D_0069B810,uVar5);
                MVectorReader__structor_0(auStack_70,(s32)&vec_a0_9c.floats.x);
                lVar4 = func_0020FD38(param_2,apuStack_80,auStack_70);
                MVectorReader__structor_1(auStack_70,2);
                destroy(apuStack_80[0]);
                if (lVar4 == 0) {
                  puStack_60 = header.begin;
                  for (piVar6 = header.begin; piVar6 != header.end; piVar6 = piVar6 + 2) {
                  }
                  if (header.begin != (undefined4 *)0x0) {
                    func_00575DA0(header.begin);
                  }
                  destroy(apuStack_110[0]);
                  return 0;
                }
                func_002A3A30(param_1,(int)vec_a0_9c.floats.x,(int)vec_a0_9c.floats.y);
                puStack_60 = header.begin;
                for (piVar6 = header.begin; piVar6 != header.end; piVar6 = piVar6 + 2) {
                }
                if (header.begin != (undefined4 *)0x0) {
                  func_00575DA0(header.begin);
                }
                puVar7 = apuStack_110[0] + -0x10;
                iVar3 = *(int *)(apuStack_110[0] + -8);
                *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
                if (iVar3 + -1 == 0) {
                  iVar3 = *(int *)(apuStack_110[0] + -0xc);
                  puVar2 = (const char **)func_005C11A8();
                  func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
                  return 1;
                }
              }
              else {
                func_002A39F0(param_1,(int)vec_c0bc.floats.x,(int)vec_c0bc.floats.y);
                puStack_60 = header.begin;
                for (piVar6 = header.begin; piVar6 != header.end; piVar6 = piVar6 + 2) {
                }
                if (header.begin != (undefined4 *)0x0) {
                  func_00575DA0(header.begin);
                }
                puVar7 = apuStack_110[0] + -0x10;
                iVar3 = *(int *)(apuStack_110[0] + -8);
                *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
                if (iVar3 + -1 == 0) {
                  iVar3 = *(int *)(apuStack_110[0] + -0xc);
                  puVar2 = (const char **)func_005C11A8();
                  func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
                  return 1;
                }
              }
            }
            else {
              *(int *)(iVar3 + 0xcc) = *header.begin;
              *(int *)(iVar3 + 0xd0) = header.begin[1];
              *(int *)(iVar3 + 0xd4) = header.begin[2];
              *(int *)(iVar3 + 0xd8) = header.begin[3];
              *(int *)(iVar3 + 0xdc) = header.begin[4];
              *(int *)(iVar3 + 0xe0) = header.begin[5];
              *(int *)(iVar3 + 0xe4) = header.begin[6];
              puStack_60 = header.begin;
              *(int *)(iVar3 + 0xe8) = header.begin[7];
              for (piVar6 = header.begin; piVar6 != header.end; piVar6 = piVar6 + 2) {
              }
              if (header.begin != (undefined4 *)0x0) {
                func_00575DA0(header.begin);
              }
              puVar7 = apuStack_110[0] + -0x10;
              iVar3 = *(int *)(apuStack_110[0] + -8);
              *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
              if (iVar3 + -1 == 0) {
                iVar3 = *(int *)(apuStack_110[0] + -0xc);
                puVar2 = (const char **)func_005C11A8();
                func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
                return 1;
              }
            }
          }
          else {
            puVar7 = apuStack_110[0] + -0x10;
            *(uint *)(iVar3 + 200) =
                 *(uint *)(iVar3 + 200) & 0xfffffffb | (uint)(aiStack_d0[0] != 0) << 2;
            iVar3 = *(int *)(apuStack_110[0] + -8);
            *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
            if (iVar3 + -1 == 0) {
              iVar3 = *(int *)(apuStack_110[0] + -0xc);
              puVar2 = (const char **)func_005C11A8();
              func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
              return 1;
            }
          }
        }
        else {
          puVar7 = apuStack_110[0] + -0x10;
          *(uint *)(iVar3 + 200) =
               *(uint *)(iVar3 + 200) & 0xfffffffd | (uint)(aiStack_d0[0] != 0) << 1;
          iVar3 = *(int *)(apuStack_110[0] + -8);
          *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
          if (iVar3 + -1 == 0) {
            iVar3 = *(int *)(apuStack_110[0] + -0xc);
            puVar2 = (const char **)func_005C11A8();
            func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
            return 1;
          }
        }
      }
      else {
        puVar7 = apuStack_110[0] + -0x10;
        *(uint *)(iVar3 + 200) = *(uint *)(iVar3 + 200) & 0xfffffffe | (uint)(aiStack_d0[0] != 0);
        iVar3 = *(int *)(apuStack_110[0] + -8);
        *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
        if (iVar3 + -1 == 0) {
          iVar3 = *(int *)(apuStack_110[0] + -0xc);
          puVar2 = (const char **)func_005C11A8();
          func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
          return 1;
        }
      }
    }
    else {
      func_0020FE28(aiStack_e0,param_2,apuStack_110);
      func_002A35F8(param_1,aiStack_e0);
      iVar3 = *(int *)(aiStack_e0[0] + -8) + -1;
      *(int *)(aiStack_e0[0] + -8) = iVar3;
      if (iVar3 == 0) {
        iVar3 = *(int *)(aiStack_e0[0] + -0xc);
        puVar2 = (const char **)func_005C11A8();
        func_00326798((void *)(aiStack_e0[0] + -0x10),iVar3 + 0x10,4,*puVar2);
      }
      puVar7 = apuStack_110[0] + -0x10;
      iVar3 = *(int *)(apuStack_110[0] + -8);
      *(int *)(apuStack_110[0] + -8) = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        iVar3 = *(int *)(apuStack_110[0] + -0xc);
        puVar2 = (const char **)func_005C11A8();
        func_00326798(puVar7,iVar3 + 0x10,4,*puVar2);
        return 1;
      }
    }
  }
  return 1;
}








