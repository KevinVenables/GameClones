#ifndef INCLUDED_com_soul_gaming_GameObject
#define INCLUDED_com_soul_gaming_GameObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Bitmap.h>
HX_DECLARE_CLASS3(com,soul,gaming,GameObject)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace com{
namespace soul{
namespace gaming{


class GameObject_obj : public ::neash::display::Bitmap_obj{
	public:
		typedef ::neash::display::Bitmap_obj super;
		typedef GameObject_obj OBJ_;
		GameObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GameObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameObject"); }

		virtual Void init( );
		Dynamic init_dyn();

		bool initialized; /* REM */ 
		virtual Void update( );
		Dynamic update_dyn();

};

} // end namespace com
} // end namespace soul
} // end namespace gaming

#endif /* INCLUDED_com_soul_gaming_GameObject */ 
