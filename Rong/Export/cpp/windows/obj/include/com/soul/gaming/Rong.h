#ifndef INCLUDED_com_soul_gaming_Rong
#define INCLUDED_com_soul_gaming_Rong

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS3(com,soul,gaming,Game)
HX_DECLARE_CLASS3(com,soul,gaming,GameState)
HX_DECLARE_CLASS3(com,soul,gaming,Rong)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace com{
namespace soul{
namespace gaming{


class Rong_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
		typedef Rong_obj OBJ_;
		Rong_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Rong_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Rong_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Rong"); }

		virtual Void update( Dynamic e);
		Dynamic update_dyn();

		virtual Void initialize( );
		Dynamic initialize_dyn();

		::com::soul::gaming::Game game; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace com
} // end namespace soul
} // end namespace gaming

#endif /* INCLUDED_com_soul_gaming_Rong */ 
