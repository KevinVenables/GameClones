import com.soul.gaming.Rong;
import nme.Assets;
import nme.events.Event;


class ApplicationMain {
	
	static var mPreloader:NMEPreloader;

	public static function main () {
		
		var call_real = true;
		
		
		var loaded:Int = nme.Lib.current.loaderInfo.bytesLoaded;
		var total:Int = nme.Lib.current.loaderInfo.bytesTotal;
		
		nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		
		if (loaded < total || true) /* Always wait for event */ {
			
			call_real = false;
			mPreloader = new NMEPreloader();
			nme.Lib.current.addChild(mPreloader);
			mPreloader.onInit();
			mPreloader.onUpdate(loaded,total);
			nme.Lib.current.addEventListener (nme.events.Event.ENTER_FRAME, onEnter);
			
		}
		
		
		
		haxe.Log.trace = flashTrace; // null
		

		if (call_real)
			begin ();
	}

	
	private static function flashTrace( v : Dynamic, ?pos : haxe.PosInfos ) {
		var className = pos.className.substr(pos.className.lastIndexOf('.') + 1);
		var message = className+"::"+pos.methodName+":"+pos.lineNumber+": " + v;

        if (flash.external.ExternalInterface.available)
			flash.external.ExternalInterface.call("console.log", message);
		else untyped flash.Boot.__trace(v, pos);
    }
	
	
	private static function begin () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(com.soul.gaming.Rong))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (com.soul.gaming.Rong, Reflect.field (com.soul.gaming.Rong, "main"), []);
		}
		else
		{
			nme.Lib.current.addChild(cast (Type.createInstance(com.soul.gaming.Rong, []), nme.display.DisplayObject));	
		}
		
	}

	static function onEnter (_) {
		
		var loaded:Int = nme.Lib.current.loaderInfo.bytesLoaded;
		var total:Int = nme.Lib.current.loaderInfo.bytesTotal;
		mPreloader.onUpdate(loaded,total);
		
		if (loaded >= total) {
			
			nme.Lib.current.removeEventListener(nme.events.Event.ENTER_FRAME, onEnter);
			mPreloader.addEventListener (Event.COMPLETE, preloader_onComplete);
			mPreloader.onLoaded();
			
		}
		
	}

	public static function getAsset (inName:String):Dynamic {
		
		
		if (inName=="assets/arrow.png")
			 
            return Assets.getBitmapData ("assets/arrow.png");
         
		
		if (inName=="assets/background.png")
			 
            return Assets.getBitmapData ("assets/background.png");
         
		
		if (inName=="assets/backgroundMenu.png")
			 
            return Assets.getBitmapData ("assets/backgroundMenu.png");
         
		
		if (inName=="assets/ball.png")
			 
            return Assets.getBitmapData ("assets/ball.png");
         
		
		if (inName=="assets/cow.jpg")
			 
            return Assets.getBitmapData ("assets/cow.jpg");
         
		
		if (inName=="assets/easy.png")
			 
            return Assets.getBitmapData ("assets/easy.png");
         
		
		if (inName=="assets/hard.png")
			 
            return Assets.getBitmapData ("assets/hard.png");
         
		
		if (inName=="assets/medium.png")
			 
            return Assets.getBitmapData ("assets/medium.png");
         
		
		if (inName=="assets/omg.png")
			 
            return Assets.getBitmapData ("assets/omg.png");
         
		
		if (inName=="assets/paddle.png")
			 
            return Assets.getBitmapData ("assets/paddle.png");
         
		
		if (inName=="assets/sound/Blip_Select.wav")
			 
            return Assets.getSound ("assets/sound/Blip_Select.wav");
         
		
		if (inName=="assets/subtitle.png")
			 
            return Assets.getBitmapData ("assets/subtitle.png");
         
		
		if (inName=="assets/title.png")
			 
            return Assets.getBitmapData ("assets/title.png");
         
		
		
		return null;
		
	}
	
	
	private static function preloader_onComplete (event:Event):Void {
		
		mPreloader.removeEventListener (Event.COMPLETE, preloader_onComplete);
		
		nme.Lib.current.removeChild(mPreloader);
		mPreloader = null;
		
		begin ();
		
	}
	
}


class NME_assets_arrow_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_background_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_backgroundmenu_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_ball_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_cow_jpg extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_easy_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_hard_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_medium_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_omg_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_paddle_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_sound_blip_select_wav extends nme.media.Sound { }
class NME_assets_subtitle_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_title_png extends nme.display.BitmapData { public function new () { super (0, 0); } }

