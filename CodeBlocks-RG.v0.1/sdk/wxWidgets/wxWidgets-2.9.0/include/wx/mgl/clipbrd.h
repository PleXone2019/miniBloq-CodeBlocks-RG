/////////////////////////////////////////////////////////////////////////////
// Name:        wx/mgl/clipboard.h
// Purpose:
// Author:      Vaclav Slavik
// Id:          $Id: clipbrd.h 52834 2008-03-26 15:06:00Z FM $
// Copyright:   (c) 2001-2002 SciTech Software, Inc. (www.scitechsoft.com)
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __WX_CLIPBOARD_H__
#define __WX_CLIPBOARD_H__

#if wxUSE_CLIPBOARD

#include "wx/object.h"
#include "wx/list.h"
#include "wx/dataobj.h"
#include "wx/control.h"
#include "wx/module.h"

// ----------------------------------------------------------------------------
// wxClipboard
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxClipboard : public wxClipboardBase
{
public:
    wxClipboard() {}
    virtual ~wxClipboard() {}

    // open the clipboard before SetData() and GetData()
    virtual bool Open() {}

    // close the clipboard after SetData() and GetData()
    virtual void Close() {}

    // query whether the clipboard is opened
    virtual bool IsOpened() const {}

    // set the clipboard data. all other formats will be deleted.
    virtual bool SetData( wxDataObject *data ) {}

    // add to the clipboard data.
    virtual bool AddData( wxDataObject *data ) {}

    // ask if data in correct format is available
    virtual bool IsSupported( const wxDataFormat& format ) {}

    // fill data with data on the clipboard (if available)
    virtual bool GetData( wxDataObject& data ) {}

    // clears wxTheClipboard and the system's clipboard if possible
    virtual void Clear() {}

    // implementation from now on
    bool              m_open;
    bool              m_ownsClipboard;
    bool              m_ownsPrimarySelection;
    wxDataObject     *m_data;

    GtkWidget        *m_clipboardWidget;  /* for getting and offering data */
    GtkWidget        *m_targetsWidget;    /* for getting list of supported formats */
    bool              m_waiting;          /* querying data or formats is asynchronous */

    bool              m_formatSupported;
    GdkAtom           m_targetRequested;
    wxDataObject     *m_receivedData;

private:
    DECLARE_DYNAMIC_CLASS(wxClipboard)
};

#endif
   // wxUSE_CLIPBOARD

#endif
    // __WX_CLIPBOARD_H__
