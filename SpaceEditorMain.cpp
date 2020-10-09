/***************************************************************
 * Name:      SpaceEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ali Sancakli (alisancakli05@gmail.com)
 * Created:   2020-10-08
 * Copyright: Ali Sancakli (github.com/TerabyteForever)
 * License:
 **************************************************************/

#include "SpaceEditorMain.h"
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <wx/textfile.h>
#include <wx/file.h>
#include <fstream>
//(*InternalHeaders(SpaceEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SpaceEditorFrame)
const long SpaceEditorFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long SpaceEditorFrame::ID_MENUITEM1 = wxNewId();
const long SpaceEditorFrame::ID_MENUITEM2 = wxNewId();
const long SpaceEditorFrame::ID_MENUITEM3 = wxNewId();
const long SpaceEditorFrame::idMenuQuit = wxNewId();
const long SpaceEditorFrame::idMenuAbout = wxNewId();
const long SpaceEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SpaceEditorFrame,wxFrame)
    //(*EventTable(SpaceEditorFrame)
    //*)
END_EVENT_TABLE()

SpaceEditorFrame::SpaceEditorFrame(wxWindow* parent,wxWindowID id)
{

    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("SpaceCraft SpaceEditor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    RichTextCtrl1 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL1, wxEmptyString, wxPoint(160,280), wxDefaultSize, wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Save\tCtrl-S"), _("Save current file."), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Save As\tCtrl-Shift-S"), _("Save current file as..."), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Open\tCtrl-O"), _("Open a file."), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    FileDialog1 = new wxFileDialog(this,"Open a file...");
    FileDialog2 = new wxFileDialog(this, _("Save file..."), "", "","", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    FileDialog3 = new wxFileDialog(this, _("Save the file as..."), "", "","", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);


    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpaceEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpaceEditorFrame::OnAbout);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpaceEditorFrame::OnSaveClicked);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpaceEditorFrame::OnSaveAsClicked);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpaceEditorFrame::OnOpenClicked);


}
void SpaceEditorFrame::SaveAFile(wxString& filePath){


        wxFile file;
        file.Create(filePath,true);
        std::ofstream output(filePath); //clear function on textfile also doesn't work :/
        file.Write(RichTextCtrl1->GetValue());



}
void SpaceEditorFrame::OnSaveClicked(wxCommandEvent& event)
{
    saveCounter++;

    if(saveCounter == 1){


        int handler = FileDialog2->ShowModal();
        if(handler == wxID_CANCEL){

        if(saveCounter != 0){

                saveCounter--;

        }


        }

        else if(handler == wxID_OK){



        savePath = FileDialog2->GetPath();
        fileName = FileDialog2->GetFilename();
        SaveAFile(savePath);



        }


    }
    if(saveCounter > 1){


        SaveAFile(savePath);

    }
}
void SpaceEditorFrame::OnSaveAsClicked(wxCommandEvent& event)
{

    int state = FileDialog3->ShowModal();
    wxString address;
    if(state == wxID_OK){
        address = FileDialog3->GetPath();
        SaveAFile(address);


    }


}

void SpaceEditorFrame::OnOpenClicked(wxCommandEvent& event)
{
    saveCounter = 0;
    wxString text;
    int handler = FileDialog1->ShowModal();
    if(handler == wxID_OK){
            SetTitle(FileDialog1->GetFilename() + " - SpaceCraft SpaceEditor");
        wxTextFile editfile;
        editfile.Open(FileDialog1->GetPath());
        for(size_t i = 0; i < editfile.GetLineCount(); i++){


            text<<editfile.GetLine(i)<<"\r\n";


        }

        RichTextCtrl1->SetValue(text);

    }
}

SpaceEditorFrame::~SpaceEditorFrame()
{

}
void SpaceEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SpaceEditorFrame::OnAbout(wxCommandEvent& event)
{
       wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName("SpaceCraft SpaceEditor");
    aboutInfo.SetVersion("Beta 0.2");
    aboutInfo.SetDescription(_("All the content that makes SpaceEditor is written by contributors and it will be open-source forever. Say thanks to all the contributors!"));
    aboutInfo.SetWebSite("http://github.com/SpaceCraftTR");
    wxAboutBox(aboutInfo);
}

