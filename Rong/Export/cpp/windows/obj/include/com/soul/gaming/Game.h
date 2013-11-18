#ifndef INCLUDED_com_soul_gaming_Game
#define INCLUDED_com_soul_gaming_Game

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/soul/gaming/GameState.h>
HX_DECLARE_CLASS3(com,soul,gaming,Ball)
HX_DECLARE_CLASS3(com,soul,gaming,Game)
HX_DECLARE_CLASS3(com,soul,gaming,GameObject)
HX_DECLARE_CLASS3(com,soul,gaming,GameState)
HX_DECLARE_CLASS3(com,soul,gaming,Paddle)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
namespace com{
namespace soul{
namespace gaming{


class Game_obj : public ::com::soul::gaming::GameState_obj{
	public:
		typedef ::com::soul::gaming::GameState_obj super;
		typedef Game_obj OBJ_;
		Game_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Game_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Game_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Game"); }

		virtual Void keyUp( ::neash::events::KeyboardEvent e);
		Dynamic keyUp_dyn();

		virtual Void keyDown( ::neash::events::KeyboardEvent e);
		Dynamic keyDown_dyn();

		virtual Void init( );

		virtual Void update( );

		int movement; /* REM */ 
		::com::soul::gaming::Ball ball; /* REM */ 
		::com::soul::gaming::Paddle player; /* REM */ 
		::neash::display::Bitmap background; /* REM */ 
};

} // end namespace com
} // end namespace soul
} // end namespace gaming

#endif /* INCLUDED_com_soul_gaming_Game */ 
