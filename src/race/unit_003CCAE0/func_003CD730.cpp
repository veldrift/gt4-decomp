/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Car { char pad[0x168]; int f168; char q[8]; int f174; };
extern "C" u8 *func_00359538(int);
struct Rows { char pad[0x9850]; int arr[1][4]; };
#define T(k) (((Rows *)(self + 8))->arr[idx][k])

extern "C" void func_003CD730(char *self, int idx, int arg2)
{
    u8 type = *func_00359538(arg2);
    switch (type) {
    case 1:
        T(0) = 0; T(1) = 0; T(2) = 1; T(3) = 1;
        *(int *)(idx * 0x8D0 + (int)self + 0x6D0) = 1;
        *(int *)(idx * 0x8D0 + (int)self + 0x9B4) = 1;
        break;
    case 2: {
        T(0) = 0; T(1) = 0; T(2) = 1; T(3) = 2;
        Car *c = (Car *)(idx * 0x8D0 + (int)self + 0x55C);
        c->f174 = 1;
        c->f168 = 1;
        break;
    }
    case 3: {
        T(0) = 0; T(1) = 1; T(2) = 2; T(3) = 2;
        Car *c = (Car *)(idx * 0x8D0 + (int)self + 0x84C);
        c->f174 = 1;
        c->f168 = 1;
        break;
    }
    case 0:
    default:
        T(0) = 0; T(1) = 1; T(2) = 2; T(3) = 3;
        break;
    }
}
