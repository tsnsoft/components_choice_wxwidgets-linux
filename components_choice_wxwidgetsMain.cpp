/***************************************************************
 * Name:      components_choice_wxwidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#include "components_choice_wxwidgetsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(components_choice_wxwidgetsFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(components_choice_wxwidgetsFrame)
const long components_choice_wxwidgetsFrame::ID_LISTBOX1 = wxNewId();
const long components_choice_wxwidgetsFrame::ID_STATICTEXT1 = wxNewId();
const long components_choice_wxwidgetsFrame::ID_CHOICE1 = wxNewId();
const long components_choice_wxwidgetsFrame::ID_CHECKBOX1 = wxNewId();
const long components_choice_wxwidgetsFrame::ID_RADIOBOX1 = wxNewId();
const long components_choice_wxwidgetsFrame::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(components_choice_wxwidgetsFrame,wxFrame)
    //(*EventTable(components_choice_wxwidgetsFrame)
    //*)
END_EVENT_TABLE()

components_choice_wxwidgetsFrame::components_choice_wxwidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(components_choice_wxwidgetsFrame)
    Create(parent, id, _("Компоненты выбора"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(384,311));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxPoint(40,72), wxSize(136,152), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    ListBox1->SetSelection( ListBox1->Append(_("C")) );
    ListBox1->Append(_("C++"));
    ListBox1->Append(_("Java"));
    ListBox1->Append(_("C#"));
    ListBox1->Append(_("Python"));
    ListBox1->Append(_("Delphi"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("\?\?\?"), wxPoint(64,232), wxSize(160,21), 0, _T("ID_STATICTEXT1"));
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(40,16), wxSize(136,40), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("C")) );
    Choice1->Append(_("C++"));
    Choice1->Append(_("Java"));
    Choice1->Append(_("C#"));
    Choice1->Append(_("Python"));
    Choice1->Append(_("Delphi"));
    Choice1->Append(_("Новый язык"));
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("C++"), wxPoint(40,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    wxString __wxRadioBoxChoices_1[6] =
    {
    	_("C"),
    	_("C++"),
    	_("Java"),
    	_("C#"),
    	_("Python"),
    	_("Delphi")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Выбери"), wxPoint(224,16), wxSize(136,208), 6, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_RADIOBOX1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Выход"), wxPoint(248,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Center();

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&components_choice_wxwidgetsFrame::OnListBox1Select);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&components_choice_wxwidgetsFrame::OnChoice1Select);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&components_choice_wxwidgetsFrame::OnCheckBox1Click);
    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&components_choice_wxwidgetsFrame::OnRadioBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&components_choice_wxwidgetsFrame::OnQuit);
    //*)
    wxCommandEvent e;
    OnListBox1Select(e);
}

components_choice_wxwidgetsFrame::~components_choice_wxwidgetsFrame()
{
    //(*Destroy(components_choice_wxwidgetsFrame)
    //*)
}

void components_choice_wxwidgetsFrame::OnQuit(wxCommandEvent& event) {
    Close();
}


void components_choice_wxwidgetsFrame::OnListBox1Select(wxCommandEvent& event) {
    int i = ListBox1 -> GetSelection();
    wxString s = ListBox1 -> GetString(i);
    StaticText1 -> SetLabel(s);
}


void components_choice_wxwidgetsFrame::OnChoice1Select(wxCommandEvent& event) {
    int i = Choice1 -> GetSelection();
    wxString s = Choice1 -> GetString(i);
    StaticText1 -> SetLabel(s);
}

void components_choice_wxwidgetsFrame::OnRadioBox1Select(wxCommandEvent& event) {
    int k = RadioBox1 -> GetSelection();
    wxString s = RadioBox1 -> GetString(k);
    StaticText1 -> SetLabel(s);
}

void components_choice_wxwidgetsFrame::OnCheckBox1Click(wxCommandEvent& event) {
    bool b = CheckBox1 -> GetValue();
    if (b == true) {
        StaticText1 -> SetLabel(L"Да!");
    } else {
        StaticText1 -> SetLabel(L"Нет!");
    }
}
