package com.soul.gaming;
import nme.display.Bitmap;

/**
 * ...
 * @author Kevin Venables
 */

class GameObject extends Bitmap
{

	public function new() 
	{
		super();
	}
	
	public function update()
	{
		
	}
	
	public var initialized:Bool = false;
	public function init() : Void
	{
		initialized = true;
	}
}