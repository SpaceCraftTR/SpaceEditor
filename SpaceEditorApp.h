/***************************************************************
 * Name:      SpaceEditorApp.h
 * Purpose:   Defines Application Class
 * Author:    Ali Sancakli (alisancakli05@gmail.com)
 * Created:   2020-10-08
 * Copyright: Ali Sancakli (github.com/TerabyteForever)
 * License:
 **************************************************************/

#ifndef SPACEEDITORAPP_H
#define SPACEEDITORAPP_H
#include "SpaceEditorMain.h"
#include <wx/image.h>
#include <wx/app.h>

class SpaceEditorApp : public wxApp
{
    public:
        virtual bool OnInit();
        SpaceEditorFrame* Frame;

};

#endif // SPACEEDITORAPP_H
