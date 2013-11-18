#include <hxcpp.h>

#ifndef INCLUDED_com_soul_gaming_Game
#include <com/soul/gaming/Game.h>
#endif
#ifndef INCLUDED_com_soul_gaming_GameState
#include <com/soul/gaming/GameState.h>
#endif
#ifndef INCLUDED_com_soul_gaming_Rong
#include <com/soul/gaming/Rong.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace soul{
namespace gaming{

Void Rong_obj::__construct()
{
HX_STACK_PUSH("Rong::new","com/soul/gaming/Rong.hx",27);
{
	HX_STACK_LINE(29)
	super::__construct();
	HX_STACK_LINE(31)
	this->initialize();
}
;
	return null();
}

Rong_obj::~Rong_obj() { }

Dynamic Rong_obj::__CreateEmpty() { return  new Rong_obj; }
hx::ObjectPtr< Rong_obj > Rong_obj::__new()
{  hx::ObjectPtr< Rong_obj > result = new Rong_obj();
	result->__construct();
	return result;}

Dynamic Rong_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rong_obj > result = new Rong_obj();
	result->__construct();
	return result;}

Void Rong_obj::update( Dynamic e){
{
		HX_STACK_PUSH("Rong::update","com/soul/gaming/Rong.hx",56);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(56)
		this->game->update();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rong_obj,update,(void))

Void Rong_obj::initialize( ){
{
		HX_STACK_PUSH("Rong::initialize","com/soul/gaming/Rong.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_LINE(36)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetAlign(::neash::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(37)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::neash::display::StageScaleMode_obj::NO_SCALE_dyn());
		HX_STACK_LINE(38)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
		HX_STACK_LINE(39)
		this->game = ::com::soul::gaming::Game_obj::__new();
		HX_STACK_LINE(41)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addChild(this->game);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rong_obj,initialize,(void))

Void Rong_obj::main( ){
{
		HX_STACK_PUSH("Rong::main","com/soul/gaming/Rong.hx",43);
		HX_STACK_LINE(43)
		::nme::Lib_obj::nmeGetCurrent()->addChild(::com::soul::gaming::Rong_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Rong_obj,main,(void))


Rong_obj::Rong_obj()
{
}

void Rong_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rong);
	HX_MARK_MEMBER_NAME(game,"game");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Rong_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(game,"game");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Rong_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"game") ) { return game; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rong_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { game=inValue.Cast< ::com::soul::gaming::Game >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rong_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("game"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initialize"),
	HX_CSTRING("game"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rong_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rong_obj::__mClass,"__mClass");
};

Class Rong_obj::__mClass;

void Rong_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.soul.gaming.Rong"), hx::TCanCast< Rong_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Rong_obj::__boot()
{
}

} // end namespace com
} // end namespace soul
} // end namespace gaming
