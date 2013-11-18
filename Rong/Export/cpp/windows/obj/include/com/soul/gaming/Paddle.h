#ifndef INCLUDED_com_soul_gaming_Paddle
#define INCLUDED_com_soul_gaming_Paddle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/soul/gaming/GameObject.h>
HX_DECLARE_CLASS3(com,soul,gaming,GameObject)
HX_DECLARE_CLASS3(com,soul,gaming,Paddle)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace com{
namespace soul{
namespace gaming{


class Paddle_obj : public ::com::soul::gaming::GameObject_obj{
	public:
		typedef ::com::soul::gaming::GameObject_obj super;
		typedef Paddle_obj OBJ_;
		Paddle_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Paddle_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Paddle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Paddle"); }

		virtual Void moveDown( );
		Dynamic moveDown_dyn();

		bool movingDown; /* REM */ 
		virtual Void moveUp( );
		Dynamic moveUp_dyn();

		bool movingUp; /* REM */ 
		virtual Void init( );

		virtual Void update( );

		int difficulty; /* REM */ 
};

} // end namespace com
} // end namespace soul
} // end namespace gaming

#endif /* INCLUDED_com_soul_gaming_Paddle */ 
