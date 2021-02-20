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


#include <wx/textfile.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/file.h>
#include <wx/filedlg.h>

class SpaceEditorFrame: public wxFrame
{
    public:

        SpaceEditorFrame(wxWindow* parent,wxWindowID id = -1);
        SpaceEditorFrame(wxWindow* parent, wxString arguments, wxWindowID id = -1);
        virtual ~SpaceEditorFrame();


inline void OpenFile(){

    wxString text;
    int handler = FileDialog1->ShowModal();
    if(handler == wxID_OK){
        SetTitle(FileDialog1->GetFilename() + " - SpaceCraft SpaceEditor");
        wxTextFile editfile;
        argv_ = FileDialog1->GetPath();
        editfile.Open(FileDialog1->GetPath());
        for(size_t i = 0; i < editfile.GetLineCount(); i++){

            text<<editfile.GetLine(i)<<"\r\n";

        }
        RichTextCtrl1->SetValue(text);
    }
}
inline void OpenFile(wxString path){
        wxString text;
        SetTitle(path + " - SpaceCraft SpaceEditor");
        wxTextFile editfile;
        argv_ = path;
        editfile.Open(path);
        for(size_t i = 0; i < editfile.GetLineCount(); i++){

            text<<editfile.GetLine(i)<<"\r\n";

        }
        RichTextCtrl1->SetValue(text);
}



    private:


        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRichTextCtrl1Text(wxCommandEvent& event);
        void OnSaveClicked(wxCommandEvent& event);
        void OnSaveAsClicked(wxCommandEvent& event);
        void OnOpenClicked(wxCommandEvent& event);

        /*Save file function*/
        void SaveAFile(wxString &filePath);

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


        wxString savePath;
        wxString fileName;
        wxString argv_;
        DECLARE_EVENT_TABLE()
};

#endif // SPACEEDITORMAIN_H
