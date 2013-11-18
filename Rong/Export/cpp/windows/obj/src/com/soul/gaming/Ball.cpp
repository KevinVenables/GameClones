#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_soul_gaming_Ball
#include <com/soul/gaming/Ball.h>
#endif
#ifndef INCLUDED_com_soul_gaming_GameObject
#include <com/soul/gaming/GameObject.h>
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
#ifndef INCLUDED_neash_media_Sound
#include <neash/media/Sound.h>
#endif
#ifndef INCLUDED_neash_media_SoundChannel
#include <neash/media/SoundChannel.h>
#endif
#ifndef INCLUDED_neash_media_SoundTransform
#include <neash/media/SoundTransform.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace soul{
namespace gaming{

Void Ball_obj::__construct()
{
HX_STACK_PUSH("Ball::new","com/soul/gaming/Ball.hx",12);
{
	HX_STACK_LINE(15)
	this->velocity_Y = (int)5;
	HX_STACK_LINE(14)
	this->velocity_X = (int)5;
	HX_STACK_LINE(18)
	super::__construct();
}
;
	return null();
}

Ball_obj::~Ball_obj() { }

Dynamic Ball_obj::__CreateEmpty() { return  new Ball_obj; }
hx::ObjectPtr< Ball_obj > Ball_obj::__new()
{  hx::ObjectPtr< Ball_obj > result = new Ball_obj();
	result->__construct();
	return result;}

Dynamic Ball_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Ball_obj > result = new Ball_obj();
	result->__construct();
	return result;}

Void Ball_obj::init( ){
{
		HX_STACK_PUSH("Ball::init","com/soul/gaming/Ball.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_LINE(46)
		this->nmeSetBitmapData(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/ball.png"),null()));
		HX_STACK_LINE(47)
		this->nmeSetX((int)400);
		HX_STACK_LINE(48)
		this->nmeSetY((int)200);
		HX_STACK_LINE(50)
		this->beep = ::nme::installer::Assets_obj::getSound(HX_CSTRING("assets/sound/Blip_Select.wav"));
		HX_STACK_LINE(54)
		if (((::Std_obj::random((int)-2) == (int)-1))){
			HX_STACK_LINE(55)
			this->velocity_X = (this->velocity_X * (int)-1);
		}
		HX_STACK_LINE(60)
		if (((::Std_obj::random((int)-2) == (int)-1))){
			HX_STACK_LINE(61)
			this->velocity_Y = (this->velocity_Y * (int)-1);
		}
		HX_STACK_LINE(65)
		this->super::init();
	}
return null();
}


Void Ball_obj::update( ){
{
		HX_STACK_PUSH("Ball::update","com/soul/gaming/Ball.hx",23);
		HX_STACK_THIS(this);
		HX_STACK_LINE(26)
		{
			HX_STACK_LINE(26)
			::com::soul::gaming::Ball _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(26)
			_g->nmeSetX((_g->nmeGetX() + this->velocity_X));
		}
		HX_STACK_LINE(27)
		{
			HX_STACK_LINE(27)
			::com::soul::gaming::Ball _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(27)
			_g->nmeSetY((_g->nmeGetY() + this->velocity_Y));
		}
		HX_STACK_LINE(29)
		if (((bool((this->nmeGetY() < (int)10)) || bool((this->nmeGetY() > (int)390))))){
			HX_STACK_LINE(31)
			this->velocity_Y = (this->velocity_Y * (int)-1);
			HX_STACK_LINE(32)
			this->beep->play((int)0,(int)0,null());
		}
		HX_STACK_LINE(36)
		if (((bool((this->nmeGetX() < (int)0)) || bool((this->nmeGetX() > (int)790))))){
			HX_STACK_LINE(38)
			this->velocity_X = (this->velocity_X * (int)-1);
			HX_STACK_LINE(39)
			this->beep->play((int)0,(int)0,null());
		}
		HX_STACK_LINE(41)
		this->super::update();
		HX_STACK_LINE(41)
		return null();
	}
return null();
}



Ball_obj::Ball_obj()
{
}

void Ball_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Ball);
	HX_MARK_MEMBER_NAME(beep,"beep");
	HX_MARK_MEMBER_NAME(velocity_Y,"velocity_Y");
	HX_MARK_MEMBER_NAME(velocity_X,"velocity_X");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Ball_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(beep,"beep");
	HX_VISIT_MEMBER_NAME(velocity_Y,"velocity_Y");
	HX_VISIT_MEMBER_NAME(velocity_X,"velocity_X");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Ball_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"beep") ) { return beep; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"velocity_Y") ) { return velocity_Y; }
		if (HX_FIELD_EQ(inName,"velocity_X") ) { return velocity_X; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Ball_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"beep") ) { beep=inValue.Cast< ::neash::media::Sound >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"velocity_Y") ) { velocity_Y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocity_X") ) { velocity_X=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Ball_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("beep"));
	outFields->push(HX_CSTRING("velocity_Y"));
	outFields->push(HX_CSTRING("velocity_X"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("init"),
	HX_CSTRING("update"),
	HX_CSTRING("beep"),
	HX_CSTRING("velocity_Y"),
	HX_CSTRING("velocity_X"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Ball_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Ball_obj::__mClass,"__mClass");
};

Class Ball_obj::__mClass;

void Ball_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.soul.gaming.Ball"), hx::TCanCast< Ball_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Ball_obj::__boot()
{
}

} // end namespace com
} // end namespace soul
} // end namespace gaming
