/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Reader;
struct String { char *p; };
extern unsigned char D_006D0E79[];
extern "C" int func_0020FAD8(Reader *);
extern "C" int func_0020E670(Reader *);
extern "C" void func_0020E6F8(Reader *, int);
extern "C" String *func_005CB368(String *, u32, u32, u32, char);
extern "C" void func_005CB5A0(String *, u32, u32);
extern "C" int func_0020EE38(int);
extern "C" int func_0020EEB8(Reader *param_1, String *param_2)

{
  bool bVar1;
  int lVar2;
  int lVar3;
  int lVar4;
  unsigned int uVar5;
  int iVar6;
  int *piVar7;
  
  do {
    lVar2 = func_0020FAD8(param_1);
  } while ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 8) != 0);
  if (lVar2 == -1) {
    return -1;
  }
  func_005CB368(param_2,0,0xffffffffffffffff,0,0);
  piVar7 = (int *)param_2;
  if (((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 3) != 0) || (lVar2 == 0x5f)) {
    do {
      func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
      lVar2 = func_0020FAD8(param_1);
      bVar1 = false;
      if (lVar2 == -1) break;
      if ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 7) == 0) {
        if (lVar2 == 0x5f) {
          bVar1 = true;
        }
      }
      else {
        bVar1 = true;
      }
    } while (bVar1);
    func_0020E6F8(param_1,lVar2);
    return 0x100;
  }
  if (lVar2 == 0x27) {
    while( true ) {
      lVar2 = func_0020E670(param_1);
      if ((lVar2 == -1) || (lVar2 == 0x27)) break;
      func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
    }
    if (lVar2 == -1) {
      return -1;
    }
    return 0x100;
  }
  if ((lVar2 == 0x2d) || (lVar2 == 0x2b)) {
    func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
    lVar2 = func_0020FAD8(param_1);
    if (((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0) && (lVar2 != 0x2e)) {
      func_0020E6F8(param_1,lVar2);
      iVar6 = *piVar7;
      if (1 < *(unsigned int *)(iVar6 + -8)) {
        func_005CB5A0(param_2,*(unsigned int *)(iVar6 + -0x10),1);
        iVar6 = *piVar7;
      }
      *(unsigned int *)(iVar6 + -4) = 1;
      lVar2 = (int)*(char *)*piVar7;
    }
  }
  if (lVar2 == 0x30) {
    lVar2 = func_0020FAD8(param_1);
    if ((lVar2 == 0x78) || (lVar2 == 0x58)) {
      lVar3 = func_0020FAD8(param_1);
      if ((*(unsigned char *)(D_006D0E79 + (int)lVar3) & 0x44) != 0) {
        do {
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar3);
          lVar2 = func_0020FAD8(param_1);
          if (lVar2 == -1) break;
          lVar3 = lVar2;
        } while ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 0x44) != 0);
        goto LAB_0020f720;
      }
    }
    else {
      if ((lVar2 != 0x62) && (lVar2 != 0x42)) {
        if ((int)lVar2 - 0x30U < 8) {
          do {
            func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
            lVar2 = func_0020FAD8(param_1);
            if (lVar2 == -1) break;
          } while ((int)lVar2 - 0x30U < 8);
          goto LAB_0020f720;
        }
        func_0020E6F8(param_1,lVar2);
        lVar2 = 0x30;
        goto LAB_0020f284;
      }
      lVar3 = func_0020FAD8(param_1);
      if ((int)lVar3 - 0x30U < 2) {
        do {
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar3);
          lVar2 = func_0020FAD8(param_1);
          if (lVar2 == -1) break;
          lVar3 = lVar2;
        } while ((int)lVar2 - 0x30U < 2);
        goto LAB_0020f720;
      }
    }
    func_0020E6F8(param_1,lVar3);
    func_0020E6F8(param_1,lVar2);
    lVar2 = 0x30;
  }
