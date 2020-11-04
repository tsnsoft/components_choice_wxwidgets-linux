/***************************************************************
 * Name:      components_choice_wxwidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#ifndef COMPONENTS_CHOICE_WXWIDGETSMAIN_H
#define COMPONENTS_CHOICE_WXWIDGETSMAIN_H

//(*Headers(components_choice_wxwidgetsFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
//*)

class components_choice_wxwidgetsFrame: public wxFrame
{
    public:

        components_choice_wxwidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~components_choice_wxwidgetsFrame();

    private:

        //(*Handlers(components_choice_wxwidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(components_choice_wxwidgetsFrame)
        static const long ID_LISTBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_CHECKBOX1;
        static const long ID_RADIOBOX1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(components_choice_wxwidgetsFrame)
        wxButton* Button1;
        wxCheckBox* CheckBox1;
        wxChoice* Choice1;
        wxListBox* ListBox1;
        wxRadioBox* RadioBox1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // COMPONENTS_CHOICE_WXWIDGETSMAIN_H
