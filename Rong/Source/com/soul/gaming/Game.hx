package com.soul.gaming;
import nme.display.Bitmap;
import nme.Assets;
import nme.geom.Rectangle;
import nme.Lib;
import nme.media.Sound;
import nme.text.TextField;

import nme.events.KeyboardEvent;
import nme.ui.Keyboard;
/**
 * ...
 * @author Kevin Venables
 */

class Game extends GameState
{
	private var background:Bitmap;
	public static var player:Paddle;
	public static var npc:Paddle;
	public static var ball:Ball;
	var movement:Int = -5;
	
	public static var playerScore:Int = 0;
	public static var npcScore:Int = 0;
	
	public var npcText:TextField;
	public var playerText:TextField;
	public function new() 
	{
		super();
	}
	
	override public function update():Dynamic 
	{
		if (!initialized)
			init();
			
		ball.update();
		player.update();
		npc.update();
		playerText.text = Std.string(playerScore);
		npcText.text = Std.string(npcScore);
		super.update();
		
	}
	
	override public function init():Void 
	{
		initialized = true;
				
		background = new Bitmap(Assets.getBitmapData("assets/background.png"));
		background.x = 0;
		background.y = 0;
		addChild(background);
		ball = new Ball();
		ball.init();
		addChild(ball);
		
		player = new Paddle();
		player.init();
		addChild(player);
		
		npc = new Paddle();
		npc.difficulty = Paddle.EASY;
		npc.init();
		addChild(npc);
		
		playerText = new TextField();
		playerText.x = 100;
		playerText.y = 100;
		playerText.textColor = 0xFFFFFF;
		playerText.text = Std.string(playerScore);
		addChild(playerText);
		
		npcText = new TextField();
		npcText.x = 500;
		npcText.y = 100;
		npcText.textColor = 0xFFFFFF;
		npcText.text = Std.string(npcScore);
		addChild(npcText);
		
		
		Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, keyDown);
		Lib.current.stage.addEventListener(KeyboardEvent.KEY_UP, keyUp);
		
		
		super.init();
	}
	
	public function keyDown(e:KeyboardEvent) : Void
	{
		switch(e.keyCode)
		{
			case(Keyboard.UP):
				player.movingUp = true;
			case(Keyboard.DOWN):
				player.movingDown = true;
		}
	}
	
	public function keyUp(e:KeyboardEvent) : Void
	{
		switch(e.keyCode)
		{
			case(Keyboard.UP):
				player.movingUp = false;
			case(Keyboard.DOWN):
				player.movingDown = false;
		}
	}
}