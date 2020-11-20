/***************************************************************
 * Name:      SpaceEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ali Sancakli (alisancakli05@gmail.com)
 * Created:   2020-10-08
 * Copyright: Ali Sancakli (github.com/TerabyteForever)
 * License:
 **************************************************************/

#include "SpaceEditorApp.h"



IMPLEMENT_APP(SpaceEditorApp);

bool SpaceEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {


    	if(wxApp::argc > 1){

        Frame = new SpaceEditorFrame(NULL,wxApp::argv[1],-1);
        Frame->Show();
    	SetTopWindow(Frame);


    	}
    	else{

            Frame = new SpaceEditorFrame(nullptr,-1);
            Frame->Show();
            SetTopWindow(Frame);

    	}
    }
    //*)
    return wxsOK;

}
