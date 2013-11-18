#include <hxcpp.h>

#ifndef INCLUDED_com_soul_gaming_Ball
#include <com/soul/gaming/Ball.h>
#endif
#ifndef INCLUDED_com_soul_gaming_Game
#include <com/soul/gaming/Game.h>
#endif
#ifndef INCLUDED_com_soul_gaming_GameObject
#include <com/soul/gaming/GameObject.h>
#endif
#ifndef INCLUDED_com_soul_gaming_GameState
#include <com/soul/gaming/GameState.h>
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
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
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
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_neash_ui_Keyboard
#include <neash/ui/Keyboard.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace soul{
namespace gaming{

Void Game_obj::__construct()
{
HX_STACK_PUSH("Game::new","com/soul/gaming/Game.hx",15);
{
	HX_STACK_LINE(20)
	this->movement = (int)-5;
	HX_STACK_LINE(22)
	super::__construct();
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hx::ObjectPtr< Game_obj > Game_obj::__new()
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Dynamic Game_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Void Game_obj::keyUp( ::neash::events::KeyboardEvent e){
{
		HX_STACK_PUSH("Game::keyUp","com/soul/gaming/Game.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(71)
		int _switch_1 = (e->keyCode);
		if (  ( _switch_1==::neash::ui::Keyboard_obj::UP)){
			HX_STACK_LINE(74)
			this->player->movingUp = false;
		}
		else if (  ( _switch_1==::neash::ui::Keyboard_obj::DOWN)){
			HX_STACK_LINE(76)
			this->player->movingDown = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,keyUp,(void))

Void Game_obj::keyDown( ::neash::events::KeyboardEvent e){
{
		HX_STACK_PUSH("Game::keyDown","com/soul/gaming/Game.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(60)
		int _switch_2 = (e->keyCode);
		if (  ( _switch_2==::neash::ui::Keyboard_obj::UP)){
			HX_STACK_LINE(63)
			this->player->movingUp = true;
		}
		else if (  ( _switch_2==::neash::ui::Keyboard_obj::DOWN)){
			HX_STACK_LINE(65)
			this->player->movingDown = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,keyDown,(void))

Void Game_obj::init( ){
{
		HX_STACK_PUSH("Game::init","com/soul/gaming/Game.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		this->initialized = true;
		HX_STACK_LINE(40)
		this->background = ::neash::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/background.png"),null()),null(),null());
		HX_STACK_LINE(41)
		this->background->nmeSetX((int)0);
		HX_STACK_LINE(42)
		this->background->nmeSetY((int)0);
		HX_STACK_LINE(43)
		this->addChild(this->background);
		HX_STACK_LINE(44)
		this->ball = ::com::soul::gaming::Ball_obj::__new();
		HX_STACK_LINE(45)
		this->ball->init();
		HX_STACK_LINE(46)
		this->addChild(this->ball);
		HX_STACK_LINE(48)
		this->player = ::com::soul::gaming::Paddle_obj::__new();
		HX_STACK_LINE(49)
		this->player->init();
		HX_STACK_LINE(50)
		this->addChild(this->player);
		HX_STACK_LINE(52)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->keyDown_dyn(),null(),null(),null());
		HX_STACK_LINE(53)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->keyUp_dyn(),null(),null(),null());
		HX_STACK_LINE(56)
		this->super::init();
	}
return null();
}


Void Game_obj::update( ){
{
		HX_STACK_PUSH("Game::update","com/soul/gaming/Game.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_LINE(28)
		if ((!(this->initialized))){
			HX_STACK_LINE(29)
			this->init();
		}
		HX_STACK_LINE(31)
		this->ball->update();
		HX_STACK_LINE(32)
		this->player->update();
		HX_STACK_LINE(33)
		this->super::update();
		HX_STACK_LINE(33)
		return null();
	}
return null();
}



Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(movement,"movement");
	HX_MARK_MEMBER_NAME(ball,"ball");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(background,"background");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Game_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(movement,"movement");
	HX_VISIT_MEMBER_NAME(ball,"ball");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(background,"background");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Game_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"ball") ) { return ball; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"keyUp") ) { return keyUp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyDown") ) { return keyDown_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { return movement; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Game_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ball") ) { ball=inValue.Cast< ::com::soul::gaming::Ball >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::com::soul::gaming::Paddle >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { movement=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::neash::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Game_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("movement"));
	outFields->push(HX_CSTRING("ball"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("background"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("keyUp"),
	HX_CSTRING("keyDown"),
	HX_CSTRING("init"),
	HX_CSTRING("update"),
	HX_CSTRING("movement"),
	HX_CSTRING("ball"),
	HX_CSTRING("player"),
	HX_CSTRING("background"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.soul.gaming.Game"), hx::TCanCast< Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Game_obj::__boot()
{
}

} // end namespace com
} // end namespace soul
} // end namespace gaming