LAB_0020f284:
  if ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0) {
    if (lVar2 != 0x2e) {
      if (lVar2 != 0x22) {
        func_005CB368(param_2,0,0xffffffffffffffff,1,(char)lVar2);
        return lVar2;
      }
      while( true ) {
        lVar2 = func_0020E670(param_1);
        if (lVar2 == -1) {
          return -1;
        }
        if (lVar2 == 0x22) break;
        if (lVar2 == 0x5c) {
          uVar5 = func_0020E670(param_1);
          lVar2 = func_0020EE38(uVar5);
          if (lVar2 == -1) {
            return -1;
          }
        }
        if (lVar2 != 0) {
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
        }
      }
      return 0x102;
    }
    lVar2 = func_0020FAD8(param_1);
    if ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0) {
      func_0020E6F8(param_1,lVar2);
      func_005CB368(param_2,0,0xffffffffffffffff,1,0x2e);
      return 0x2e;
    }
    func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,0x2e);
    iVar6 = *piVar7;
    while( true ) {
      func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
      lVar2 = func_0020FAD8(param_1);
      if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
      iVar6 = *piVar7;
    }
    if ((lVar2 != 0x65) && (lVar2 != 0x45)) {
      func_0020E6F8(param_1,lVar2);
      return 0x101;
    }
    lVar3 = func_0020FAD8(param_1);
    if ((lVar3 == 0x2b) || (lVar3 == 0x2d)) {
      lVar4 = func_0020FAD8(param_1);
      if ((*(unsigned char *)(D_006D0E79 + (int)lVar4) & 4) != 0) {
        func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
        func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar3);
        iVar6 = *piVar7;
        lVar2 = lVar4;
        while( true ) {
          func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
          lVar2 = func_0020FAD8(param_1);
          if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
          iVar6 = *piVar7;
        }
        goto LAB_0020f720;
      }
      func_0020E6F8(param_1,lVar4);
    }
    else if ((*(unsigned char *)(D_006D0E79 + (int)lVar3) & 4) != 0) {
      func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
      iVar6 = *piVar7;
      lVar2 = lVar3;
      while( true ) {
        func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
        lVar2 = func_0020FAD8(param_1);
        if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
        iVar6 = *piVar7;
      }
      goto LAB_0020f720;
    }
    func_0020E6F8(param_1,lVar3);
  }
  else {
    iVar6 = *piVar7;
    while( true ) {
      func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
      lVar2 = func_0020FAD8(param_1);
      if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
      iVar6 = *piVar7;
    }
    if (lVar2 == 0x2e) {
      lVar2 = func_0020FAD8(param_1);
      if ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) != 0) {
        func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,0x2e);
        iVar6 = *piVar7;
        while( true ) {
          func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
          lVar2 = func_0020FAD8(param_1);
          if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
          iVar6 = *piVar7;
        }
      }
      if ((lVar2 != 0x65) && (lVar2 != 0x45)) {
        func_0020E6F8(param_1,lVar2);
        return 0x101;
      }
      lVar3 = func_0020FAD8(param_1);
      if ((lVar3 == 0x2b) || (lVar3 == 0x2d)) {
        lVar4 = func_0020FAD8(param_1);
        if ((*(unsigned char *)(D_006D0E79 + (int)lVar4) & 4) != 0) {
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar3);
          iVar6 = *piVar7;
          lVar2 = lVar4;
          while( true ) {
            func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
            lVar2 = func_0020FAD8(param_1);
            if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
            iVar6 = *piVar7;
          }
          goto LAB_0020f720;
        }
        func_0020E6F8(param_1,lVar4);
      }
      else if ((*(unsigned char *)(D_006D0E79 + (int)lVar3) & 4) != 0) {
        func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
        iVar6 = *piVar7;
        lVar2 = lVar3;
        while( true ) {
          func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
          lVar2 = func_0020FAD8(param_1);
          if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
          iVar6 = *piVar7;
        }
        goto LAB_0020f720;
      }
      func_0020E6F8(param_1,lVar3);
    }
    else {
      if ((lVar2 != 0x65) && (lVar2 != 0x45)) {
        func_0020E6F8(param_1,lVar2);
        return 0x101;
      }
      lVar3 = func_0020FAD8(param_1);
      if ((lVar3 == 0x2b) || (lVar3 == 0x2d)) {
        lVar4 = func_0020FAD8(param_1);
        if ((*(unsigned char *)(D_006D0E79 + (int)lVar4) & 4) != 0) {
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
          func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar3);
          iVar6 = *piVar7;
          lVar2 = lVar4;
          while( true ) {
            func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
            lVar2 = func_0020FAD8(param_1);
            if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
            iVar6 = *piVar7;
          }
          goto LAB_0020f720;
        }
        func_0020E6F8(param_1,lVar4);
      }
      else if ((*(unsigned char *)(D_006D0E79 + (int)lVar3) & 4) != 0) {
        func_005CB368(param_2,*(unsigned int *)(*piVar7 + -0x10),0,1,(char)lVar2);
        iVar6 = *piVar7;
        lVar2 = lVar3;
        while( true ) {
          func_005CB368(param_2,*(unsigned int *)(iVar6 + -0x10),0,1,(char)lVar2);
          lVar2 = func_0020FAD8(param_1);
          if ((lVar2 == -1) || ((*(unsigned char *)(D_006D0E79 + (int)lVar2) & 4) == 0)) break;
          iVar6 = *piVar7;
        }
        goto LAB_0020f720;
      }
      func_0020E6F8(param_1,lVar3);
    }
  }
LAB_0020f720:
  func_0020E6F8(param_1,lVar2);
  return 0x101;
}


