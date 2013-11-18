class ApplicationMain
{

	#if waxe
	static public var frame : wx.Frame;
	static public var autoShowFrame : Bool = true;
	#if nme
	static public var nmeStage : wx.NMEStage;
	#end
	#end
	
	public static function main()
	{
		#if nme
		nme.Lib.setPackage("Kevin Venables", "Rong", "com.soul.gaming", "1.0.0");
		
		#end
		
		#if waxe
		wx.App.boot(function()
		{
			
			frame = wx.Frame.create(null, null, "Rong", null, { width: 800, height: 400 });
			
			#if nme
			var stage = wx.NMEStage.create(frame, null, null, { width: 800, height: 400 });
			#end
			
			com.soul.gaming.Rong.main();
			
			if (autoShowFrame)
			{
				wx.App.setTopWindow(frame);
				frame.shown = true;
			}
		});
		#else
		
		nme.Lib.create(function()
			{ 
				if (800 == 0 && 400 == 0)
				{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				}
				
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
			},
			800, 400, 
			30, 
			0xffffff,
			(true ? nme.Lib.HARDWARE : 0) |
			(false ? nme.Lib.ALLOW_SHADERS : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(false ? nme.Lib.BORDERLESS : 0) |
			(false ? nme.Lib.VSYNC : 0) |
			(false ? nme.Lib.FULLSCREEN : 0) |
			(1 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(1 == 2 ? nme.Lib.HW_AA : 0),
			"Rong"
			
			, getAsset("icon.png")
			
		);
		#end
		
	}
	
	
	public static function getAsset(inName:String):Dynamic
	{
		#if nme
		
		if (inName == "assets/arrow.png")
		{
			
			return nme.Assets.getBitmapData ("assets/arrow.png");
			
		}
		
		if (inName == "assets/background.png")
		{
			
			return nme.Assets.getBitmapData ("assets/background.png");
			
		}
		
		if (inName == "assets/backgroundMenu.png")
		{
			
			return nme.Assets.getBitmapData ("assets/backgroundMenu.png");
			
		}
		
		if (inName == "assets/ball.png")
		{
			
			return nme.Assets.getBitmapData ("assets/ball.png");
			
		}
		
		if (inName == "assets/cow.jpg")
		{
			
			return nme.Assets.getBitmapData ("assets/cow.jpg");
			
		}
		
		if (inName == "assets/easy.png")
		{
			
			return nme.Assets.getBitmapData ("assets/easy.png");
			
		}
		
		if (inName == "assets/hard.png")
		{
			
			return nme.Assets.getBitmapData ("assets/hard.png");
			
		}
		
		if (inName == "assets/medium.png")
		{
			
			return nme.Assets.getBitmapData ("assets/medium.png");
			
		}
		
		if (inName == "assets/omg.png")
		{
			
			return nme.Assets.getBitmapData ("assets/omg.png");
			
		}
		
		if (inName == "assets/paddle.png")
		{
			
			return nme.Assets.getBitmapData ("assets/paddle.png");
			
		}
		
		if (inName == "assets/sound/Blip_Select.wav")
		{
			
			return nme.Assets.getSound ("assets/sound/Blip_Select.wav");
			
		}
		
		if (inName == "assets/subtitle.png")
		{
			
			return nme.Assets.getBitmapData ("assets/subtitle.png");
			
		}
		
		if (inName == "assets/title.png")
		{
			
			return nme.Assets.getBitmapData ("assets/title.png");
			
		}
		
		#end
		return null;
	}
	
	
}
