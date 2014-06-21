package com.hulixerian.hge;
public class HGELib
{
	static
	{
		System.loadLibrary("hge");
	}
	public static native boolean init();
	public static native boolean resize(int width, int height);
	public static native boolean render();
}
