/***************************************************************
 * Name:      SpaceEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ali Sancakli (alisancakli05@gmail.com)
 * Created:   2020-10-08
 * Copyright: Ali Sancakli (github.com/TerabyteForever)
 * License:
 **************************************************************/

#include "SpaceEditorApp.h"

//(*AppHeaders
#include "SpaceEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SpaceEditorApp);

bool SpaceEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SpaceEditorFrame* Frame = new SpaceEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
