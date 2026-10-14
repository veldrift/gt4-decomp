/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xF81A]; unsigned char kind; char pad2[0x3D]; unsigned char flag, mode; };
extern "C" unsigned char DynamicsConductor__GetNumberOfPylonsToBeTouched(void *);
extern "C" int func_003F8818(Obj *p, int arg1) {
    int result = 3;
    switch ((int)p->mode) {
    case 1: break;
    case 2: result = 1; break;
    case 3: result = 2; break;
    case 0:
    default:
        { int kind = p->kind;
          switch (kind) {
          case 1: result = arg1 ? kind : 2; break;
          case 3: case 4: case 6: result = 3; break;
          default: result = 1; break;
          }
        }
        if (DynamicsConductor__GetNumberOfPylonsToBeTouched(p)) result = 2;
        if (p->flag) result = 3;
        break;
    }
    return result;
}
