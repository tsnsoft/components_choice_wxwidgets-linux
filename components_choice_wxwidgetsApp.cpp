/***************************************************************
 * Name:      components_choice_wxwidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#include "components_choice_wxwidgetsApp.h"

//(*AppHeaders
#include "components_choice_wxwidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(components_choice_wxwidgetsApp);

bool components_choice_wxwidgetsApp::OnInit()
{
    wxLocale m_locale;
 	m_locale.Init(wxLANGUAGE_RUSSIAN);
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	components_choice_wxwidgetsFrame* Frame = new components_choice_wxwidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

    return wxsOK;

}
