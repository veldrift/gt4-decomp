struct Mat {float v[16];};
struct Quat {float x,y,z,w;};
struct State {int hasAngle;float angle;int hasTransform;float a,b;Mat matrix;int hasOther;float c,d;};
extern "C" void func_0048AB70(Quat*,const Mat*);
extern "C" void func_0048CA50(Quat*,const Quat*,const Quat*,float);
extern "C" void func_0048A970(const Quat*,Mat*,float,float,float);
extern "C" void func_003B0630(State*out,const State*left,const State*right,float t){
 out->hasAngle=left->hasAngle && right->hasAngle;
 if(out->hasAngle)out->angle=left->angle*(1-t)+right->angle*t;
 out->hasTransform=left->hasTransform && right->hasTransform;
 if(out->hasTransform){
 Quat q,ql,qr;
 float first=left->a;
 float inv=1-t;
 Quat*pql=&ql;Quat*pqr=&qr;
 const Mat*ml=&left->matrix;const Mat*mr=&right->matrix;Mat*mo=&out->matrix;
 out->a=first*inv+right->a*t;
 out->b=left->b*inv+right->b*t;
 func_0048AB70(pql,ml);func_0048AB70(pqr,mr);
 func_0048CA50(&q,pql,pqr,t);
 func_0048A970(&q,mo,ml->v[12]*inv+mr->v[12]*t,ml->v[13]*inv+mr->v[13]*t,ml->v[14]*inv+mr->v[14]*t);
 }
 out->hasOther=left->hasOther && right->hasOther;
 if(out->hasOther){out->c=left->c*(1-t)+right->c*t;out->d=left->d*(1-t)+right->d*t;}
}
