package com.soul.gaming;
import nme.Assets;
import nme.media.Sound;

import Std;

/**
 * ...
 * @author Kevin Venables
 */

class Ball extends GameObject
{
	public var velocity_X:Float = 5;
	public var velocity_Y:Float = 5;
	var beep:Sound;
	public function new() 
	{
		super();
	}
	
	override public function update():Dynamic 
	{
		//hits NPC paddle
		//hits PC paddle
		x += velocity_X;
		y += velocity_Y;
		//will keep for movement
		if (y < 10 || y > 390)
		{
			velocity_Y = velocity_Y * -1;
			beep.play(0, 0);			
		}
		
		if (collides(Game.player))
		{
			velocity_X = velocity_X * -1;
			beep.play(0, 0);
		}
		
		if (collides(Game.npc))
		{
			velocity_X = velocity_X * -1;
			Game.npc.posPicked = false;
			beep.play(0, 0);
		}
		
		//npc scores
		if (x < 0)
		{
			resetPOS();
			Game.npcScore++;
		}
		if (x > 790)
		{
			resetPOS();
			Game.playerScore++;
		}
		
		
		
		super.update();
	}
	
	
	private function collides(paddle:Paddle) : Bool
	{
			if (
			x < paddle.x + paddle.width //left
			&& x + width > paddle.x //right
			&& y < paddle.y + paddle.height //top
			&& y + height > paddle.y //bottom
			)
			{
				return true;
			}
		return false;
	}
	
	public function resetPOS():Void
	{
		Game.npc.posPicked = false;
		x = 400;
		y = 200;
		//random x direction
		if (Std.random( -2) == -1)
		{
			velocity_X = velocity_X * -1;
		}
		
		//random y direction
		if (Std.random( -2) == -1)
		{
			velocity_Y = velocity_Y * -1;
		}
		
	}
	override public function init():Void 
	{
		bitmapData = Assets.getBitmapData("assets/ball.png");
	
		beep = Assets.getSound("assets/sound/Blip_Select.wav");
		x = 400;
		y = 200;
		//random x direction
		if (Std.random( -2) == -1)
		{
			velocity_X = velocity_X * -1;
		}
		
		//random y direction
		if (Std.random( -2) == -1)
		{
			velocity_Y = velocity_Y * -1;
		}
		
		

		
		super.init();
	}
}