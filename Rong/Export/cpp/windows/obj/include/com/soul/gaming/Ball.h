#ifndef INCLUDED_com_soul_gaming_Ball
#define INCLUDED_com_soul_gaming_Ball

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/soul/gaming/GameObject.h>
HX_DECLARE_CLASS3(com,soul,gaming,Ball)
HX_DECLARE_CLASS3(com,soul,gaming,GameObject)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,media,Sound)
namespace com{
namespace soul{
namespace gaming{


class Ball_obj : public ::com::soul::gaming::GameObject_obj{
	public:
		typedef ::com::soul::gaming::GameObject_obj super;
		typedef Ball_obj OBJ_;
		Ball_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Ball_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Ball_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Ball"); }

		virtual Void init( );

		virtual Void update( );

		::neash::media::Sound beep; /* REM */ 
		Float velocity_Y; /* REM */ 
		Float velocity_X; /* REM */ 
};

} // end namespace com
} // end namespace soul
} // end namespace gaming

#endif /* INCLUDED_com_soul_gaming_Ball */ 
