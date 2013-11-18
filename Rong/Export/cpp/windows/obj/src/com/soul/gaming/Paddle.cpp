#include <hxcpp.h>

#ifndef INCLUDED_com_soul_gaming_GameObject
#include <com/soul/gaming/GameObject.h>
#endif
#ifndef INCLUDED_com_soul_gaming_Paddle
#include <com/soul/gaming/Paddle.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace soul{
namespace gaming{

Void Paddle_obj::__construct()
{
HX_STACK_PUSH("Paddle::new","com/soul/gaming/Paddle.hx",9);
{
	HX_STACK_LINE(64)
	this->movingDown = false;
	HX_STACK_LINE(58)
	this->movingUp = false;
	HX_STACK_LINE(22)
	super::__construct();
}
;
	return null();
}

Paddle_obj::~Paddle_obj() { }

Dynamic Paddle_obj::__CreateEmpty() { return  new Paddle_obj; }
hx::ObjectPtr< Paddle_obj > Paddle_obj::__new()
{  hx::ObjectPtr< Paddle_obj > result = new Paddle_obj();
	result->__construct();
	return result;}

Dynamic Paddle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Paddle_obj > result = new Paddle_obj();
	result->__construct();
	return result;}

Void Paddle_obj::moveDown( ){
{
		HX_STACK_PUSH("Paddle::moveDown","com/soul/gaming/Paddle.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_LINE(67)
		::com::soul::gaming::Paddle _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		_g->nmeSetY((_g->nmeGetY() + (int)5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Paddle_obj,moveDown,(void))

Void Paddle_obj::moveUp( ){
{
		HX_STACK_PUSH("Paddle::moveUp","com/soul/gaming/Paddle.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_LINE(61)
		::com::soul::gaming::Paddle _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		_g->nmeSetY((_g->nmeGetY() - (int)5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Paddle_obj,moveUp,(void))

Void Paddle_obj::init( ){
{
		HX_STACK_PUSH("Paddle::init","com/soul/gaming/Paddle.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(51)
		this->nmeSetBitmapData(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/paddle.png"),null()));
		HX_STACK_LINE(52)
		this->nmeSetX((int)0);
		HX_STACK_LINE(53)
		this->nmeSetY((int)10);
		HX_STACK_LINE(54)
		this->super::init();
	}
return null();
}


Void Paddle_obj::update( ){
{
		HX_STACK_PUSH("Paddle::update","com/soul/gaming/Paddle.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_LINE(41)
		if ((this->movingUp)){
			HX_STACK_LINE(42)
			this->moveUp();
		}
		HX_STACK_LINE(43)
		if ((this->movingDown)){
			HX_STACK_LINE(44)
			this->moveDown();
		}
		HX_STACK_LINE(45)
		this->super::update();
		HX_STACK_LINE(45)
		return null();
	}
return null();
}



Paddle_obj::Paddle_obj()
{
}

void Paddle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Paddle);
	HX_MARK_MEMBER_NAME(movingDown,"movingDown");
	HX_MARK_MEMBER_NAME(movingUp,"movingUp");
	HX_MARK_MEMBER_NAME(difficulty,"difficulty");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Paddle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(movingDown,"movingDown");
	HX_VISIT_MEMBER_NAME(movingUp,"movingUp");
	HX_VISIT_MEMBER_NAME(difficulty,"difficulty");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Paddle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"moveUp") ) { return moveUp_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moveDown") ) { return moveDown_dyn(); }
		if (HX_FIELD_EQ(inName,"movingUp") ) { return movingUp; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movingDown") ) { return movingDown; }
		if (HX_FIELD_EQ(inName,"difficulty") ) { return difficulty; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Paddle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"movingUp") ) { movingUp=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movingDown") ) { movingDown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"difficulty") ) { difficulty=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Paddle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("movingDown"));
	outFields->push(HX_CSTRING("movingUp"));
	outFields->push(HX_CSTRING("difficulty"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("moveDown"),
	HX_CSTRING("movingDown"),
	HX_CSTRING("moveUp"),
	HX_CSTRING("movingUp"),
	HX_CSTRING("init"),
	HX_CSTRING("update"),
	HX_CSTRING("difficulty"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Paddle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Paddle_obj::__mClass,"__mClass");
};

Class Paddle_obj::__mClass;

void Paddle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.soul.gaming.Paddle"), hx::TCanCast< Paddle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Paddle_obj::__boot()
{
}

} // end namespace com
} // end namespace soul
} // end namespace gaming
