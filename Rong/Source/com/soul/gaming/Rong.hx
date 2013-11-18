package com.soul.gaming;


import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;

import nme.text.TextField;
import nme.events.KeyboardEvent;

import nme.media.Sound;
import nme.Assets;

/**
 * @author Kevin Venables
 */
class Rong extends Sprite {
	
	
	
	//basic state management, currentstate will contain the active state we want updating
	//public var currentState:GameState;
	public var game:Game;
	
	public function new () {
		
		super ();
		
		initialize ();
				
	}
	private function initialize ():Void {
		
		Lib.current.stage.align = StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, update);
		game = new Game();
		
		Lib.current.stage.addChild(game);
	}	
	public static function main () {
		
		Lib.current.addChild (new Rong ());
		
	}
	
	/*
	public function swapToGame():Void
	{
		currentState = game;
	}
	*/
	public function update(e= null):Void
	{
		game.update();
	}
	
	
}