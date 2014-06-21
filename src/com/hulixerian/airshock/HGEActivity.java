package com.hulixerian.airshock;
import android.app.Activity;
import android.os.Bundle;
//import android.util.Log;
//import android.view.WindowManager;
//import java.io.File;
import com.hulixerian.hge.OpenGLView;
public class HGEActivity extends Activity
{
    OpenGLView mView;
    @Override protected void onCreate(Bundle icicle)
    {
        super.onCreate(icicle);
        mView = new OpenGLView(getApplication());
        setContentView(mView);
    }
    @Override protected void onPause()
    {
        super.onPause();
        mView.onPause();
    }
    @Override protected void onResume()
    {
        super.onResume();
        mView.onResume();
    }
}