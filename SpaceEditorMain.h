/***************************************************************
 * Name:      SpaceEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ali Sancakli (alisancakli05@gmail.com)
 * Created:   2020-10-08
 * Copyright: Ali Sancakli (github.com/TerabyteForever)
 * License:
 **************************************************************/

#ifndef SPACEEDITORMAIN_H
#define SPACEEDITORMAIN_H


#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/statusbr.h>
#include <wx/file.h>
#include <wx/filedlg.h>

class SpaceEditorFrame: public wxFrame
{
    public:

        SpaceEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SpaceEditorFrame();

    private:


        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRichTextCtrl1Text(wxCommandEvent& event);
        void OnSaveClicked(wxCommandEvent& event);
        void OnSaveAsClicked(wxCommandEvent& event);
        void OnOpenClicked(wxCommandEvent& event);


        static const long ID_RICHTEXTCTRL1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;

        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxRichTextCtrl* RichTextCtrl1;
        wxStatusBar* StatusBar1;
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxFileDialog* FileDialog3;

       unsigned int saveCounter = 0; //I know it doesn't look really good, but I don't know any better way for this. You'll see what is this for in the main code.
        wxString savePath;
        DECLARE_EVENT_TABLE()
};

#endif // SPACEEDITORMAIN_H
