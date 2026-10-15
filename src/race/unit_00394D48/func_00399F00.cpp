/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { int x,y,w,h; Rect() {} Rect(int a,int b,int c,int d):x(a),y(b),w(c),h(d) {} };
struct View { int a[4]; int x,y,w,h; int b[7]; };
struct Obj { char pad[0x2c]; View v; int n; Rect r[5]; };
extern "C" void func_001054A0(View*,int);
extern "C" void func_001056A0(View*);
extern "C" void func_00105728(View*);
extern "C" void func_004A4550(int,int);
extern "C" void func_004A4810(int,int,int);
extern "C" void func_004A4910();
extern "C" void func_004A6788(float,float,float,float,float,float,float,float);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004AB040(int);
extern "C" void func_00399F00(Obj *o,View *v) {
 View *own=&o->v;
 int width=own->x+own->w;
 int height=own->y+own->h;
 o->r[0]=Rect(0,0,width/2,height);
 o->r[1]=Rect(width/2,0,width/2,height/2);
 o->r[2]=Rect(width/2,height/2,width/4,height/2);
 o->r[3]=Rect(width*3/4,height/2,width/4,height/4);
 o->r[4]=Rect(width*3/4,height*3/4,width/4,height/4);
 o->n=4; own->a[1]=1;
 func_001054A0(own,0); own->b[3]=0;
 int x=0,y=0;
 int w=v->x+v->w,h=v->y+v->h;
 func_004AB040(4);func_004AB040(6);func_004AB040(5);
 func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
 func_001056A0(own);func_00105728(v);
 func_004A4550(3,1);func_004A4550(2,1);
 for(int i=0;i<o->n+1;i++) {
  if(i==1)func_00105728(own);
  int sx=x,sy=y;
  int ex=w,ey=h;
  x=o->r[i].x; y=o->r[i].y;
  w=o->r[i].w;h=o->r[i].h;
  func_004A4550(4,2);func_004A4550(5,2);
  func_004A4810(0,sx,sx+ex-1);func_004A4810(1,sy,sy+ey-1);
  func_004A4550(2,1);
  func_004A6788((float)x,(float)y,(float)(x+w),(float)(y+h),(float)sx,(float)sy,(float)(sx+ex),(float)(sy+ey));
  func_004A4910();
 }
}
