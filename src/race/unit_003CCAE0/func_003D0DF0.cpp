/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32; typedef char s8;
#define NULL 0

#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

struct V { float x,y,z; };
struct Q { float x,y,z,w; };
struct Inner {
 char pad[0x8f40]; float rot[6][3]; float pos2[6][3]; char pad2[0x8fd0-0x8f40-144];
 float wheel1[6][4]; float wheel2[6][4]; float wheel3[6][4]; float pos[6][3];
};
struct Body { int h; Inner inner; char pad[0x96b0-4-sizeof(Inner)]; int state[6]; };
struct S { int h; Body body; };
struct Pos2 { char pad[0x8f90]; float pos[6][3]; };
struct Rates { char pad[0x8f30]; float rate[6]; };
struct Wheels { char pad[0x95e0]; float wheels[6][4]; };
extern "C" {
f32 func_00344798(s32, f32);                    /* extern */
f32 func_003447F8(s32, f32);                    /* extern */
f32 func_00344828(s32, f32);                    /* extern */
f32 func_00344858(s32, f32);                    /* extern */
f32 func_00344888(s32, f32);                    /* extern */
f32 func_003448B8(s32, f32);                    /* extern */
f32 func_00344AA8(s32, s32, f32);               /* extern */
f32 func_00344B40(s32, s32, f32);               /* extern */
f32 func_00344C08(s32, s32, f32);               /* extern */
f32 func_00344E48(s32, s32, f32);               /* extern */
s32 func_0034C190(s32);                             /* extern */
s32 func_003CD900(S *, s32, s32) throw();               /* extern */
void func_003CDB20(S *, s32, s32) throw(); /* extern */
void func_003CDFD8(S *, s32, s32) throw();               /* extern */
void func_003CE4A0(S *, s32, s32) throw();               /* extern */
void func_003CE930(S *, s32, s32) throw();               /* extern */
void func_0046BEC0(s32, s32, float *, float *, int *); /* extern */

void func_003D0DF0(S *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Stack { int flags[4]; float pos[4]; float rot[4]; } sp_;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s6;
    Body *temp_s7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_a3;
    s32 temp_a5;



    temp_s3 = func_0034C190(arg3);
    temp_v1 = arg0->body.state[arg1];
    switch (temp_v1) {
    case -1:
    case 0:
        if (arg2 == 0) {
            
            arg0->body.state[arg1] = 1;
            ((Wheels *)arg0)->wheels[arg1][0] = 0;
            ((Wheels *)arg0)->wheels[arg1][1] = 0;
            ((Wheels *)arg0)->wheels[arg1][2] = 0;
            ((Wheels *)arg0)->wheels[arg1][3] = 0;
        case 1: {
            func_0046BEC0(arg3 + 0xDA50, arg1, sp_.pos, sp_.rot, sp_.flags);
            
            float z = -sp_.pos[1];
            float r = sp_.rot[2];
            float x = sp_.pos[0];
            float y = sp_.pos[2];
            arg0->body.inner.pos[arg1][0] = x;
            arg0->body.inner.pos[arg1][1] = y;
            arg0->body.inner.pos[arg1][2] = z;
            ((Rates *)arg0)->rate[arg1] = r;
            arg0->body.inner.rot[arg1][0] = 0;
            arg0->body.inner.rot[arg1][1] = r;
            arg0->body.inner.rot[arg1][2] = 0;
            func_003CDB20(arg0, arg1, arg3);
            func_003CE930(arg0, arg1, arg3);
            arg0->body.state[arg1] = 2;
        }
        default:;
        }
        break;
    case 2:
        if (arg2 == 2) {
            arg0->body.state[arg1] = 3;
        case 3:
            arg0->body.inner.pos[arg1][0] = func_00344798(temp_s3, 0);
            arg0->body.inner.pos[arg1][2] = func_00344828(temp_s3, 0);
            ((Wheels *)arg0)->wheels[arg1][0] = func_00344E48(temp_s3, func_003CD900(arg0, arg1, 0), 0);
            ((Wheels *)arg0)->wheels[arg1][1] = func_00344E48(temp_s3, func_003CD900(arg0, arg1, 1), 0);
            ((Wheels *)arg0)->wheels[arg1][2] = func_00344E48(temp_s3, func_003CD900(arg0, arg1, 2), 0);
            ((Wheels *)arg0)->wheels[arg1][3] = func_00344E48(temp_s3, func_003CD900(arg0, arg1, 3), 0);
            func_003CDFD8(arg0, arg1, temp_s3);
            func_003CE4A0(arg0, arg1, arg3);
            arg0->body.state[arg1] = 4;
        }
        break;
    case 4:
        if (arg2 < 4) {
            arg0->body.inner.pos[arg1][0] = func_00344798(temp_s3, 0);
            arg0->body.inner.pos[arg1][2] = func_00344828(temp_s3, 0);
            ((Pos2 *)arg0)->pos[arg1][0] = func_00344798(temp_s3, 0);
            ((Pos2 *)arg0)->pos[arg1][1] = func_003447F8(temp_s3, 0);
            ((Pos2 *)arg0)->pos[arg1][2] = func_00344828(temp_s3, 0);
            temp_v0 = func_003CD900(arg0, arg1, 0);
            arg0->body.inner.wheel1[arg1][0] = func_00344AA8(temp_s3, temp_v0, 0);
            arg0->body.inner.wheel2[arg1][0] = func_00344B40(temp_s3, temp_v0, 0);
            arg0->body.inner.wheel3[arg1][0] = func_00344C08(temp_s3, temp_v0, 0);
            temp_v0_2 = func_003CD900(arg0, arg1, 1);
            arg0->body.inner.wheel1[arg1][1] = func_00344AA8(temp_s3, temp_v0_2, 0);
            arg0->body.inner.wheel2[arg1][1] = func_00344B40(temp_s3, temp_v0_2, 0);
            arg0->body.inner.wheel3[arg1][1] = func_00344C08(temp_s3, temp_v0_2, 0);
            temp_v0_3 = func_003CD900(arg0, arg1, 2);
            arg0->body.inner.wheel1[arg1][2] = func_00344AA8(temp_s3, temp_v0_3, 0);
            arg0->body.inner.wheel2[arg1][2] = func_00344B40(temp_s3, temp_v0_3, 0);
            arg0->body.inner.wheel3[arg1][2] = func_00344C08(temp_s3, temp_v0_3, 0);
            temp_v0_4 = func_003CD900(arg0, arg1, 3);
            arg0->body.inner.wheel1[arg1][3] = func_00344AA8(temp_s3, temp_v0_4, 0);
            arg0->body.inner.wheel2[arg1][3] = func_00344B40(temp_s3, temp_v0_4, 0);
            arg0->body.inner.wheel3[arg1][3] = func_00344C08(temp_s3, temp_v0_4, 0);
        } else {
            arg0->body.inner.rot[arg1][0] = func_00344858(temp_s3, 0);
            arg0->body.inner.rot[arg1][1] = func_003448B8(temp_s3, 0);
            arg0->body.inner.rot[arg1][2] = (f32) -func_00344888(temp_s3, 0);
            arg0->body.state[arg1] = 5;
        case 5:
            arg0->body.state[arg1] = 0;
        }
        break;
    }
}

}
