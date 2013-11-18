package nme.installer;


import nme.display.BitmapData;
import nme.media.Sound;
import nme.net.URLRequest;
import nme.text.Font;
import nme.utils.ByteArray;


/**
 * ...
 * @author Joshua Granick
 */

class Assets {

	
	public static var cachedBitmapData:Hash<BitmapData> = new Hash<BitmapData>();
	
	private static var initialized:Bool = false;
	private static var resourceNames:Hash <String> = new Hash <String> ();
	private static var resourceTypes:Hash <String> = new Hash <String> ();
	
	
	private static function initialize ():Void {
		
		if (!initialized) {
			
			resourceNames.set ("assets/arrow.png", "assets/arrow.png");
			resourceTypes.set ("assets/arrow.png", "image");
			resourceNames.set ("assets/background.png", "assets/background.png");
			resourceTypes.set ("assets/background.png", "image");
			resourceNames.set ("assets/backgroundMenu.png", "assets/backgroundMenu.png");
			resourceTypes.set ("assets/backgroundMenu.png", "image");
			resourceNames.set ("assets/ball.png", "assets/ball.png");
			resourceTypes.set ("assets/ball.png", "image");
			resourceNames.set ("assets/cow.jpg", "assets/cow.jpg");
			resourceTypes.set ("assets/cow.jpg", "image");
			resourceNames.set ("assets/easy.png", "assets/easy.png");
			resourceTypes.set ("assets/easy.png", "image");
			resourceNames.set ("assets/hard.png", "assets/hard.png");
			resourceTypes.set ("assets/hard.png", "image");
			resourceNames.set ("assets/medium.png", "assets/medium.png");
			resourceTypes.set ("assets/medium.png", "image");
			resourceNames.set ("assets/omg.png", "assets/omg.png");
			resourceTypes.set ("assets/omg.png", "image");
			resourceNames.set ("assets/paddle.png", "assets/paddle.png");
			resourceTypes.set ("assets/paddle.png", "image");
			resourceNames.set ("assets/sound/Blip_Select.wav", "assets/sound/Blip_Select.wav");
			resourceTypes.set ("assets/sound/Blip_Select.wav", "sound");
			resourceNames.set ("assets/subtitle.png", "assets/subtitle.png");
			resourceTypes.set ("assets/subtitle.png", "image");
			resourceNames.set ("assets/title.png", "assets/title.png");
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
				
				var data = BitmapData.load (resourceNames.get (id));
				
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
		
		if (resourceNames.exists (id)) {
			
			return ByteArray.readFile (resourceNames.get (id));
			
		} else {
			
			trace ("[nme.Assets] There is no String or ByteArray asset with an ID of \"" + id + "\"");
			
			return null;
			
		}
		
	}
	
	
	public static function getFont (id:String):Font {
		
		initialize ();
		
		if (resourceTypes.exists (id) && resourceTypes.get (id) == "font") {
			
			return new Font (resourceNames.get (id));
			
		} else {
			
			trace ("[nme.Assets] There is no Font asset with an ID of \"" + id + "\"");
			
			return null;
			
		}
		
	}
	
	
	public static function getResourceName (id:String):String {
		
		initialize ();
		
		return resourceNames.get (id);
		
	}
	
	
	public static function getSound (id:String):Sound {
		
		initialize ();
		
		if (resourceTypes.exists (id)) {
			
			if (resourceTypes.get (id) == "sound") {
				
				return new Sound (new URLRequest (resourceNames.get (id)), null, false);
				
			} else if (resourceTypes.get (id) == "music") {
				
				return new Sound (new URLRequest (resourceNames.get (id)), null, true);
				
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
