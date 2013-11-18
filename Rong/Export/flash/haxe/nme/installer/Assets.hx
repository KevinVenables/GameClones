package nme.installer;


import nme.display.BitmapData;
import nme.media.Sound;
import nme.net.URLRequest;
import nme.text.Font;
import nme.utils.ByteArray;
import ApplicationMain;


/**
 * ...
 * @author Joshua Granick
 */

class Assets {

	
	public static var cachedBitmapData:Hash<BitmapData> = new Hash<BitmapData>();
	
	private static var initialized:Bool = false;
	private static var resourceClasses:Hash <Dynamic> = new Hash <Dynamic> ();
	private static var resourceTypes:Hash <String> = new Hash <String> ();
	
	
	private static function initialize ():Void {
		
		if (!initialized) {
			
			resourceClasses.set ("assets/arrow.png", NME_assets_arrow_png);
			resourceTypes.set ("assets/arrow.png", "image");
			resourceClasses.set ("assets/background.png", NME_assets_background_png);
			resourceTypes.set ("assets/background.png", "image");
			resourceClasses.set ("assets/backgroundMenu.png", NME_assets_backgroundmenu_png);
			resourceTypes.set ("assets/backgroundMenu.png", "image");
			resourceClasses.set ("assets/ball.png", NME_assets_ball_png);
			resourceTypes.set ("assets/ball.png", "image");
			resourceClasses.set ("assets/cow.jpg", NME_assets_cow_jpg);
			resourceTypes.set ("assets/cow.jpg", "image");
			resourceClasses.set ("assets/easy.png", NME_assets_easy_png);
			resourceTypes.set ("assets/easy.png", "image");
			resourceClasses.set ("assets/hard.png", NME_assets_hard_png);
			resourceTypes.set ("assets/hard.png", "image");
			resourceClasses.set ("assets/medium.png", NME_assets_medium_png);
			resourceTypes.set ("assets/medium.png", "image");
			resourceClasses.set ("assets/omg.png", NME_assets_omg_png);
			resourceTypes.set ("assets/omg.png", "image");
			resourceClasses.set ("assets/paddle.png", NME_assets_paddle_png);
			resourceTypes.set ("assets/paddle.png", "image");
			resourceClasses.set ("assets/sound/Blip_Select.wav", NME_assets_sound_blip_select_wav);
			resourceTypes.set ("assets/sound/Blip_Select.wav", "sound");
			resourceClasses.set ("assets/subtitle.png", NME_assets_subtitle_png);
			resourceTypes.set ("assets/subtitle.png", "image");
			resourceClasses.set ("assets/title.png", NME_assets_title_png);
			resourceTypes.set ("assets/title.png", "image");
			
			initialized = true;
			
		}
		
	}
	
	
	public static function getBitmapData (id:String, useCache:Bool = true):BitmapData {
		
		initialize ();
		
		if (resourceTypes.exists (id) && resourceTypes.get (id) == "image") {
			
			if (useCache && cachedBitmapData.exists (id)) {
				
				return cachedBitmapData.get (id);
				
			} else {
				
				var data = cast (Type.createInstance (resourceClasses.get (id), []), BitmapData);
				
				if (useCache) {
					
					cachedBitmapData.set (id, data);
					
				}
				
				return data;
				
			}
			
		} else {
			
			trace ("[nme.Assets] There is no BitmapData asset with an ID of \"" + id + "\"");
			
			return null;
			
		}
		
	}
	
	
	public static function getBytes (id:String):ByteArray {
		
		initialize ();
		
		if (resourceClasses.exists (id)) {
			
			return Type.createInstance (resourceClasses.get (id), []);
			
		} else {
			
			trace ("[nme.Assets] There is no ByteArray asset with an ID of \"" + id + "\"");
			
			return null;
			
		}
		
	}
	
	
	public static function getFont (id:String):Font {
		
		initialize ();
		
		if (resourceTypes.exists (id) && resourceTypes.get (id) == "font") {
			
			return cast (Type.createInstance (resourceClasses.get (id), []), Font);
			
		} else {
			
			trace ("[nme.Assets] There is no Font asset with an ID of \"" + id + "\"");
			
			return null;
			
		}
		
	}
	
	
	public static function getSound (id:String):Sound {
		
		initialize ();
		
		if (resourceTypes.exists (id)) {
			
			if (resourceTypes.get (id) == "sound" || resourceTypes.get (id) == "music") {
				
				return cast (Type.createInstance (resourceClasses.get (id), []), Sound);
				
			}
			
		}
		
		trace ("[nme.Assets] There is no Sound asset with an ID of \"" + id + "\"");
		
		return null;
		
	}
	
	
	public static function getText (id:String):String {
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
	}
	
	
}