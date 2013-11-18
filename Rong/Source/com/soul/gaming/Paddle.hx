package com.soul.gaming;
import nme.Assets;
import Math;
import nme.events.TextEvent;
import nme.text.TextField;

/**
 * ...
 * @author Kevin Venables
 */

class Paddle extends GameObject
{
	//NPC Handling
	public var difficulty:Int;
	public var aiPOS:Int = 0;
	public var posPicked:Bool = false;
	public static var HUMAN:Int = 0;
	public static var EASY:Int = 1;
	//public static var MED:Int = 2;
	//public static var HARD:Int = 3;
	
	

	public function new() 
	{
		super();
	}
	
	override public function update():Dynamic 
	{
		if (difficulty == HUMAN)
		{
			if (movingUp)
				moveUp();
			if (movingDown)
				moveDown();
		}
		else
		{
			if (posPicked)
			{
				if (aiPOS < y)
					moveUp();
				if (aiPOS > y)
					moveDown();
			}
			else if (Game.ball.velocity_X > 0)
			{
				if (Game.ball.x > 400)
				{
					if (Game.ball.velocity_Y < 0)
					{
						aiPOS = Std.random(200);
						posPicked = true;
					}
					if (Game.ball.velocity_Y > 0)
					{
						aiPOS = Std.random(200) + 200;
						posPicked = true;
					}
				}
			}
		}
		
		super.update();		
	}
	
	override public function init():Void 
	{
		bitmapData = Assets.getBitmapData("assets/paddle.png");
		if (difficulty == HUMAN)
		{
			x = 0;
			y = 10;
		}
		else
		{
			x = 790;
			y = 10;
		}
		
		
		
		super.init();
	}
	
	//human movements, keyboard
	public var movingUp:Bool = false;
	public function moveUp():Void
	{
		if (!(y <= 0))
			y -= 5;
	}
	
	public var movingDown:Bool = false;
	public function moveDown():Void
	{
		if(!(y >= 350))
			y += 5;
	}
	
}