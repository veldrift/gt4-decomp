/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x48]; signed char front,left,right,sideleft,sideright,backleft,backright,back; char gap[8]; float minleft,minright; };
extern "C" void func_004694F8(Obj *o,float speed,float z,float x,float front,float rear,float width) {
 if(speed>20.0f) return;
 float extent=width+3.0f;
 if(x < -extent) return;
 if(extent < x) return;
 if(front*0.9f < z) {
  float w=width*0.75f;
  z-=front;
  if(x < -w) {
   if(z<5.0f) { if(o->left<2) o->left=2; }
   else if(z<20.0f) { if(o->left<=0) o->left=1; }
  } else if(w<x) {
   if(z<5.0f) { if(o->right<2) o->right=2; }
   else if(z<20.0f) { if(o->right<=0) o->right=1; }
  } else {
   if(z<20.0f) { if(o->front<2) o->front=2; }
   if(x < -(width*0.5f)) {
    if(z<5.0f) { if(o->left<2) o->left=2; }
    else if(z<20.0f) { if(o->left<=0) o->left=1; }
   }
   if(width*0.5f < x) {
    if(z<5.0f) { if(o->right<2) o->right=2; }
    else if(z<20.0f) { if(o->right<=0) o->right=1; }
   }
  }
 } else if(z < -(rear*0.9f)) {
  if(x < -width) { if(o->backleft<2) o->backleft=2; }
  else if(width<x) { if(o->backright<2) o->backright=2; }
  else {
   if(o->back<2) o->back=2;
   if(x>0.0f) { if(o->backright<=0) o->backright=1; }
   else { if(o->backleft<=0) o->backleft=1; }
  }
 } else if(x<0.0f) {
  float d=-x-width;
  if(d<o->minleft) o->minleft=d;
  if(o->sideleft<2) o->sideleft=2;
  if(front*0.5f < z) { if(o->left<=0) o->left=1; }
  else if(z < -(rear*0.5f)) { if(o->backleft<=0) o->backleft=1; }
 } else {
  x-=width;
  if(x<o->minright) o->minright=x;
  if(o->sideright<2) o->sideright=2;
  if(front*0.5f < z) { if(o->right<=0) o->right=1; }
  else if(z < -(rear*0.5f)) { if(o->backright<=0) o->backright=1; }
 }
}
