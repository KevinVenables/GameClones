package;


import flash.display.Sprite;
import flash.display.Bitmap;
import flash.events.KeyboardEvent;
import flash.ui.Keyboard;

import flash.text.FontStyle;
import flash.text.FontType;
import flash.text.TextField;
import flash.text.TextFieldAutoSize;
import flash.Lib;

import openfl.Assets;
class Main extends Sprite {
	
	static var currentState : Int = 0;
	static var inputState : Int = 1;
	static var guessState : Int = 2;
	
	var guess : String;
	
	var frames : Array<Bitmap>;
	var guesses : Int;
	
	//text
	var debugText : TextField;
	var inputField : TextField;
	var guessText : TextField;
	
	
	public function new () {
		super ();
		setupFrames();
		addChild(frames[0]);
		debugText = new TextField();
		debugText.text = "Give a word: ";
		debugText.textColor = 0xFF0000;
		addChild(debugText);
		
		guessText = new TextField();
		guessText.scaleY = 8;
		guessText.width = 1000;
		guessText.x = 275;
		guessText.y = 450;
		
		
		inputField = new TextField();
		inputField.x = debugText.x + 100;
		inputField.textColor = 0xFF0000;
		addChild(inputField);
		
		currentState = inputState;
		Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, event_onKeyDown);
		guess = "";
		guesses = 0;
		
		
	}
	//where most of the game will be handled
	public function event_onKeyDown(e : KeyboardEvent) : Void
	{
		if (currentState == inputState)
		{
			state_inputState(e);
		}
		else if (currentState == guessState)
		{
			state_guessState(e);
		}
	}
	
	public function state_inputState(e : KeyboardEvent) : Void
	{
		
		if (e.keyCode == Keyboard.ENTER)
		{
			swapToGuess();
		}
		
		else if (e.keyCode == Keyboard.BACKSPACE)
		{
			if (inputField.text != "")
			{
				inputField.text = inputField.text.substr(0, inputField.text.length - 1);
			}
		}
		
		else
		{
			var tmp : String = String.fromCharCode(e.keyCode);
			inputField.text += tmp.toLowerCase();
		}
	}
	
	public function state_guessState(e : KeyboardEvent) : Void
	{
		//first, check if guess was correct
		var matched : Bool = false;
		var tmp : String = String.fromCharCode(e.keyCode);
		tmp = tmp.toLowerCase();
		for (a in 0...inputField.text.length)
		{
			if (tmp.charCodeAt(0) == inputField.text.charCodeAt(a))
			{
				matched = true;
				//replaces blank txt with guess text
				guessText.text = guessText.text.substring(0, a - 1) + tmp
					+ guessText.text.substring(a + 1, guessText.text.length);
			}
		}
		//if wrong, then increment guesses and set to next frame
		if (!matched)
			incrementGuess();
		
		
	}
	
	function incrementGuess() : Void
	{
		//refresh screen
		removeChild(frames[guesses]);
		removeChild(debugText);
		removeChild(guessText);
		
		guesses++;
		
		addChild(frames[guesses]);
		addChild(debugText);
		addChild(guessText);
	}
	
	function setupFrames() : Void
	{
		frames = new Array<Bitmap> ();
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame1.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame2.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame3.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame4.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame5.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame6.png")));
		frames.push(new Bitmap(Assets.getBitmapData("assets/frame7.png")));		
		
	}
	
	function swapToGuess() : Void
	{
		removeChild(inputField);
		currentState = guessState;
		for (a in 0...inputField.text.length)
		{
			guess += "-";
		}
		guessText.text = guess;
		addChild(guessText);
		debugText.text = "Guess the word!";
	}
	
	
}