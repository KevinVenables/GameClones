package;

import flash.display.BitmapData;
import flash.display.Sprite;
import flash.display.Bitmap;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.geom.Rectangle;
import flash.text.TextField;
import flash.geom.Point;

import openfl.Assets;

class Main extends Sprite {
	
	var boardDisplay : Bitmap;
	var debug : TextField;
	var board : Array<Array<TacLoc>>;
	
	//display data
	var X : BitmapData;
	var O : BitmapData;
	public function new () {		
		super ();
		init();
		addEventListener(MouseEvent.CLICK, event_onClick);
	}
	
	public function event_onClick(e : MouseEvent) : Void
	{
		//just places x on board
		
	}
	
	public function init() : Void
	{
		//display stuff
		boardDisplay = new Bitmap(Assets.getBitmapData("assets/board.png"));
		board.y = 5;
		addChild(board);
		debug = new TextField();
		debug.text = "hello";
		addChild(debug);
		
		//setup board
		board = new Array<Array<TacLoc>> ();
		var mult = 100;
		for (a in 1...3)
		{
			var tmp : Array<TacLoc> - new Array<TacLoc>();
			for (b in 1...3)
			{
				tmp.push(new TacLoc(200, 200, a * mult, b * mult);
			}
			board.push(tmp);
		}
		
		//import x and y bitmapdata
		X = Assets.getBitmapData("assets/X.png");
		O = Assets.getBitmapData("assets/O.png");		
	}
	
}

class TacLoc extends Bitmap
{
	public var location : Int;
	public var state : Int;
	public static var state_X : Int = 1;
	public static var state_O : Int = 2;
	public var rect : Rectangle;
	public function new(width : Float, height : Float,
		x : Float, y : Float) 
	{
		super();
		this.x = x;
		this.y = y;
		this.rect = new Rectangle(x, y, width, height);
	}
	
}