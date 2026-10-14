/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; };
struct Alloc { const char *name; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *, int, int, const char *, int);
extern "C" Alloc *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003068A8(void *, Str *, void (*)());
extern "C" void func_00306980(void *, Str *, void (*)(), void (*)());
extern "C" void func_003066F8(void *, int);
extern "C" void adhoc__LoadKanjiFont();
extern "C" void adhoc__UnloadKanjiFont();
extern "C" void func_0026DB68();
extern "C" int mActivateEvent__GetClassID();
extern "C" int func_001FF0F8();
extern "C" int func_002782C0();
extern "C" int mBlob__GetClassID();
extern "C" int func_002790E0();
extern "C" int mBlockTransition__GetClassID();
extern "C" int mBlurFace__GetClassID();
extern "C" int mBox__GetClassID();
extern "C" int mButton__GetClassID();
extern "C" int func_0027E2C8();
extern "C" int func_0027F2B8();
extern "C" int mButtonPressEvent__GetClassID();
extern "C" int mButtonReleaseEvent__GetClassID();
extern "C" int mCallbackEvent__GetClassID();
extern "C" int mCancelEvent__GetClassID();
extern "C" int func_00283858();
extern "C" int mColorFace__GetClassID();
extern "C" int mColorObject__GetClassID();
extern "C" int mColorTransition__GetClassID();
extern "C" int mColorWindow__GetClassID();
extern "C" int func_00271070();
extern "C" int mComposite__GetClassID();
extern "C" int mCrossTransition__GetClassID();
extern "C" int mCrossingEvent__GetClassID();
extern "C" int func_0028BEF8();
extern "C" int func_001DB078();
extern "C" int mDomNode__GetClassID();
extern "C" int mDomNodeList__GetClassID();
extern "C" int mEnterEvent__GetClassID();
extern "C" int mEvent__GetClassID();
extern "C" int mFBox__GetClassID();
extern "C" int func_0020B4E8();
extern "C" int mFinalizeEvent__GetClassID();
extern "C" int mFlashFace__GetClassID();
extern "C" int mFocusEnterEvent__GetClassID();
extern "C" int mFocusLeaveEvent__GetClassID();
extern "C" int mFrameImageFace__GetClassID();
extern "C" int mFunctionEvent__GetClassID();
extern "C" int mGameInputAnalog__GetClassID();
extern "C" int mGameInputButton__GetClassID();
extern "C" int mGameInputData__GetClassID();
extern "C" int mGamePort__GetClassID();
extern "C" int mGpb__GetClassID();
extern "C" int func_0029E998();
extern "C" int mHBox__GetClassID();
extern "C" int func_001D7028();
extern "C" int mImageFace__GetClassID();
extern "C" int mInputNumberFace__GetClassID();
extern "C" int mInputTextFace__GetClassID();
extern "C" int func_002A95A8();
extern "C" int mKeyPressEvent__GetClassID();
extern "C" int mKeyReleaseEvent__GetClassID();
extern "C" int mKeyboardBox__GetClassID();
extern "C" int mKeytopBox__GetClassID();
extern "C" int mLeaveEvent__GetClassID();
extern "C" int mListBox__GetClassID();
extern "C" int mLocale__GetClassID();
extern "C" int mMBox__GetClassID();
extern "C" int func_002B9980();
extern "C" int mManager__GetClassID();
extern "C" int mModelFace__GetClassID();
extern "C" int mModelStream__GetClassID();
extern "C" int mMotionEvent__GetClassID();
extern "C" int func_002C0530();
extern "C" int mMovieFace__GetClassID();
extern "C" int mMusic__GetClassID();
extern "C" int mNetConf__GetClassID();
extern "C" int func_001DC7A0();
extern "C" int func_002C7460();
extern "C" int mPipe__GetClassID();
extern "C" int mProgress__GetClassID();
extern "C" int mProgressFace__GetClassID();
extern "C" int mProject__GetClassID();
extern "C" int mRandom__GetClassID();
extern "C" int mRenderContext__GetClassID();
extern "C" int mRootWindow__GetClassID();
extern "C" int func_002CCA70();
extern "C" int func_00236828();
extern "C" int mScriptEvent__GetClassID();
extern "C" int mScriptWatcher__GetClassID();
extern "C" int mScrollArrow__GetClassID();
extern "C" int mScrollBase__GetClassID();
extern "C" int mScrollBox__GetClassID();
extern "C" int mScrollPinch__GetClassID();
extern "C" int func_002D26E8();
extern "C" int mScrollable__GetClassID();
extern "C" int mSelectBar__GetClassID();
extern "C" int mSelectBox__GetClassID();
extern "C" int mSession__GetClassID();
extern "C" int mShell__GetClassID();
extern "C" int func_002DD7E8();
extern "C" int mSound__GetClassID();
extern "C" int mStorage__GetClassID();
extern "C" int mStorageEntry__GetClassID();
extern "C" int mStorageHD__GetClassID();
extern "C" int mStream__GetClassID();
extern "C" int func_002E2188();
extern "C" int func_002E3D10();
extern "C" int mTextBoxFace__GetClassID();
extern "C" int mTextFace__GetClassID();
extern "C" int mToolTipFace__GetClassID();
extern "C" int mTransform__GetClassID();
extern "C" int mTransition__GetClassID();
extern "C" int mUpdateContext__GetClassID();
extern "C" int mVBox__GetClassID();
extern "C" int mVirtualFace__GetClassID();
extern "C" int mWidget__GetClassID();
extern "C" int mWindowEvent__GetClassID();
extern "C" int mXml__GetClassID();
extern "C" int mUpdateContextPS2__GetClassID();
extern "C" int mRenderContextPS2__GetClassID();
extern "C" int func_002766D8();
extern "C" void init_menu(void **arg0) {
 Str s;
 {
 void *obj = *arg0;
 Str *ps = &s;
 const char *src = "LoadKanjiFont";
 Rep *r = &D_00659FA8;
 char *d;
 if (r->sel != 0) d = func_005C2560(r);
 else { d = (char *)(r + 1); r->ref++; }
 ps->p = d;
 func_005C2630(ps, 0, -1, src, func_0057F260(src));
 func_003068A8(obj, &s, adhoc__LoadKanjiFont);
 Rep *q = (Rep *)(s.p - 0x10);
 if (--q->ref == 0) {
 int cap = q->cap + 0x10;
 func_00326798(q, cap, 4, func_005C11A8()->name);
 }
 }
 {
 void *obj = *arg0;
 Str *ps = &s;
 const char *src = "UnloadKanjiFont";
 Rep *r = &D_00659FA8;
 char *d;
 if (r->sel != 0) d = func_005C2560(r);
 else { d = (char *)(r + 1); r->ref++; }
 ps->p = d;
 func_005C2630(ps, 0, -1, src, func_0057F260(src));
 func_003068A8(obj, &s, adhoc__UnloadKanjiFont);
 Rep *q = (Rep *)(s.p - 0x10);
 if (--q->ref == 0) {
 int cap = q->cap + 0x10;
 func_00326798(q, cap, 4, func_005C11A8()->name);
 }
 }
 {
 void *obj = *arg0;
 Str *ps = &s;
 const char *src = "Version";
 Rep *r = &D_00659FA8;
 char *d;
 if (r->sel != 0) d = func_005C2560(r);
 else { d = (char *)(r + 1); r->ref++; }
 ps->p = d;
 func_005C2630(ps, 0, -1, src, func_0057F260(src));
 func_00306980(obj, &s, func_0026DB68, func_0026DB68);
 Rep *q = (Rep *)(s.p - 0x10);
 if (--q->ref == 0) {
 int cap = q->cap + 0x10;
 func_00326798(q, cap, 4, func_005C11A8()->name);
 }
 }
 { void *obj = *arg0; func_003066F8(obj, mActivateEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_001FF0F8()); }
 { void *obj = *arg0; func_003066F8(obj, func_002782C0()); }
 { void *obj = *arg0; func_003066F8(obj, mBlob__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002790E0()); }
 { void *obj = *arg0; func_003066F8(obj, mBlockTransition__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mBlurFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mButton__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_0027E2C8()); }
 { void *obj = *arg0; func_003066F8(obj, func_0027F2B8()); }
 { void *obj = *arg0; func_003066F8(obj, mButtonPressEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mButtonReleaseEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mCallbackEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mCancelEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_00283858()); }
 { void *obj = *arg0; func_003066F8(obj, mColorFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mColorObject__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mColorTransition__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mColorWindow__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_00271070()); }
 { void *obj = *arg0; func_003066F8(obj, mComposite__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mCrossTransition__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mCrossingEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_0028BEF8()); }
 { void *obj = *arg0; func_003066F8(obj, func_001DB078()); }
 { void *obj = *arg0; func_003066F8(obj, mDomNode__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mDomNodeList__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mEnterEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_0020B4E8()); }
 { void *obj = *arg0; func_003066F8(obj, mFinalizeEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFlashFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFocusEnterEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFocusLeaveEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFrameImageFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mFunctionEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mGameInputAnalog__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mGameInputButton__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mGameInputData__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mGamePort__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mGpb__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_0029E998()); }
 { void *obj = *arg0; func_003066F8(obj, mHBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_001D7028()); }
 { void *obj = *arg0; func_003066F8(obj, mImageFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mInputNumberFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mInputTextFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002A95A8()); }
 { void *obj = *arg0; func_003066F8(obj, mKeyPressEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mKeyReleaseEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mKeyboardBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mKeytopBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mLeaveEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mListBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mLocale__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mMBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002B9980()); }
 { void *obj = *arg0; func_003066F8(obj, mManager__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mModelFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mModelStream__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mMotionEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002C0530()); }
 { void *obj = *arg0; func_003066F8(obj, mMovieFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mMusic__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mNetConf__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_001DC7A0()); }
 { void *obj = *arg0; func_003066F8(obj, func_002C7460()); }
 { void *obj = *arg0; func_003066F8(obj, mPipe__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mProgress__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mProgressFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mProject__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mRandom__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mRenderContext__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mRootWindow__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002CCA70()); }
 { void *obj = *arg0; func_003066F8(obj, func_00236828()); }
 { void *obj = *arg0; func_003066F8(obj, mScriptEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mScriptWatcher__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mScrollArrow__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mScrollBase__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mScrollBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mScrollPinch__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002D26E8()); }
 { void *obj = *arg0; func_003066F8(obj, mScrollable__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mSelectBar__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mSelectBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mSession__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mShell__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002DD7E8()); }
 { void *obj = *arg0; func_003066F8(obj, mSound__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mStorage__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mStorageEntry__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mStorageHD__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mStream__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002E2188()); }
 { void *obj = *arg0; func_003066F8(obj, func_002E3D10()); }
 { void *obj = *arg0; func_003066F8(obj, mTextBoxFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mTextFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mToolTipFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mTransform__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mTransition__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mUpdateContext__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mVBox__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mVirtualFace__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mWidget__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mWindowEvent__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mXml__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mUpdateContextPS2__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, mRenderContextPS2__GetClassID()); }
 { void *obj = *arg0; func_003066F8(obj, func_002766D8()); }
}
